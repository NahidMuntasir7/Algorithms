// Like Coin Combinations I but order matters // ** Distinct Ordered Ways **
// ** TLE VERSION **
// if the coins are {2,3,5} and the desired sum is 9, there are 3 ways:
// 2+2+5
// 3+3+3
// 2+2+2+3
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e6 + 7;
int n, x; 
int arr[107];
int dp[107][N];
ll func(int i, int total){
    if(i == n + 1) return 0;
    if(total < 0) return 0; // function call er age if use kori nai...
    if(total == 0) return 1;
    if(dp[i][total] != -1) return dp[i][total];
    ll ans = 0;
    ans += func(i, total - arr[i]); // knapsack approach
    ans += func(i + 1, total);
    return dp[i][total] = ans % mod;
}
int main(){
    ios_base::sync_with_stdio(0); u
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> x;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    cout << func(1, x) << endl;
}

// **Accepted Versions**

// knapsack iterative
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1));
    // dp[i][k] = number of ways to construct sum k
    // such that all coins before coin[i] are unusable
    
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    
    for(int i = n - 1; i >= 0; i--){
        for(int sum = 1; sum <= x; sum++){
            int skipping = dp[i + 1][sum];
            int picking = 0;
            if(a[i] <= sum){
                picking = dp[i][sum - a[i]];
            }
            dp[i][sum] = (skipping + picking) % MOD;
        }
    }
    cout << dp[0][x] << endl;
    return 0;
}

// approach 2
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[1000001];
const int MOD = (int)1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) { 
        cin >> coins[i]; 
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int weight = 0; weight <= x; weight++) {
            if (weight - coins[i - 1] >= 0) {  // prevent out of bounds cases
                dp[weight] += dp[weight - coins[i - 1]];
                dp[weight] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}
