// Problem Statement: Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. 
// Replace all ‘O’ with ‘X’ that is surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be 
// surrounded by ‘X’ if there are ‘X’ at locations just below, just above just left, and just right of it.


class Solution{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[]){
        vis[row][col] = 1; 
        int n = mat.size();
        int m = mat[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >= 0 && nrow <n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, mat, delrow, delcol); 
            }
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        vector<vector<int>> vis(n, vector<int> (m, 0)); 
        // traverse first row and last row 
        for(int j = 0; j < m; j++) {
            // check for unvisited Os in the boundary rows
            // first row 
            if(!vis[0][j] && mat[0][j] == 'O') {
                dfs(0, j, vis, mat, delrow, delcol); 
            }
            // last row 
            if(!vis[n - 1][j] && mat[n - 1][j] == 'O') {
                dfs(n-1, j, vis, mat, delrow, delcol); 
            }
        }
        
        for(int i = 0; i < n; i++) {
            // check for unvisited Os in the boundary columns
            // first column 
            if(!vis[i][0] && mat[i][0] == 'O') {
                dfs(i, 0, vis, mat, delrow, delcol); 
            }
            
            // last column
            if(!vis[i][m - 1] && mat[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, mat, delrow, delcol); 
            }
        }
        
        // if unvisited O then convert to X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && mat[i][j] == 'O') 
                    mat[i][j] = 'X'; 
            }
        }
        return mat; 
    }
};


// LeetCode Version: with no extra vis array

class Solution {
public:

    void flooding(vector<vector<char>>& board, int i, int j){
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        
        board[i][j] = 'V'; // gonecase
        for(int k = 0; k < 4; k++){
            int in = i + delrow[k];
            int jn = j + delcol[k];
            if(in >= 0 && jn >= 0 && in < board.size() && jn < board[0].size() && board[in][jn] == 'O'){
                flooding(board, in, jn);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') flooding(board, i, 0);
        }
        for(int i = 0; i < n; i++){
            if(board[i][m - 1] =='O') flooding(board, i, m - 1);
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O') flooding(board, 0, j);
        }
        for(int j = 0; j < m; j++){
            if(board[n - 1][j] == 'O') flooding(board, n - 1, j);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'V') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};
