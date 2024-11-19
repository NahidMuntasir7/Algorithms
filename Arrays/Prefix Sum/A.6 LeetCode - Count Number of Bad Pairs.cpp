You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
Return the total number of bad pairs in nums.


Total pairs would be n * (n - 1) / 2
And remove those pairs which dont satisfy the rule i - nums[i] == j - nums[j] ....


// solve 

class Solution {
public:
        
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans = (n * (n - 1)) / 2;

        unordered_map<int, long long> m;
        
        for(int i = 0; i < n ; i++){
            int diff = i - nums[i]; // checking if there is a previos one that is able to make pair
            ans -= m[diff]; // if there minus them
            m[diff]++; // new one count e add
        }
        return ans;
    }
};
  
 
