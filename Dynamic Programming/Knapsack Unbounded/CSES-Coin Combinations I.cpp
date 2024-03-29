// just like Dice Combination with an array
// if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
// 2+2+5
// 2+5+2    // Order does not matter
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int mod = 1e9 + 7;
const int N = 1e6 + 7;
int n, x; 
int arr[107];
int dp[N];
ll func(int sum){
    if(sum == 0) return 1;
    if(sum < 0) return 0; // VVVimp   // kono ans nao thakte pare 
    if(dp[sum] != -1) return dp[sum]; // for loop e if use na korle
    ll ans = 0;
    for(int i = 0; i < n; i++){
       ans += func(sum - arr[i]); // without if
    }
    return dp[sum] = ans % mod;
}
// ll func(int sum){  //JUST LIKE DICE COMBINATION
//     if(sum == 0) return 1;
//     if(dp[sum] != -1) return dp[sum];
//     ll ans = 0;
//     for(int i = 0; i < n; i++){
//         if(sum - arr[i] >= 0){       // if condition use korle
//             ans += func(sum - arr[i]);
//         }
//     }
//     return dp[sum] = ans % mod;
// }
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << func(x) << endl;    
}



// iterative
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
 
int main(){
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    vector<int> dp(x + 1, 0); 

    dp[0] = 1; // base
    
    // dp[x] -> dp[x - ci]
    for(int i = 1; i <= x; i++){ // O(x)
        // find dp[x]
        for(int j = 0; j < n; j++){ // O(n)
            if(a[j] <= i){
                // transition
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }
    //final subproblem
    cout << dp[x] << endl;
    return 0;
}

