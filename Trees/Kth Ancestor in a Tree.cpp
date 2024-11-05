#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> g[N];
int parent[N];

void dfs(int u, int par) {
    parent[u] = par;
    for (int v : g[u]) {
        if (v != par) {
            dfs(v, u);
        }
    }
}

int kthAncestor(int node, int k) {
    while (k > 0 && node != -1) {
        node = parent[node];
        k--;
    }
    return node;
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
    dfs(1, -1); // Assuming 1 is the root
    int node, k;
    cin >> node >> k; // Node and Kth ancestor to find
    cout << kthAncestor(node, k) << endl;
}
