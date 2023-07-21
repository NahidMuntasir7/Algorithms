#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 107;
vector<int> graph[N];
int vis[N];
ll dis1[N], dis2[N];
queue<int> q;

void bfs1(){
  while(!q.empty()){
    int u = q.front();
    vis[u] = 1;
    q.pop();
    for(auto v : graph[u]){
       if(!vis[v]){
         vis[v] = 1;
         q.push(v);
         dis1[v] = dis1[u] + 1;
      }
    }
  }
}
void bfs2(){
  while(!q.empty()){
    int u = q.front();
    vis[u] = 1;
    q.pop();
    for(auto v : graph[u]){
       if(!vis[v]){
         vis[v] = 1;
         q.push(v);
         dis2[v] = dis2[u] + 1;
      }
    }
  }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t, cs = 0 ; 
    cin >> t;

    while(t--){
      cout << "Case " << ++cs << ": ";

      memset(dis1, 0, sizeof(dis1));
      memset(dis2, 0, sizeof(dis2));
      memset(vis, 0, sizeof(vis));

      int n; cin >> n;
      int r; cin >> r;
      int s, d;
      for(int i = 0; i < r; i++){
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
      }
      
      cin >> s >> d;
      q.push(s);
      bfs1();
      memset(vis, 0, sizeof(vis));
      q.push(d);
      bfs2();
      
      ll mx = 0;
      for(int i = 0; i < n; i++){
        mx = max(mx, dis1[i] + dis2[i]);
      }
      
      cout << mx << endl;

      for(int i = 0; i < n; i++){ 
        graph[i].clear();
      }
  }
}
