#include<bits/stdc++.h>
using namespace std;

const int N = 105, MX_SUM = 1e5 + 9;
int dp[N][MX_SUM];

bool subsetSum(int a[], int i, int sum){
    if (sum == 0) {
        return true;
    }
    if (i <= 0 || sum < 0) {
        return false;
    }
    if(dp[i][sum] != -1) return dp[i][sum]; 
    bool include = subsetSum(a, i - 1, sum - a[i]);
    bool exclude = subsetSum(a, i - 1, sum);

    return dp[i][sum] = (include || exclude);
}
 
int32_t main() { 
  int n, a[N];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof dp);
  vector<int> ans;
  for (int s = 1; s < MX_SUM; s++) {  // all check
    if (subsetSum(a, n , s)) {
      ans.push_back(s);
    }
  }
  cout << ans.size() << '\n';
  for (auto s: ans) {
    cout << s << ' ';
  }
  cout << '\n';
}
