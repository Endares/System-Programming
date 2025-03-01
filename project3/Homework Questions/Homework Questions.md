# HW3

## Q1

4 Points

### Q1.1

2 Points

Grading comment:

A bit string, 10001111110100011111011, needs to be transmitted at the data link layer. What is the string transmitted across the Link after bit stuffing by the sender? Assume the same start/end flags as the ones used in class. (Hint: Apply 5 consecutive 1s to your frame and append 01111110 to both the start and end of your frame).  Format requirement: Please answer with numbers only, no other characters or spaces allowed.

01111110100011111010100011111001101111110

### Q1.2

2 Points

Grading comment:

A frame is received by the data link layer, which was transmitted using bit stuffing: 01111110111110110001111101101111110. What is the bit string that the link layer passes up the stack to the network layer after bit de-stuffing?  Format requirement: Please answer with numbers only, no other characters or spaces allowed.

11111110001111111

## Q2

4 Points

### Q2.1

2 Points

Grading comment:

Encode the message 10011011 to send. Format requirement: Please answer with numbers only, no other characters or spaces allowed.

011000111011

### Q2.2

2 Points

Grading comment:

What can be said about the correctness of the following received messages (Hint: Check for Hamming Code correctness using parity)? i.111000101011 ii.01110011011

i. error detected. If it's an one-bit error, it's the 9th bit (5th data bit) error and can be corrected by flipping that bit. Otherwise it can't be corrected. ii. error detected. If it's an one-bit error, it's the 11th bit (7th data bit) error and can be corrected by flipping that bit. Otherwise it can't be corrected.

## Q3 CRC Code

4 Points

Grading comment:

Assume the C(x) = x4 + x2 + 1.

### Q3.1

2 Points

Grading comment:

Encode the message 10110 with CRC. Format requirement: Please answer with numbers only, no other characters or spaces allowed.

101101111

### Q3.2

2 Points

Grading comment:

What can be said about the correctness of the following received messages? i.110101110 ii.110101100

i. r'(x) = n'(x) mod c(x) = 10, not zero, incorrect ii. r'(x) = n'(x) mod c(x) = 0, correct according to CRC check

## Q4 Distance Vector Routing

5 Points

Grading comment:

Consider the subnet shown below. Distance vector routing is used, and the following distance vectors have just come in to router C: B: (6, 0, 8, 10, 5, 5); from D: (4, 9, 7, 0, 8, 6); and from E: (7, 7, 4, 8, 0, 5). The measured distances/costs from C to B, D, and E are 5, 5, and 4, respectively. What will C’s new routing table be after this update? Show both the outgoing router to use and the cost. Format requirement: Upload a screenshot of your answer.

![Screenshot_2025-02-08_at_6.03.55_PM.png](images/fa7379ab-2264-4214-ac29-7769bf868466)

##  hw3_t4.jpg[ Download](https://production-gradescope-uploads.s3-us-west-2.amazonaws.com/uploads/text_file/file/766131096/hw3_t4.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAV45MPIOW4ZQMTBAZ%2F20250225%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20250225T172449Z&X-Amz-Expires=10800&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEBEaCXVzLXdlc3QtMiJHMEUCIQCO%2BQZdhnqVlZDR1bTpEtE%2Foy4y1Q%2FJ4thaq%2FeFYSphjQIgai3U49MAVseiFxhj2vDgcBp63rsKqHX8n%2BI7p0hYeY0qugUIShAAGgw0MDU2OTkyNDkwNjkiDKAOJvYKXsm%2FdCPfYCqXBdG35mz7Vz2Xm%2BmCNT4zfw0Unt5mQ0Ro9gX2t34AH0jPQxw4mg83AA3jw2MHtBPwWNuTFHHZeQBhFHtWw5dMLiydCYtSD4dQEUd1yCZcvgmP7RW5ycp9USkSKsP47Do0CerAzHXmSBT0SnLZFeUq0N1gBo8T2Y4%2Fra%2B2uvm1dbK22dCgJROhfZIpM%2FJ%2BIS7goV70ypTF2jJUcUKtpu50JvOPoET3W9cj2A5tx1Rb1kktclZwwIFUKErWjyNB%2Bs2%2F4UZdVmAdBT1bRINfyZgo8PBBwdnOsbULzYs6xRadNU4MfqY%2Byqsqstgz9vXRiSyfvRm%2BsAKTHZP5Q4wp2adw6s3LwLEwZKNkt29BcHJ2n3%2F%2F1Cx9w34PgV92egrqRDTvLSc5VCbR1OpgQc%2Fd5vdereVi%2BipNy5eppjvANPxrqj8%2BXrbC%2BoRtlLwPMNv9BlvZqvDG%2FIvVn92tEES7h9yVGAGRnHm8mX0aqRKn0UOJodXcVmybLXym7YLqz6GGAlQhMAns00FeN%2BlLbMDLMN9CZhIyVN2Lk5xsxgVs09DGzmzAUBrPEmtJdKEMHUpbH9HbewU%2FOn2nNXJOzyNHqykTuLzwz2IjSK8uEagCqMrVHPmmaTW7RBimOW0GrkyFUG5crJLztuHQ8bWMtosTNfSRjNeJ1xO5hiCTb2GQo293MH1RxI7yfLPW3hnzlLIWyzpqfxtwNDKyofynqrOoyehkQLGrMF2CfOXloEjQTilxfTbR8gtLwbLKUB5Ne8Q%2B7pADQuiXQR46lpnANQ%2BOpvP7eGEHNQTfsos%2FGw8ct6ZNI%2FEjfngGuyq1ekbuYCHY2XylhIawHKwj7skryjyVgG1O%2BG%2FoEBF%2F8%2FNlmqCmUey0kd9fp1TRphWujDC04%2Fe9BjqxAUhsE0IbWjaOJ%2B6jQf%2BQcnwF4JHsVtY7gtAEvqJVQBV2eOgekiG%2B0dZyy%2B0tfP0Dm%2FIgZ7Pafz2w3gwo0evrX%2BMjEEXc23rZg%2BiQjy3DnfnC0HArtnNmO6dEHsgwdamnw4uR3HXuwpw11ifj3Bd0Hx4QDiHIE3%2BE34FyY2rJSPLIxUH0%2FLBFCQJ5WGqSkEMVFHSqY37QG1%2BbIi8P8iNMQvJDGJ6xu7X0R8cmxIlFxYvAfw%3D%3D&X-Amz-SignedHeaders=host&X-Amz-Signature=95ceef41bd660bb1968d0f54a62fdcfa0fdcbc2bbe3702291f56938c87ec72d2)

![Submission File](images/hw3_t4.jpg)

## Q5 TCP Sequence Numbers

4 Points

Grading comment:

To get around the problem of sequence numbers wrapping around while old TCP packets still exist, TCP could use 64-bit sequence numbers instead of 32 bits.  However, theoretically, an optical fiber can run at 100 Terabits per second. What maximum packet lifetime would be required to prevent sequence number wrap-around even with 64-bit sequence numbers? Assume that each byte of a packet has its own sequence number (as TCP does). Format requirement: Upload a screenshot of your answer.

##  hw3_t5.jpg[ Download](https://production-gradescope-uploads.s3-us-west-2.amazonaws.com/uploads/text_file/file/766131085/hw3_t5.jpg?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAV45MPIOWRBQMMG2P%2F20250225%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20250225T172446Z&X-Amz-Expires=10800&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEBAaCXVzLXdlc3QtMiJGMEQCIAnkOC2I3aILmm%2B5or0luV2hii9xfB%2FLwCnP3RkJ234JAiASUyH86LlJX%2FpKgHOd0IAQKckUqTyzujsWf0v4yHbS0Sq6BQhJEAAaDDQwNTY5OTI0OTA2OSIMMZxbGbz7ZOB8gWcxKpcFPGMSorR%2BWLtPCGjiK4rBNlI76C%2B5rRK6oLy29rSaFqasQBdQUcoX4CKGiMf5g8mzyuCrxJ8QLqzUyow2RUdLv%2FvZKuOz40Z%2BeuWybBeH53Z5H9onGaaTDsnfqRgOxfftFeWyTrJ3%2B2hu%2B45HHRd%2F87bl%2F0iD7BtO%2Fx1wVpcrS3SgUWXfLbLS56QokEWJYOz2p79nJs27EjE9nek%2Fh6rCUwsdhvh%2FmA7rAg209BJkpVmW4lPDcBDwU3iMShQo1hqQVm5tQEV2AK601xIEUb98sHyFzH1%2FkxLoRBxAt%2BDovnmJnky5MYrbt8NggGOw9uvm0qhsjGefTAXCjZ2s37OQ1%2F8ND5sJLgEMELGP%2BeCUWfcvAmR5hja%2FPInFLHfj%2BK3ylefYuL1AKVZEj4jlvmvdzRlB1zhUWN642JPf%2F587OU17rUie%2Bemz6jY0YzWH3qHVnATxl4j2buHrGFbScu6HbqdeNrTYzc3q2LmR7E17c31Z4cmyjjgWiRZFvqWrj1VG5mFbF%2BdhLGt5bOSPESfN0ix7NoggNkFUSwYTWl4HRrLmYb%2FWxaMLckwW3eWtKDghrS8mBw60Yz9jTkSQH0Zoh72SefFDtHFpP4TUJSLBNESVjZ%2FD%2Bwj8xdnSxaTNVlCQgFuPACdOrwiq3YCJgBwhwmwNfCSebK7d%2FFYy97SFMzrq8vP0I8%2Bo6WlNScOiBibPL1rBvB%2BBzqOAPb0xy5dM9KpsznDnB%2FouQxiaxMJqcx0A2F3OUcwj%2FPkER4IBUzHlatdqsNHeJ0o3VcswpsXzccQjovdK%2FIN6WK9jtBThfI2ExyY5a%2BGAXMK0%2F4cLRE%2BalZ2K%2FJjqs%2BrLabYcz7rwsq%2BxI8r1rjX9%2BenVUkmc60bDn0wvg3HzMIDN970GOrIByfVkb1YhdxELdI9R57Z2%2F4JKMvID5jwFiK%2B4M5FEXKgPrEMetDVNxVZK7xuk7dEEIfZGB%2FT8EMGcRR72Kyc%2F7NicCO3HVnS5wh0pbZkeOsIj5VF6T0oUadtdLxNPkJ3Jssq3HMPSqGbOZq9lLEgMDFNsVZndZHNqZ53Gx6Gw3meEVkYCjV2lMPlHZfjnjmNEmuLqYuEuRXN2xRKh9m%2BT%2F52j9hoIEe9SNqJDHgAsUufixg%3D%3D&X-Amz-SignedHeaders=host&X-Amz-Signature=fccfa59035dc1c7d12ea77839767a48f3d7604a59143f7887e4cd4b2c5dfb668)

![Submission File](images/hw3_t5.jpg)

## Q6 DNS

4 Points

Grading comment:

Using an online whois lookup service like whois.net, look up duke.edu. On what date was the domain registered? When does it expire? What are the DNS servers for this domain? Include a screenshot of your source. Format requirement: Upload a screenshot of your answer.

##  hw3_t6.png[ Download](https://production-gradescope-uploads.s3-us-west-2.amazonaws.com/uploads/text_file/file/766132123/hw3_t6.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAV45MPIOW6WR7DDDL%2F20250225%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20250225T172801Z&X-Amz-Expires=10800&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEBAaCXVzLXdlc3QtMiJIMEYCIQDrz2P8YZKC4KOr8fBa%2Bb3YF42NS4rn%2BIClXr6sJQaHIwIhAMzTYpR0IMMrbaO3D5pOkB4%2Flcm1OHT2Enbl7SRM0Yr4KroFCEkQABoMNDA1Njk5MjQ5MDY5IgwJRbQHy3dLKf0mjUMqlwU9GM1VEi0Ih7IqU%2F6%2BCD0XJhjc3EfuL9VESRdZ3PA%2FOJw%2BNnS%2FbrhAMhQ%2B%2FZ%2BI5kQ%2FKtCSdykEeJogQU7C7G%2FULSGW0vpuS2Gq5rKa0LqvanLGsAPwbjCppZRhqjE%2FPQ9sslrWlAS1WjehldoRgeuQkeli7iDP1edMq2bHXBZ8fjf8NWH9XFGHV7%2BQcLX0ijtN1CNfENBaxRcBL7ZiOcRr1DJGqsEIsJG%2FMn3WcQfkKRQhweNsjftrrqceqLY%2FLiJGKPky3RJ08%2FhZD1TjeYsVJdKGTUnigz9o3WQz%2B29n9GpCakT0GsBW6M6BYQfszVa37YMg5dunEEDG0Q6KtpU0FGtrCa2a5gb3dZVkvMlTY2Fd0NoH7nyjfPkRBUt4AWcp%2FxH%2F6i0RqITQkYHepBDLqaMTQRuN737qpt7Ba%2BOqADLMsoeX0CY2GH3CCvK%2FvrXejBALAR5K7GNGQuHxItoZkgBc1txFKxV05WQXQL0YR2ogKn7nTd8xKidqPP%2BUBmKUVKtDkNqZ58DmCGurWzoIRuriqKQPfRTX8BACGGQUtGQaRwca0ZZO1SdiDIl3J%2FCJb29F9%2BhhRwwz6CpFwOVcA2ETqjTPx8yw36mTS6p67moX%2FoEbG%2F0RtOyR63PkgYOnnIDlcnYjCXQaBLI306LH3hdZtkdYeGguD%2BJ5tV9XTNqbYzb7I9SLP5e6xFrUPD6Trrto5c4PBml4PC5MRd59uGMTIELxDMK7Cy%2BhEOe6JE9xms7VV51qcZh9357MP0QtCSARlWaF81h2tJyGFZ045Tj5f1JOD9mjCLmbxEtrowWfTxI4DRjTKgg%2FjAJYxP5Jq9tLAv76hqrZR%2F0IUxTjrEwadmkmLbljadp2jkOX2Q%2FMw4sRbXcwy8z3vQY6sAGveafLgt5BOkz8TADaW08A9C9XV0D0evWx6eSuio%2B1I9Av6H5iAkpJz4Vva0WzzB14FS8zp%2BZr5Aiwnkte5m2s6dMnJA%2F15KBYR%2BoP78E6OFjvjoyCT0MRXxdYFY4G5335MN55c6rZ9LmdI1sb7uo7VzuKHAkyiTpiHZxB9syLtWkd0vZUKJa%2BjTP0XQqcsHt52D%2FJqmjAxqX4gS5CzNs3oZo8qCuSOXg683Ysntg59A%3D%3D&X-Amz-SignedHeaders=host&X-Amz-Signature=bd6f9deeb8a5fdf090224f69dacbe6881782287efdee6fbad1f0952657233f86)

![Submission File](https://production-gradescope-uploads.s3-us-west-2.amazonaws.com/uploads/text_file/file/766132123/hw3_t6.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=ASIAV45MPIOW6WR7DDDL%2F20250225%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20250225T172801Z&X-Amz-Expires=10800&X-Amz-Security-Token=IQoJb3JpZ2luX2VjEBAaCXVzLXdlc3QtMiJIMEYCIQDrz2P8YZKC4KOr8fBa%2Bb3YF42NS4rn%2BIClXr6sJQaHIwIhAMzTYpR0IMMrbaO3D5pOkB4%2Flcm1OHT2Enbl7SRM0Yr4KroFCEkQABoMNDA1Njk5MjQ5MDY5IgwJRbQHy3dLKf0mjUMqlwU9GM1VEi0Ih7IqU%2F6%2BCD0XJhjc3EfuL9VESRdZ3PA%2FOJw%2BNnS%2FbrhAMhQ%2B%2FZ%2BI5kQ%2FKtCSdykEeJogQU7C7G%2FULSGW0vpuS2Gq5rKa0LqvanLGsAPwbjCppZRhqjE%2FPQ9sslrWlAS1WjehldoRgeuQkeli7iDP1edMq2bHXBZ8fjf8NWH9XFGHV7%2BQcLX0ijtN1CNfENBaxRcBL7ZiOcRr1DJGqsEIsJG%2FMn3WcQfkKRQhweNsjftrrqceqLY%2FLiJGKPky3RJ08%2FhZD1TjeYsVJdKGTUnigz9o3WQz%2B29n9GpCakT0GsBW6M6BYQfszVa37YMg5dunEEDG0Q6KtpU0FGtrCa2a5gb3dZVkvMlTY2Fd0NoH7nyjfPkRBUt4AWcp%2FxH%2F6i0RqITQkYHepBDLqaMTQRuN737qpt7Ba%2BOqADLMsoeX0CY2GH3CCvK%2FvrXejBALAR5K7GNGQuHxItoZkgBc1txFKxV05WQXQL0YR2ogKn7nTd8xKidqPP%2BUBmKUVKtDkNqZ58DmCGurWzoIRuriqKQPfRTX8BACGGQUtGQaRwca0ZZO1SdiDIl3J%2FCJb29F9%2BhhRwwz6CpFwOVcA2ETqjTPx8yw36mTS6p67moX%2FoEbG%2F0RtOyR63PkgYOnnIDlcnYjCXQaBLI306LH3hdZtkdYeGguD%2BJ5tV9XTNqbYzb7I9SLP5e6xFrUPD6Trrto5c4PBml4PC5MRd59uGMTIELxDMK7Cy%2BhEOe6JE9xms7VV51qcZh9357MP0QtCSARlWaF81h2tJyGFZ045Tj5f1JOD9mjCLmbxEtrowWfTxI4DRjTKgg%2FjAJYxP5Jq9tLAv76hqrZR%2F0IUxTjrEwadmkmLbljadp2jkOX2Q%2FMw4sRbXcwy8z3vQY6sAGveafLgt5BOkz8TADaW08A9C9XV0D0evWx6eSuio%2B1I9Av6H5iAkpJz4Vva0WzzB14FS8zp%2BZr5Aiwnkte5m2s6dMnJA%2F15KBYR%2BoP78E6OFjvjoyCT0MRXxdYFY4G5335MN55c6rZ9LmdI1sb7uo7VzuKHAkyiTpiHZxB9syLtWkd0vZUKJa%2BjTP0XQqcsHt52D%2FJqmjAxqX4gS5CzNs3oZo8qCuSOXg683Ysntg59A%3D%3D&X-Amz-SignedHeaders=host&X-Amz-Signature=bd6f9deeb8a5fdf090224f69dacbe6881782287efdee6fbad1f0952657233f86)