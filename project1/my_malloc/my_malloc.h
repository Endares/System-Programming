#include <unistd.h>  // for sbrk()
#include <stdio.h>
#include <stdlib.h>

#define META_SIZE sizeof(block_meta)

unsigned long data_segment_size = 0;

typedef struct _block_meta {
  size_t size;
  struct _block_meta *next, *prev;
} block_meta;

// head and tail ptr of free_list
block_meta *head = NULL;
block_meta *tail = NULL;

// for test
void print_free_list() {
  block_meta *curr = head;
  printf("Free list: ");
  while (curr) {
    printf("[%p: size=%zu] -> ", curr, curr->size);
    curr = curr->next;
  }
  printf("NULL\n");
}

// find a sutable free block accoridng to ff strategy
block_meta * find_ff_block(size_t size) {
  block_meta * curr = head;
  while (curr) {
    // a new meta is always needed for allocation
    if (curr->size >= size) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

// allocate the whole free block by deleting it from the free_list
void allocate_block(block_meta *block) {
  // 1. only one block in free list
  if (head == block && tail == block) {
    head = NULL;
    tail = NULL;
  }
  // 2. block is head
  else if (head == block) {
    head = block->next;
    block->next->prev = NULL;
  }
  // 3. block is tail 
  else if (tail == block) {
    tail = block->prev;
    block->prev->next = NULL;
  }
  // 4. block is in the mid part
  else {
    block->next->prev = block->prev;
    block->prev->next = block->next;
  }
    block->prev = NULL;
    block->next = NULL;
}

// split a free block into an allocated block followed by a free block
void split_block(block_meta *block, size_t size) {
  block_meta *new_block = (block_meta *)((char *)block + META_SIZE + size);   // char offset
  new_block->size = block->size - size - META_SIZE;
  
  // 1. only one block in the free list
  if (head == block && tail == block) {
    head = new_block;
    tail = new_block;
    new_block->prev = NULL;
    new_block->next = NULL;
  }
  // 2. block is head
  else if (head == block) {
    if (block->next) block->next->prev = new_block;
    new_block->next = block->next;
    new_block->prev = NULL;
    head = new_block;
  }
  // 3. block is tail 
  else if (tail == block) {
    if (block->prev) block->prev->next = new_block;
    new_block->prev = block->prev;
    new_block->next = NULL;
    tail = new_block;
  }
  // 4. block is in the mid part
  else {
    new_block->prev = block->prev;
    new_block->next = block->next;
    if (block->prev) block->prev->next = new_block;
    if (block->next) block->next->prev = new_block;
  }

  // allocated block
  block->size = size;
  block->prev = NULL;
  block->next = NULL;
}

// allocate space on heap. An allocated block always needs a meta
block_meta *request_space(size_t size) {
  void *requested = sbrk(size + META_SIZE);
  // allocation failure
  if (requested == (void *) -1) {
    fprintf(stderr, "Error: allocation failure");
    exit(EXIT_FAILURE);
  };

  block_meta *block = (block_meta *)requested;
  block->size = size;
  block->next = NULL;
  block->prev = NULL;
    
  data_segment_size += size + META_SIZE;

  return block;
}


// First Fit malloc/free
void *ff_malloc(size_t size) {
  if (size == 0) return NULL;

  block_meta *block = find_ff_block(size);
  if (block == NULL) {   // no adequate free block, expand the heap
    block = request_space(size);
    // if (!block) return NULL; // heap expansion failure
  } else {  // adequate free block founded
    // 1. no need to split
    if (block->size <= size + META_SIZE) {
      allocate_block(block);
    }
    // 2. split the block 
    else {
      split_block(block, size);
    } 
  }
  return (void *)((char*)block + META_SIZE);  // return the actual data's address by skipping block_meta
}

// only need to merge with direct prev and next free blocks
void merge_blocks(block_meta *block) {
  if (!head || !block) return;
 
  if (block->next && (char *)block->next == (char *)block + META_SIZE + block->size) {
    block_meta * next_block = block->next;
    block->size += next_block->size + META_SIZE;
    // renew tail
    if (next_block == tail) {
      tail = block;
    }
    block->next = next_block->next;
    // here block->next might be NULL
    if (next_block->next) {
      next_block->next->prev = block;
    }
    next_block->prev = NULL;
    next_block->next = NULL;
  }
  
  if (block->prev && (char *)block == (char *)(block->prev) + META_SIZE + block->prev->size) {
    block_meta * prev_block = block->prev;
    prev_block->size += block->size + META_SIZE;
    if (block == tail) {
      tail = prev_block;  
    }
    prev_block->next = block->next;
    if (block->next) block->next->prev = prev_block;
    block->prev = NULL;
    block->next = NULL;
  }
}


void ff_free(void *ptr) {
    if (!ptr) return;
    
    block_meta *block = (block_meta*)ptr - 1;   // meta address
    // 1. head = null, empty free list
    if (head == NULL) {
      head = block;
      tail = block;
      block->prev = NULL;
      block->next = NULL;
    }
    // 2. freed block before head, block becomes the new head
    else if (block < head) {
      block->next = head;
      head->prev = block;
      block->prev = NULL;
      head = block;
    } 
    // 3. freed block after tail
    else if (block > tail) {
      block->prev = tail;
      tail->next = block;
      block->next = NULL;
      tail = block;
    }
    // 4. somewhere between head and tail
    else {
      block_meta *curr = head;
      // find two free blocks right before and right after block
      block_meta *front = NULL, *back = NULL;
      while (curr) {
        if (curr < block) front = curr;
        if (curr > block) {
          back = curr;
          break;
        }
        curr = curr->next;
      }
      if (front -> next != back) {
        printf("front -> next != back\n");
      }
      block->prev = front;
      block->next = back;
      front->next = block;
      back->prev = block;
    }
    
    merge_blocks(block);
}


// find a sutable free block accoridng to bf strategy
block_meta * find_bf_block(size_t size) {
  block_meta * curr = head;
  block_meta * res = NULL;
  while (curr) {
    // a new meta is always needed for allocation
    if (curr->size >= size) {
      // find the smallest space bigger equal than size
      if (res == NULL || curr->size < res->size) {
        res = curr;
        // already found the best one
        if (curr->size == size) break;
      }
    }
    curr = curr->next;
  }
  return res;
}

// Best Fit malloc/free
void *bf_malloc(size_t size) {
  if (size == 0) return NULL;

  block_meta *block = find_bf_block(size);
  if (block == NULL) {   // no adequate free block, expand the heap
    block = request_space(size);
    // if (!block) return NULL; // heap expansion failure
  } else {  // adequate free block founded
    // 1. no need to split
    if (block->size <= size + META_SIZE) {
      allocate_block(block);
    }
    // 2. split the block 
    else {
      split_block(block, size);
    } 
  }
  return (void *)(block + 1);  // return the actual data's address by skipping block_meta
  // ptr addition: 1 refers to 1 ptr's size, aka 1 block_meta size.
}

// same as ff_free
void bf_free(void *ptr) {
  ff_free(ptr);
}

// In bytes
// heap size
unsigned long get_data_segment_size() {
  return data_segment_size;
}
unsigned long get_data_segment_free_space_size() {
  unsigned long free_size = 0;
  block_meta *curr = head;

  while (curr) {
    free_size += curr->size + META_SIZE;  // free block's block_meta is included!
    curr = curr->next;
  }

  return free_size;
}
