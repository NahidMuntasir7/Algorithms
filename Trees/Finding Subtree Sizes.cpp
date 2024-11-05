#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int sub[100005];

void dfs(int u, int p) {
    sub[u] = 1; // Include the node itself
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u);
            sub[u] += sub[v]; // Sum sizes of all subtrees
        }
    }
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
    dfs(1, -1); // Start DFS from node 1
    for (int i = 1; i <= n; i++) {
        cout << sub[i] << " ";
    }
    return 0;
}
