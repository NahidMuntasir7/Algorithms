// Problem Statement: 
// Niche NEXT: // LeetCode - Shortest Path in Binary Matrix

// Given an n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. 
// The path can only be created out of a cell if its value is 1. 
// If the path is not possible between the source cell and the destination cell, then return -1.
// Note: You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. 
// In other words, you can move in one of four directions, Up, Down, Left, and Right.


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
        // Edge Case: if the source is only the destination.
        if (source.first == destination.first && source.second == destination.second) return 0;

        // Create a queue for storing cells with their distances from source
        // in the form {dist,{cell coordinates pair}}.
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the source cell as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the maze by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Through this loop, we check the 4 direction adjacent nodes
            // for a shorter path to destination.
            for (int i = 0; i < 4; i++){
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Checking the validity of the cell and updating if dist is shorter.
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]){
                    dist[newr][newc] = 1 + dis;

                    // Return the distance until the point when
                    // we encounter the destination cell.
                    if (newr == destination.first && newc == destination.second) return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};

int main(){
    // Driver Code.

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    Solution obj;

    int res = obj.shortestPath(grid, source, destination);

    cout << res;
    cout << endl;

    return 0;
}






// LeetCode - Shortest Path in Binary Matrix
// can visit only 0 and diagonal possible
// normal BFS

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        if(grid[0][0]==0){
        q.push({{0,0},1});
        visited[0][0] = 1;


        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            if(r == n - 1 and c == m - 1){
                return steps;
            }
            
            q.pop();
            int dx[] = {-1,-1,-1,0,1,1,1,0};
            int dy[] = {-1,0,1,1,1,0,-1,-1};

            for(int i = 0; i < 8; i++){
                int newr = r + dx[i];
                int newc = c + dy[i];

                if(newr >= 0 and newr < n and newc >= 0 and newc < m and grid[newr][newc] == 0 and visited[newr][newc] == 0){
                    q.push({{newr,newc}, steps + 1});
                    visited[newr][newc] = 1;
                }
            } 
        }
        }
        return -1;

    }
};
