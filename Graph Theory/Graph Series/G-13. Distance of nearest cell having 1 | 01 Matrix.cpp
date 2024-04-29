// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, 
// and i2, j2 are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.


// Grid BFS

class Solution {
    public:
    // Function to find the distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> grid){
	    int n = grid.size(); 
	    int m = grid[0].size(); 
	    
	    vector<vector<int>> vis(n, vector<int>(m, 0));  // visited and distance matrix
	    vector<vector<int>> dist(n, vector<int>(m, 0)); 
	   
	    queue<pair<pair<int,int>, int>> q;  // <coordinates, steps>
	    // traverse the matrix
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(grid[i][j] == 1) {  // start BFS if cell contains 1
	                q.push({{i,j}, 0}); 
	                vis[i][j] = 1; 
	            }
	            else {
	                vis[i][j] = 0; // mark unvisited 
	            }
	        }
	    }
	    
	    int delrow[] = {-1, 0, +1, 0}; 
	    int delcol[] = {0, +1, 0, -1}; 
	    
	    // traverse till queue becomes empty
	    while(!q.empty()) {
	        int row = q.front().first.first; 
	        int col = q.front().first.second; 
	        int steps = q.front().second; 
	        q.pop(); 
	        dist[row][col] = steps; 
	        // for all 4 neighbours
	        for(int i = 0; i < 4; i++) {
	            int nrow = row + delrow[i]; 
	            int ncol = col + delcol[i]; 
	            // check for valid unvisited cell
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
	                vis[nrow][ncol] = 1; 
	                q.push({{nrow, ncol}, steps + 1});  
	            }
	        }
	    }
	    // return distance matrix
	    return dist; 
	}
};
