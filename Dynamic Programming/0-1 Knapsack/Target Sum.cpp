// https://leetcode.com/problems/target-sum/solutions/3218461/most-easiest-way-c/
// number of ways to make a sum by including and excluding
class Solution {
public:
    int solve(vector<int> &nums, int target, int ans, int index){
        if(index == nums.size() && ans == target) return 1;
        if(nums.size() <= index) return 0;  // index == nums.size() is also ok

        return solve(nums, target, ans + nums[index] , index + 1) + solve(nums, target, ans - nums[index], index + 1); //include and exclude
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0, i = 0;
        return solve(nums, target, ans, i);
    }
};
