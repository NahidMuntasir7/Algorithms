int main() {
    vector<vector<int>> mat; // Declare a 2D vector


    vector<vector<int>> mat2(3, vector<int>(4, 0)); // 3x4 matrix of 0s
  
    mat.push_back({1, 2, 3}); // Add rows
    mat.push_back({4, 5, 6});
    mat.push_back({7, 8, 9});

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " "; // Access elements
        }
        cout << endl;
    }
}
