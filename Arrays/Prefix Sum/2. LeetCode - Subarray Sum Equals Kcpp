// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;

        seen[0] = 1; 

        int sum = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            count += seen[sum - k]; // l = r - x
            seen[sum]++;
        }
        
        return count;

    }
};

 
