// directed graph given. find the length of longest directed path. the length of a directed path is the number of edges in it.
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
vector<int> graph[N];
int dp[N];
int rec(int u){
    if(dp[u] != -1) return dp[u];
    int ans = 0;
    for(auto v : graph[u]){
        ans = max(ans, rec(v) + 1);
    }
    return dp[u] = ans;
}
    
int main(){    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, rec(i));
    }
    cout << ans << endl;
}
