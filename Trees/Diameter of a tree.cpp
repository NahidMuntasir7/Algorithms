tree diameter - the length of the longest path between any two nodes in a tree


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
