// Consider an n x n grid whose squares may have traps. It is not allowed to move to a square with a trap.
// Your task is to calculate the ** number of paths ** from the upper-left square to the lower-right square. You can only move right or down
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n;
char grid[1001][1001]; 
ll dp[1001][1001];

ll func(int i, int j){
    if (grid[1][1] == '*') return 0;
    if(i == n && j == n) return 1;
    if(i > n || j > n) return 0; 
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = 0;
    if(grid[i][j] != '*'){
        if(grid[i + 1][j] != '*') ans += func(i + 1, j);
        if(grid[i][j + 1] != '*') ans += func(i, j + 1);
    }
    return dp[i][j] = ans % mod;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
        }
    }
    cout << func(1, 1) << endl;
}
