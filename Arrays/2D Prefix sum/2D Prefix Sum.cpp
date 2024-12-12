#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c; 
    cin >> r >> c;
    int arr[r + 1][c + 1], pre[r + 1][c + 1] = {0};

    // Input the 2D array
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cin >> arr[i][j];
        }
    }

    // Calculate 2D prefix sum
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            pre[i][j] = arr[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    // Query the sum of a submatrix (l1, l2) to (r1, r2)
    int l1, l2, r1, r2;
    cin >> l1 >> l2 >> r1 >> r2;

    // Submatrix sum using prefix sum formula
    ll result = pre[r1][r2] - pre[l1 - 1][r2] - pre[r1][l2 - 1] + pre[l1 - 1][l2 - 1];
    cout << result << endl;

    return 0;
}

