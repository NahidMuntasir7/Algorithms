// Given an array nums of distinct integers, return all the possible permutations
// You can return the answer in any order.

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


class Solution {
public:
    vector<int> path; 
    vector<vector<int>> ans; 
    vector<bool> taken; 
    int n;

    void backtrack(vector<int>& nums) {
        if (path.size() == n) {
            ans.push_back(path); 
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!taken[i]) {
                taken[i] = true;
                path.push_back(nums[i]); 
                backtrack(nums); 
                path.pop_back(); 
                taken[i] = false; 
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        taken.resize(n, false); 
        backtrack(nums);
        return ans; 
    }
};
