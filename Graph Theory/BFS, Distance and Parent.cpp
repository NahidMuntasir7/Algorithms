#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N]; int dis[N], par[N];

int32_t main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  queue<int> q;
  q.push(1); 
  vis[1] = true; 
  dis[1] = 0;

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      if (!vis[v]) {
        q.push(v);
        par[v] = u;
        dis[v] = dis[u] + 1;
        vis[v] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << '\n';

  int v = 4;
  while (v != 1) {
    cout << v << ' ';
    v = par[v];
  }
  cout << 1 << '\n';
}





// #include<bits/stdc++.h>
// using namespace std;

// #define ll long long
// const int N = 1e5;

// vector<int> g[N];
// int vis[N];
// int level[N];

// void bfs(int source){
//     queue<int> q;
//     q.push(source);
//     vis[source] = 1;
   
//     while(!q.empty()){
//         int cur_v = q.front();
//         q.pop();
//         cout << cur_v << " ";
//         for(int child : g[cur_v]){
//             if(!vis[child]){
//                 q.push(child);
//                 vis[child] = 1;
//                 level[child] = level[cur_v] + 1;
//             }
//         }
//     }
//     cout << endl;
// }
// int32_t main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int v, e;
//   cin >> v >> e;

//   while(e--){
//       int x, y;
//       cin >> x >> y;

//       g[x].push_back(y);
//       g[y].push_back(x);
// }

//   bfs(1);

//   for(int i = 1; i <= v; i++){
//       cout << i << ":" << level[i] << endl;
//   }
// }
