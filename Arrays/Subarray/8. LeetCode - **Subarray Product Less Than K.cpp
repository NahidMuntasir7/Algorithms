// Given an array of integers nums and an integer k, return 
// the **number of contiguous subarrays** where the product of all the elements in the subarray is strictly less than k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0, prod = 1, cnt = 0;
        int n = nums.size();
        if(k <= 1) return 0;

        while(right < n){
            prod *= nums[right];
            while(prod >= k) prod /= nums[left++];
            cnt += 1 + (right - left);
            right++;
        }  
        return cnt;
    }
};
