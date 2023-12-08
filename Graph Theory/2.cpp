#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int inf = 1e9 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;

    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src; cin >> src;

    vector<int> dist(n, inf);
    dist[src] = 0;

    for(int iter = 0; iter < n - 1; iter++){
        bool change = 0;   // to detect negative cycle 
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u] + w < dist[v]) change = 1;

            dist[v] = min(dist[v], w + dist[u]);  
        }
    }

    // if(change) cout << "Cycle detected" << endl;
    for(auto it : dist){
        cout << it << " ";
    }
    cout << endl;
}