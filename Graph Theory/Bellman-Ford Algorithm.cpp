#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int inf = 1e8;
    
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
    // n - 1 iteartions
    for(int iter = 0; iter < n - 1; iter++){
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            if(dist[u] != 1e8 and dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }
    // n th iteration 
    int change = 0;   
    for(auto e : edges){
        int u = e[0];
        int v = e[1];
        int w = e[2];
        if(dist[u] != 1e8 and dist[u] + w < dist[v]){
            change = 1;
        } 
    }

    // if(change) cout << "Cycle detected" << endl;
    for(auto it : dist){
        cout << it << " ";
    }
    cout << endl;
}
