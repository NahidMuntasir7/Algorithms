#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int inf = 1e7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;

    vector<int> dist(n + 1, inf);
    vector<vector<pair<int, int>>> graph(n + 1);

    for(int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w}); //undirected
    }

    int source; cin >> source;

    dist[source] = 0;

    set<pair<int, int>> s;
    s.insert({0, source});   // dis, source

    while(!s.empty()){
        auto x = *(s.begin());  
        s.erase(x);

        for(auto it : graph[x.second]){
            if(dist[x.second] + it.second < dist[it.first]){ //amar distance + neigh. edge er weight < neigh. er distanse
                s.erase({dist[it.first], it.first});         //done
                dist[it.first] = dist[x.second] + it.second; // neigh. update
                s.insert({dist[it.first], it.first});        // neigh. insert
            }
        } 
    }

    for(int i = 1; i <= n; i++){
        if(dist[i] < inf) cout << dist[i] << " "; 
        else cout << -1 << " "; // never accessed from source at all
    }
}




// #include<bits/stdc++.h>
// using namespace std;

// const int N = 1e5 + 10;
// const int INF = 1e9 + 10;

// vector<pair<int,int>> g[N];

// void dijkastra(int source){
//     vector<int>vis(N,0);
//     vector<int>dist(N,INF);

//     set<pair<int,int>>st;

//     st.insert({0,source});
//     dist[source] =  0;

//     while(st.size() > 0){
//         auto node = *st.begin();
//         int v_dist = node.first;
//         int v = node.second;
//         st.erase(st.begin());
//         if(vis[v]) continue; 
//         vis[v] = 1;
//         for(auto child : g[v]){
//             int child_v = child.first;
//             int wt = child.second;
//             if(dist[v] + wt < dist[child_v]){
//                 dist[child_v] = dist[v] + wt;
//                  st.insert({dist[child_v],child_v}); 
//             }
//         }
//     }


// }


// int32_t main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n, m;
//     cin >> n >> m;
//     while(m--){
//         int x, y, wt;
//         cin >> x >> y >> wt;
//         g[x].push_back({y,wt});
//     }
// }
