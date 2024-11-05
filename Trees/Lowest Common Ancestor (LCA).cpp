#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
int parent[N], depth[N];

void dfs(int u, int par, int d) {
    parent[u] = par;
    depth[u] = d;
    for (int v : g[u]) {
        if (v != par) {
            dfs(v, u, d + 1);
        }
    }
}

int lca(int u, int v) {
    while (depth[u] > depth[v]) u = parent[u];
    while (depth[v] > depth[u]) v = parent[v];
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    return u;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1, 0); // Assuming 1 is the root
    int u, v;
    cin >> u >> v; // Nodes for which LCA is to be found
    cout << lca(u, v) << endl;
}
