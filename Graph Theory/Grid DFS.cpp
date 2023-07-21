#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
const int N = 1000 + 7;
char graph[N][N];
int vis[N][N], n, m;
 
int dx[] = {+0, +0, -1, +1};
int dy[] = {+1, -1, +0, +0};
 
 
void dfs(int x, int y){
    if(x < 1 || y < 1 || x > n || y > m || vis[x][y] || graph[x][y] == '#'){
        return;
    }
 
    vis[x][y] = 1;
 
    for(int i = 0; i < 4; i++){   // direction array
        int xx = x + dx[i], yy = y + dy[i];
        dfs(xx, yy);
    }
 
    /*
    dfs(x + 1, y);
    dfs(x, y + 1);
    dfs(x - 1, y);
    dfs(x, y - 1);
    */
}
 
int main(){
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
 
    cin >> n >> m;
 
    for(int i = 1; i <= n ;i++){
        for(int j = 1; j <= m; j++){
             cin >> graph[i][j];
        }
    }
        
 
    int cnt = 0;
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!vis[i][j] &&  graph[i][j] != '#'){
                    dfs(i, j);
                    cnt++;
            }
        }
    }
 
    cout << cnt << endl;
}
