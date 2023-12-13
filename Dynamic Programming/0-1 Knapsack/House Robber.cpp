https://leetcode.com/problems/house-robber/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int dp[101];

    int solve(vector<int> &nums, int n){
        if(n < 0) return 0;  // no limit on money 
        if(dp[n] != -1) return dp[n];

        return dp[n] = max(solve(nums, n - 2) + nums[n], solve(nums, n - 1)); // no adjacent house
    }

    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();

        return solve(nums, n - 1);
    }
};
