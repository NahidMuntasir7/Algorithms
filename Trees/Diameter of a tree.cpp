// tree diameter - the length of the longest path between any two nodes in a tree


// CSES-Tree Diameter
// chatgpt ///////

void dfs(int u, int par) {
    dep[u] = dep[par] + 1; // Set depth based on parent
    vis[u] = true;

    if (dep[u] > mx) {
        mx = dep[u];
        second_node = u;
    }

    for (int v : g[u]) {
        if (v != par && !vis[v]) {
            dfs(v, u); // Pass current node as the parent
        }
    }
}

/////////////////

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
vector<int> g[N];
bool vis[N];
int dist[N];
int mx = INT_MIN, second_node;

void dfs(int u, int d) {
    vis[u] = true;
    dist[u] = d;
    
    if (dist[u] > mx) {
        mx = dist[u];
        second_node = u;
    }
    
    for (int v : g[u]) {
        if (vis[v]) continue;
        dfs(v, d + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int u, v; // Changed from x, y to u, v
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 0); // First DFS to find the farthest node
    mx = -1;
    for(int i = 0; i < N; i++){  // Reset visited array
        vis[i] = false;
    } 
    
    dfs(second_node, 0); // Second DFS from the farthest node
    cout << mx << endl;
}
