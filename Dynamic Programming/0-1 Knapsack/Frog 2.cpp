#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;

int n , k,  arr[N];
int dp[N];
 
int func(int i){
    if(i == 1) return 0;
    if(dp[i] != -1) return dp[i];

    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(i - j >= 1) ans = min(ans, func(i - j) + abs(arr[i] - arr[i - j])); // *if is imppp
    }
    return dp[i] = ans;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    memset(dp, -1, sizeof dp);
 
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << func(n) << endl;
}
