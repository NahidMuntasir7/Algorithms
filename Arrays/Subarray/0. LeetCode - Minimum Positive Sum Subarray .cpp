// You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.
// Return the minimum sum of such a subarray. If no such subarray exists, return -1.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [3, -2, 1, 4], l = 2, r = 3
// Output: 1

// Explanation:
// The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
// [3, -2] with a sum of 1
// [1, 4] with a sum of 5
// [3, -2, 1] with a sum of 2
// [-2, 1, 4] with a sum of 3
// Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.


class Solution {
public:
    int helper(vector<int>&arr,int k){
        int i = 0, n = arr.size(), j = 0;
        int sum = INT_MAX;
        int ans = 0;
        while(j < n){
            ans += arr[j];
            if(j - i + 1 == k){
                if(ans > 0) sum = min(sum, ans);
                ans -= arr[i];
                i++;
            }
            j++;
        }
        return sum;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;

        for(int i = l; i <= r; i++){
            ans = min(ans, helper(nums, i));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
