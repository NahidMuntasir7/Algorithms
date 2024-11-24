// easy**

// You are given an integer array nums and three integers k, op1, and op2.

// You can perform the following operations on nums:

// Operation 1: Choose an index i and divide nums[i] by 2, rounding up to the nearest whole number. You can perform this operation at most op1 times, and not more than once per index.
// Operation 2: Choose an index i and subtract k from nums[i], but only if nums[i] is greater than or equal to k. You can perform this operation at most op2 times, and not more than once per index.
// Note: Both operations can be applied to the same index, but at most once each.

// Return the minimum possible sum of all elements in nums after performing any number of operations.

// Example 1:
// Input: nums = [2,8,3,19,3], k = 3, op1 = 1, op2 = 1
// Output: 23

class Solution {
public:
    int dp[101][101][101];

    int solve(vector<int> &nums, int i, int k, int op1, int op2){
        if(i >= nums.size()) return 0;
        if(dp[i][op1][op2] != -1) return dp[i][op1][op2];

        // not pick -----------------------------
        int ans = solve(nums, i + 1, k, op1, op2) + nums[i];

        // pick ---------------------------------
        if(op1 > 0) ans = min(ans, solve(nums, i + 1, k, op1 - 1, op2) + ((nums[i] + 1) / 2)); // div with ceil
        if(op2 > 0 and nums[i] >= k) ans = min(ans, solve(nums, i + 1, k, op1, op2 - 1) + (nums[i] - k)); // minus

        // first div then minus
        if(op1 > 0 and op2 > 0){
            int dividedValue = (nums[i] + 1) / 2;
            if(dividedValue >= k){
                ans = min(ans, solve(nums, i + 1, k, op1 - 1, op2 - 1) + (dividedValue - k));
            }
        }
        // first minus then div
        if(op1 > 0 and op2 > 0 and nums[i] >= k){
            int subValue = nums[i] - k;
            ans = min(ans, solve(nums, i + 1, k, op1 - 1, op2 - 1) + ((subValue + 1) / 2)); // div with ceil
        }

        return dp[i][op1][op2] = ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp, -1, sizeof dp);

        return solve(nums, 0, k, op1, op2);
    }
};
