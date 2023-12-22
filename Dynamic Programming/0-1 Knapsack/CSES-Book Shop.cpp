#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> val(n);
    vector<int> weight(n);
    
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0)); // inner vectors are initialized with 0 to x + 1 size
                                                          // base case also declared here ^ dp[0][anything] = 0
    for(int i = 1; i <= n; i++){                          // row -> n , column -> x
        for(int j = x; j >= 0; j--){
            // compute dp[i][j] here
            int w = weight[i - 1];
            int value = val[i - 1];
            // two choices
            //  - pick up ith element
            //  - skip ith element
            int pick = (j >= w ? dp[i - 1][j - w] + value : 0);
            int skip = dp[i - 1][j];
            // transition
            dp[i][j] = max(skip, pick); 
        }
    }
    // final subproblem
    cout << dp[n][x] << endl;
    return 0;
}
