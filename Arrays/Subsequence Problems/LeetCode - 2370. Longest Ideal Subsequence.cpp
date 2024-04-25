class Solution {
public:
    int lis(int i, int prev, const string &s, int k, vector<vector<int>> &dp) {
        if (i == s.size()) return 0;
        
        if (dp[i][prev] != -1) return dp[i][prev];
    
        int incl = 0;
        if (abs(prev - (s[i] - 'a' + 1)) <= k or prev == 0) {
            incl = lis(i + 1, s[i] - 'a' + 1, s, k, dp) + 1;  // s[i] - 'a' + 1 ( + 1 is impp)
        }
        int excl = lis(i + 1, prev, s, k, dp);

        return dp[i][prev] = max(incl, excl);

    }

    int longestIdealString(string s, int k) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(26, -1)); // // 27 because space for 26 alphabets and one more for '0'
        return lis(0, 0, s, k, dp);  
    }
};
