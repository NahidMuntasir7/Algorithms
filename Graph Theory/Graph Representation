#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0);


  int n, m; cin >> n >> m;

  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (auto v: g[2]) { 
    cout << v << '\n';
  }

  // degrees
  for (int i = 1; i <= n; i++) {
    cout << g[i].size() << ' ';
  }
  
  cout << '\n';
  return 0;
}
