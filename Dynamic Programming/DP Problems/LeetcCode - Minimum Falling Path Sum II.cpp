class Solution {
public:
    int dp[201][201];
    int mini(int i, int j, vector<vector<int>> &grid){

        int n = grid.size();
        if(j >= n) return INT_MAX;
        if(i == n - 1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];;

        int ans = INT_MAX;

        for(int k = 0; k < grid.size(); k++){
            if(k != j) ans = min(ans, mini(i + 1, k, grid) + grid[i][j]);
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));

        int ans = INT_MAX;
        for(int i = 0; i < grid[0].size(); i++){
            ans = min(ans, mini(0, i, grid));
        }
        return ans;
    }
};
