// Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province 
// if there is a path from u to v or v to u. Your task is to find the number of provinces.


// Matrix to Adj list DFS
class Solution {
public: 
void dfs(int node, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1; 
    for(auto child: adj[node]){
        if(!vis[child]) {
            dfs(child, vis, adj);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected){ 
        int n = isConnected.size();
        vector<int> adj[n]; 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j] == 1){ // self nodes are not considered
                   adj[i].push_back(j); 
                   adj[j].push_back(i);
                }
            }
        } 
        vector<int> vis(n, 0); 

        int count = 0;
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
               count++; 
               dfs(i, vis, adj);
            }
        } 
        return count;
    }
};



// Matrix DFS
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector <bool> &vis) {
        vis[i] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && vis[j] == false) {
                dfs(isConnected, j, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <bool> vis(isConnected.size(), false);
        int ans = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (vis[i] == false) {
                dfs(isConnected, i, vis);
                ans++;
            }
        }
        return ans;
    }
};


// with DSU
class DSU{
private:
    vector<int>Parent, Size;
public :
    DSU(int n){
        Parent.resize(n);
        Size.resize(n);
        for(int i=0;i<n;i++){
            Parent[i]=i;
            Size[i]=1;
        }
    }
    int Find(int x){
        if(x == Parent[x]) return x;
        return Parent[x] = Find(Parent[x]);
    }
    bool Union(int x,int y){
        x = Find(x);
        y = Find(y);
        if(x == y) return false;
        if(Size[x] < Size[y]){
            swap(x, y);
        }
        Parent[y] = x;
        Size[x] += Size[y];
        return true;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        int ans = n;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(isConnected[i][j] && dsu.Find(i) != dsu.Find(j) ){
                    ans -= 1;
                    dsu.Union(i, j);
                }
            }
        }
        return ans;
    }
};
