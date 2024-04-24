// Problem statement

// You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
// You are also given an integer ‘k’.
// You have to place 'k' new gas stations on the X-axis.
// You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.
// Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.

// Find the minimum value of dist.

// Example:
// Input: ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}.

// Answer: 0.5

// Explanation:
// We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 
// Thus the value of 'dist' will be 0.5. It can be shown that we can't get a lower value of 'dist' by placing 6 gas stations.
