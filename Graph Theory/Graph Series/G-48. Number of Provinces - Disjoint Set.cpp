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
