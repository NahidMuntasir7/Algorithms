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

// iterative
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int MOD = 1e9 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    // state
    // dp[i] = number of ways to make a sum of i
    
    // base case
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(j <= i){
                // transition
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }
    
    //final subproblem
    cout << dp[n] << endl;
}

//iterative space-optimized
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int main(){
    int n;
    cin >> n;
 
    vector<int> prev = {1}; // only contains dp[0]
    
    for(int i = 1; i <= n; i++){
        // finding dp[i] or number of ways to make a sum of i
        // dp[i] = summation of all the previous states
        int current = 0;
        for(int j : prev){
            current = (current + j) % MOD;
        }
        prev.push_back(current);
        // if previous contains more than 6 elements
        // discard the first element
        if(prev.size() > 6){
            prev.erase(prev.begin());
        } 
    }
    //finally the last element of prev would be dp[n]
    cout << prev.back() << endl;
    return 0;
}
