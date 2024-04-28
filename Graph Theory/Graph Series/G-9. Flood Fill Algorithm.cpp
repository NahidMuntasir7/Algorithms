// Problem Statement: An image is represented by a 2-D array of integers, each integer representing the pixel value of the image. Given a coordinate (sr, sc) 
// representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same colour as the starting pixel, 
// plus any pixels connected 4-directionally to those pixels (also with the same colour as the starting pixel), and so on. 
// Replace the colour of all of the aforementioned pixels with the newColor.

// both without using extra ans matrix **

// DFS

class Solution {
public:
      void dfs(int row, int col, int color, int initColor, vector<vector<int>>& image, int delRow[], int delCol[]){
    
        int n = image.size();
        int m = image[0].size();

        image[row][col] = color;
        for(int i = 0; i < 4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == initColor && image[nRow][nCol] != color){
                dfs(nRow, nCol, color, initColor, image, delRow, delCol);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int initColor = image[sr][sc];
        int delRow[] = {-1, +1, 0, 0};
        int delCol[] = {0, 0, 1, -1};
        dfs(sr, sc, color, initColor, image, delRow, delCol);
        
        return image;
    }
};

// BFS

class Solution {
public:

    void bfs(int row, int col, vector<vector<int>>& image, int startColor, int newColor){
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});

        image[row][col] = newColor;

        int delRow[4] = {-1, 1, 0, 0};
        int delCol[4] = {0, 0, -1, 1};

        while(!q.empty()){
            int currRow = q.front().first;
            int currCol = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int newRow = currRow + delRow[i];
                int newCol = currCol + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] == startColor && image[newRow][newCol] != newColor){
                    image[newRow][newCol] = newColor;
                    q.push({newRow, newCol});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int startColor = image[sr][sc];
        bfs(sr, sc, image, startColor, color);

        return image;
    }
};
