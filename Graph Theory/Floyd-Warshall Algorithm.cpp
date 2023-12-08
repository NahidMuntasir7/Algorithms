#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int inf = 1e9 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> graph = { {0, 5, inf, 10},
                                  {inf, 0, 3, inf},
                                  {inf, inf, 0, 1},
                                  {inf, inf, inf, 0}
                                };

    int n = graph.size();
    vector<vector<int>> dist = graph;

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }   
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == inf) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;

        //cout  << dist[1][3]; // individual distance
    }
}
