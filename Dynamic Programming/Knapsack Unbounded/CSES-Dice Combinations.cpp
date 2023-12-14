// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
// For example, if n = 3, there are 4 ways:
// 1+1+1
// 1+2
// 2+1
// 3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e9 + 7;
const int N = 1e6 + 7;
int dp[N];
int count(int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int ways = 0;
    for(int i = 1; i <= 6; i++){
        if(n - i >= 0){   
            ways += count(n - i);
            ways %= M;
        }
    }
    return dp[n] = ways;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    int n; cin >> n;
    cout << count(n) << endl;
}
