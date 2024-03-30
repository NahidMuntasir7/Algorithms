// given a array of cards.. you can pick k cards .. serially from leftmost to right and / or rightmost to left
// let k == 4
// [(4, 3), 6, 4, 7, 2, (1, 7)] or [(4, 3, 6, 4), 7, 2, 1, 7] or [4, 3, 6, 4, (7, 2, 1, 7)] or [(4, 3, 6), 4, 7, 2, 1, (7)] .... like this
// what is the maxx sum?

// make a left sum of first k elements and make a right sum of 0.. then sub from left and add to right
// 7 3
// 7 2 3 1 1 4 5
// ans = 16; (7) 2 3 1 1 (4 5)
  

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n; cin >> k;
  int arr[n];

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  
  int lsum = 0;
  for(int i = 0; i < k; i++){
      lsum += arr[i];
  }

  int mx = lsum, right = n - 1, rsum = 0;

  for(int i = k - 1; i >= 0; i--){  
      lsum -= arr[i];
      rsum += arr[right--];
      mx = max(mx, lsum + rsum);  // substracting from lsum (right to left) and adding to rsum (right to left)
  }

  cout << mx;

}
