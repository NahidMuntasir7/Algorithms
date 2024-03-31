// TYPE : Number of subarrays having X equal to Y = number of subarrays having different integer equal to k

// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good array is an array where the number of different integers in that array is exactly k.

// ans = nos(different <= k) - nos(different <= k - 1)   | nos = number of subarrays..

class Solution {
public:
    int countSubarraysWithAtMostKDistinct(vector<int>& nums, int k){
        unordered_map<int, int> mp;        
        int i = 0, j = 0, cnt = 0;
        
        while(j < nums.size()){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            cnt += (j - i + 1);
            j++;
        }
        return cnt;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countSubarraysWithAtMostKDistinct(nums, k) - countSubarraysWithAtMostKDistinct(nums, k - 1);
    }
};
