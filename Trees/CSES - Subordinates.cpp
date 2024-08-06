// Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e7 + 7;
 
vector<int> tree[N];
 
void dfs(int vertex, int par, vector<int> &ans){
 
   int subords = 0;
   for(int child : tree[vertex]){
       if(child == par) continue;
       dfs(child, vertex, ans);
       subords += (1 + ans[child]);
   }
    ans[vertex] = subords;
} 
 
int main(){
 
   int n; cin >> n;
 
   vector<int> ans(n + 1);  // size na dile wrong dibe...
 
   for(int i = 2; i <= n; i++){
      int x;
      cin >> x;
      tree[x].push_back(i);
      tree[i].push_back(x);
   }
 
   dfs(1, 0, ans);
 
   for(int i = 1; i <= n; i++){
      cout << ans[i] << " ";
   }
}


// ChatGPT

const int MAXN = 100005; 

vector<int> adj[MAXN];  
int subordinate_count[MAXN]; 

void dfs(int node, int parent) {
    subordinate_count[node] = 0; 

    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node); 
            subordinate_count[node] += 1 + subordinate_count[neighbor]; 
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
        cout << "Subordinate count of node " << i << " is " << subordinate_count[i] << endl;
    }
}
