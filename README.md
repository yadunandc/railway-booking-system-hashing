# Railway Booking System Using Hashing

## Title

Implementation and Comparison of Collision Resolution Techniques in Hashing

## Objective

To implement and compare three collision-resolution techniques for a railway booking system:

1. Linear Probing
2. Quadratic Probing
3. Double Hashing

The booking IDs are inserted into a hash table, searched for existing and non-existing IDs, and the number of probes is recorded.

## Input Data

Booking IDs:

23, 43, 13, 33, 53, 63, 73

Hash table size:

11

Search keys:

23, 73, 93

## Hash Function

Primary hash function:

h(k) = k % 11

For double hashing:

h1(k) = k % 11

h2(k) = 7 - (k % 7)

## Linear Probing

Linear probing checks the next available position sequentially when a collision occurs.

Formula:

h(k,i) = (h(k) + i) % 11

## Quadratic Probing

Quadratic probing uses square offsets to find the next available position.

Formula:

h(k,i) = (h(k) + i²) % 11

## Double Hashing

Double hashing uses a second hash function to determine the step size.

Formula:

h(k,i) = (h1(k) + i × h2(k)) % 11

## Load Factor

Load factor = Number of elements / Table size

= 7 / 11

= 0.636

= 63.6%

A higher load factor generally increases the chance of collisions and therefore increases the number of probes.

## Execution Result

For the given booking IDs, all three techniques produce the same final hash table because each ID has a different initial hash position.

Final table:

| Index | Booking ID |
|------:|------------|
| 0 | 33 |
| 1 | 23 |
| 2 | 13 |
| 3 | EMPTY |
| 4 | EMPTY |
| 5 | EMPTY |
| 6 | EMPTY |
| 7 | 73 |
| 8 | 63 |
| 9 | 53 |
| 10 | 43 |

## Search Results

The selected search keys are 23, 73 and 93.

23: Found in 1 probe.

73: Found in 1 probe.

93: Not found after 1 probe.

The same probe counts are obtained for all three methods because no collision occurs.

## Complexity Analysis

### Linear Probing

Average time complexity: O(1)

Worst-case time complexity: O(n)

Space complexity: O(m)

### Quadratic Probing

Average time complexity: O(1)

Worst-case time complexity: O(n)

Space complexity: O(m)

### Double Hashing

Average time complexity: O(1)

Worst-case time complexity: O(n)

Space complexity: O(m)

## Comparison

Linear probing is simple and easy to implement, but it can suffer from primary clustering.

Quadratic probing reduces primary clustering by using square offsets.

Double hashing uses a second hash function and generally provides better distribution when collisions occur.

For this particular input, however, no collisions occur, so all three methods have identical observed performance.

## Conclusion

The railway booking system was implemented using Linear Probing, Quadratic Probing and Double Hashing.

The load factor is 63.6%. For the given booking IDs and a table size of 11, the initial hash positions are all different. Therefore, no collision occurs and each insertion requires only one probe.

All three techniques produce the same final hash table and the same search performance for this input.

In a situation with more collisions and a higher load factor, the difference between the collision-resolution techniques would become more noticeable. Double hashing generally provides better probe distribution, while linear probing is the simplest to implement.

## Files Included

- main.c
- input.txt
- output.txt
- trace_table.txt
- complexity_analysis.txt
- comparison_table.txt
- README.md
