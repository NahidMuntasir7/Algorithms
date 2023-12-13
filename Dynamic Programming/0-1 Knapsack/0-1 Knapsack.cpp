// 1
#include<bits/stdc++.h>
using namespace std;

const int N = 105;
#define int long long

int n, W, w[N], v[N], dp[N][100005]; //1

int rec(int i, int weight) {
  if (i == n + 1) return 0;
  if (dp[i][weight] != -1) return dp[i][weight]; //2

  int ans = rec(i + 1, weight);
  if (weight + w[i] <= W) ans = max(ans, rec(i + 1, weight + w[i]) + v[i]);
  
  return dp[i][weight] = ans; //3
}

int32_t main() {
  cin >> n >> W;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  memset(dp, -1, sizeof dp); //4

  cout << rec(1, 0) << '\n';
}

// 2
#include<bits/stdc++.h>
using namespace std;
 
int knapsack(int v[], int w[], int n, int W){
    if (W < 0) {
        return INT_MIN;
    }
    if (n < 0 || W == 0) {
        return 0;
    }
    int include = v[n] + knapsack(v, w, n - 1, W - w[n]);
    int exclude = knapsack(v, w, n - 1, W);

    return max(include, exclude);
}
 
int main(){

    int v[] = { 20, 5, 10, 40, 15, 25 };
    int w[] = { 1, 2, 3, 8, 7, 4 };

    int W = 10;
    int n = sizeof(v) / sizeof(v[0]);
 
    cout << "Knapsack value is " << knapsack(v, w, n - 1, W);
}
