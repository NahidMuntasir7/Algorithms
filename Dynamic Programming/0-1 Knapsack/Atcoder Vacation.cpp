// https://vjudge.net/contest/476645#problem/C
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 7;

int a[N], b[N], c[N], n;
int dp[N][4];

ll solve(int i, int prev){
    if(i == n) return 0;
    if(dp[i][prev] != -1) return dp[i][prev];

    ll ans = INT_MIN;
    if(prev == 0){
        ans = max(ans, b[i] + solve(i + 1, 1));
        ans = max(ans, c[i] + solve(i + 1, 2));
    }
    else if(prev == 1){
        ans = max(ans, a[i] + solve(i + 1, 0));
        ans = max(ans, c[i] + solve(i + 1, 2));
    }
    else if(prev == 2){
        ans = max(ans, a[i] + solve(i + 1, 0));
        ans = max(ans, b[i] + solve(i + 1, 1));
    }
    else{
        ans = max(ans, a[i] + solve(i + 1, 0));
        ans = max(ans, b[i] + solve(i + 1, 1));
        ans = max(ans, c[i] + solve(i + 1, 2));
    }
    return dp[i][prev] = ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> a[i] >> b[i] >> c[i];
    }
    ll ans = solve(0, 3); // 0 1 2 possible
    cout << ans << endl;
}
