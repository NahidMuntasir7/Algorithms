// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.


// ** similar to find subarray with sum = x ** here sum of odd numbers = k

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) nums[i] = 1;
            else nums[i] = 0;
        }

        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            count += mp[sum - k];
            mp[sum]++;
        }
        return count;
    }
};



// by sliding window

class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        int count = 0, ans = 0, start = 0, end = 0;
        int n = nums.size();
        while(end < n){
            if(nums[end] % 2 == 1){
                count++;
            }
            while(count > k){
                if(nums[start] % 2 == 1){
                    count--;
                }
                start++;
            }
            ans += end - start + 1;  // Add all valid subarrays ending at 'end' (all valid that ***ends with end*** and  at most k ta tahkte parbe... 0 is possible)
            end++;
        }
        return ans;
    }

//  The idea is to count the number of subarrays with exactly k odd numbers by finding
// the difference between subarrays with at most k  odd numbers and those with at most k - 1 odd numbers.

    int numberOfSubarrays(vector<int>& nums, int k) {
      return subArray(nums, k) - subArray(nums, k - 1);  //  subArray(nums, k) which counts subarrays with at most k odd numbers.
                                                         //  subArray(nums, k - 1) which counts subarrays with at most k-1 odd numbers.
    }
};



//   LeetCode - Binary Subarrays With Sum: Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

exactly same one............................. so there is a pattern in this type of number of subarray where you can't decide... so do map method or atmost method

**## end - start + 1 => hobe when you can take every subarray ending with end ##**
For each valid end, add end - start + 1



Count Subarrays with Sum Less Than k:
Problem: Count the number of subarrays where the sum of elements is less than k.
Approach: Use sliding window to maintain a valid subarray where the sum is less than k. For each valid position of end, add (end - start + 1) to the result.

Longest Substring with At Most k Distinct Characters:
Problem: Find the length of the longest substring with at most k distinct characters.
Approach: Use a sliding window and a hash map to track character counts. Adjust start until there are at most k distinct characters, and calculate the length of the substring as (end - start + 1).

Subarrays with at Most k Different Integers:
Problem: Count the number of subarrays containing at most k distinct integers.
Approach: Use a sliding window with a hash map to count distinct integers in the current window. For each valid end, add (end - start + 1).

Substrings with At Most k Repeated Characters:
Problem: Count substrings where no character repeats more than k times.
Approach: Use sliding window to track character counts and adjust start until all characters in the window meet the condition.

Maximum Size Subarray with Sum Less Than or Equal to k:
Problem: Find the size of the largest subarray with a sum less than or equal to k.
Approach: Use a sliding window to track the sum of elements in the current window. Adjust start to maintain a valid sum, and calculate the size of the window as (end - start + 1).

Number of Nice Subarrays (Current Problem):
Problem: Find the number of subarrays with exactly k odd numbers.
Approach: Use the "at most" method to count subarrays with ≤ k and ≤ k-1, then subtract to get the count of subarrays with exactly k.

Smallest Subarray with Sum Greater Than k:
Problem: Find the smallest subarray whose sum is greater than k.
Approach: Use sliding window to find valid windows and minimize (end - start + 1).
