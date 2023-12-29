#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
int dep[N];
int mx, node, ans;

void dfs1(int u, int p) {
  dep[u] = dep[p] + 1;
  if (dep[u] > mx) {
    mx = dep[u];
    node = u;
  }
  for (auto v: g[u]) {
    if (v != p) {
      dfs1(v, u);
    }
  }
}

void dfs2(int u, int p) {
  dep[u] = dep[p] + 1;
  ans = max(ans, dep[u] - 1);
  for (auto v: g[u]) {
    if (v != p) {
      dfs2(v, u);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs1(1, 0);
  dfs2(node, 0);
  
  cout << ans << '\n';
  return 0;
}


// CSES-Tree Diameter
#include<bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10 ;
 
vector<int> g[N];
bool vis[N];
int dist[N];
int mx = INT_MIN, second_node;

void dfs(int vertex, int d){
     vis[vertex] = true;
     dist[vertex] = d;
    
    if(dist[vertex] > mx){
        mx = dist[vertex];
        second_node = vertex;
    }
    for(int child : g[vertex]){
        if(vis[child]) continue;
        dfs(child, dist[vertex] + 1);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    mx = -1;
    for(int i = 0; i < N; i++){
        vis[i] = false;
    }
    dfs(second_node, 0);
    cout << mx << endl;
 }

