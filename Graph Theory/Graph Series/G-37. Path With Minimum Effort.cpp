// Problem Statement:

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
// where heights[row][col] represents the height of the cell (row, col). You are situated in the top-left cell, (0, 0), 
// and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e.,0-indexed). You can move up, down, left, or right, 
// and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.



#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int MinimumEffort(vector<vector<int>> &heights){

        // Create a priority queue containing pairs of cells 
        // and their respective distance from the source cell in the 
        // form {diff, {row of cell, col of cell}}.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        // Create a distance matrix with initially all the cells marked as
        // unvisited and the dist for source cell (0,0) as 0.
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        // The following delta rows and delts columns array are created such that
        // each index represents each adjacent node that a cell may have 
        // in a direction.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // Iterate through the matrix by popping the elements out of the queue
        // and pushing whenever a shorter distance to a cell is found.
        while (!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Check if we have reached the destination cell,
            // return the current value of difference (which will be min).
            if (row == n - 1 && col == m - 1) return diff;
           
            for (int i = 0; i < 4; i++){
                // row - 1, col
                // row, col + 1
                // row - 1, col
                // row, col - 1
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Checking validity of the cell.
                if (newr >= 0 && newc >= 0 && newr < n && newc < m){
                    // Effort can be calculated as the max value of differences 
                    // between the heights of the node and its adjacent nodes.
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);

                    // If the calculated effort is less than the prev value
                    // we update as we need the min effort.
                    if (newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0; // if unreachable
    }
};

int main(){
    // Driver Code.

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution obj;

    int ans = obj.MinimumEffort(heights);

    cout << ans;
    cout << endl;

    return 0;
}
