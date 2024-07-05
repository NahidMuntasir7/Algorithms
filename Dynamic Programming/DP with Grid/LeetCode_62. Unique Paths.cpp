// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.


class Solution {
private:
    int helpme(int i, int j, int m, int n, vector<vector<int>> &dp){
        if (i == m - 1 and j == n - 1)   return 1;
        if (i >= m or j >= n)    return 0;
        if (dp[i][j] != -1)   return dp[i][j];
        
        int down = helpme(i + 1, j, m, n, dp);
        int right = helpme(i, j + 1, m, n, dp);
        
        return dp[i][j] =  down + right;
    }
public:
    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return helpme(0, 0, m, n, dp);
    }
};


// another

class Solution {
private:
    int helpme(int i, int j, int m, int n, vector<vector<int>> &dp){
        if (i == m - 1 and j == n - 1)   return 1;
        if (i >= m or j >= n)    return 0;
        if (dp[i][j] != -1)   return dp[i][j];

        int ans = 0;
        
        ans += helpme(i + 1, j, m, n, dp);
        ans += helpme(i, j + 1, m, n, dp);
        
        return dp[i][j] =  ans;
    }
public:
    int uniquePaths(int m, int n){
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, -1));
        return helpme(0, 0, m, n, dp);
    }
};
