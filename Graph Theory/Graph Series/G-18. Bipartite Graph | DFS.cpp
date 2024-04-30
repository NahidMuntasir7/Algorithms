class Solution {
private: 
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    for(int i = 0;i < V; i++) color[i] = -1; 
	    
	    // for connected components
	    for(int i = 0; i < V; i++) {
	        if(color[i] == -1) {
	            if(dfs(i, 0, color, adj) == false) 
	                return false; 
	        }
	    }
	    return true; 
	}
};



// another
#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 9;

vector<int> g[N];
bool vis[N]; int col[N];
bool ok;

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      col[v] = col[u] ^ 1;
      dfs(v);
    }
    else {
      if (col[u] == col[v]) {
        ok = false;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  ok = true;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  
  if (ok) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}
