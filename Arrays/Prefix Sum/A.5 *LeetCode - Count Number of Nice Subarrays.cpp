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
            ans += end - start + 1;  // Add all valid subarrays ending at 'end' (all valid as at most k ta tahkte parbe... 0 is possible)
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




