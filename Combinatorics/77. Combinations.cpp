// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.


class Solution {
public:
    int n, k;
    vector<int>path, nums;
    vector<vector<int>> ans;

    void backtrack(int start){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = start; i < n; i++){
            path.push_back(nums[i]);
            backtrack(i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int num, int kk){
        n = num, k = kk; 
        for(int i = 1; i <= n; i++) nums.push_back(i);

        backtrack(0);
        return ans;
    }
};
