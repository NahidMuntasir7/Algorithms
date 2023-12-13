#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
 
int n , arr[N];
int dp[N];
 
int func(int i){
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
 
    int ans = INT_MAX;
  
    ans = min(ans, func(i - 1) + abs(arr[i] - arr[i - 1]));
    if(i > 1) ans = min(ans, func(i - 2) + abs(arr[i] - arr[i - 2]));
 
    return dp[i] = ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    memset(dp, -1, sizeof dp);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << func(n - 1) << endl;
}
