// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Print one integer: the minimum number of steps

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int dp[N];
int min_steps(int x) {
    if(x == 0) return 0;
    if(dp[x] != -1) return dp[x];
    
    int ans = INT_MAX;
    int xx = x;
    while(xx > 0) {
        if(xx % 10 != 0) ans = min(ans, 1 + min_steps(x - (xx % 10)));
        xx /= 10;
    }
    return dp[x] = ans;
}
int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << min_steps(n) << '\n';
}
