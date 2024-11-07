// 1
#include<bits/stdc++.h>
using namespace std;

int LCSLength(string X, string Y, int m, int n){
    if (m == 0 || n == 0) {
        return 0;
    }
    if (X[m - 1] == Y[n - 1]) {
        return LCSLength(X, Y, m - 1, n - 1) + 1;
    }
    return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}
 
int main(){
    string X = "ABCBDAB", Y = "BDCABA";
    cout << "The length of the LCS is " << LCSLength(X, Y, X.length(), Y.length());
}


// gpt


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    
    // DP table to store lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill the DP table iteratively
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;  // If characters match
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // If characters don't match
            }
        }
    }
    
    return dp[m][n];  // The result is in dp[m][n]
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    
    cout << "Length of Longest Common Subsequence: " << lcs(s1, s2) << endl;
    return 0;
}


// 2
#include<bits/stdc++.h>
using namespace std;

const int N = 3030;
string a, b;
int dp[N][N];

int lcs(int i, int j) {
  if (i >= a.size() or j >= b.size()) return 0;
  if (dp[i][j] != -1) return dp[i][j];

  int ans = lcs(i + 1, j);
  ans = max(ans, lcs(i, j + 1));

  if (a[i] == b[j]) {
    ans = max(ans, lcs(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;
}

void print(int i, int j) {
  if (i >= a.size() or j >= b.size()) return;

  if (a[i] == b[j]) {
    cout << a[i];
    print(i + 1, j + 1);
    return;
  }
  
  int x = lcs(i + 1, j);
  int y = lcs(i, j + 1);
  if (x >= y) {
    print(i + 1, j);
  }
  else {
    print(i, j + 1);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b;
  memset(dp, -1, sizeof dp);
  cout << lcs(0, 0) << '\n';
  print(0, 0);
}
