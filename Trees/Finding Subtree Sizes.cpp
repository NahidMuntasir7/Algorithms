
const int MAXN = 100005;

vector<int> adj[MAXN];  
int subtree_size[MAXN]; 

void dfs(int node, int parent) {
    subtree_size[node] = 1; 

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node); 
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1; 
    dfs(root, -1); 

    for (int i = 1; i <= n; ++i) {
        cout << "Subtree size of node " << i << " is " << subtree_size[i] << endl;   // includes the node so no -1
    }  
}
