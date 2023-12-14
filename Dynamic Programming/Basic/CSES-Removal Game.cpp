// There is a list of n numbers and two players who move alternately. On each move, a player removes either the first or last number from the list, and their score increases by that number. 
// Both players try to maximize their scores.
// What is the maximum possible score for the *first player* when both players play optimally?

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

int n, a[5001];
ll dp[5001][5001][2];
ll func(int i, int j, int turn){
    if(i > j) return 0;
    if(dp[i][j][turn] != -1) return dp[i][j][turn]; 
    ll ans;
    if(turn == 1){
        ans = max(func(i + 1, j, 0) + a[i], func(i, j - 1, 0) + a[j]); // 1st
    }
    else {
        ans = min(func(i + 1, j, 1), func(i, j - 1, 1)); // 2nd
    }
    return dp[i][j][turn] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    ll x = func(1, n, 1); // first
    cout << x  << endl;
}
