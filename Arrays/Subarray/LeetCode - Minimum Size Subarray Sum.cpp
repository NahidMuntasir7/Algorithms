// Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray
//  whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX, sum = 0, start = 0, end = 0, n = nums.size();
        while(start < n){
            sum += nums[start];
            while(sum >= target){
                len = min(len, start - end + 1); // must be here
                sum -= nums[end];
                end++;
            }
            start++;
        } 
        if(len == INT_MAX) return 0;
        else return len;
    }
};
