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

// iterative
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        string a = to_string(i);
        for(char c : a){
            int digit = c - '0';
            if(digit != 0){
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
