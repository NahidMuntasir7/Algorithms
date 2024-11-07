// 1
#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[], int i, int n, int prev){
    if (i == n) {
        return 0;
    }
    
    int incl = 0;
    if (arr[i] > prev) { // LDS (arr[i] < prev)
        incl = 1 + LIS(arr, i + 1, n, arr[i]);
    }
    
    int excl = LIS(arr, i + 1, n, prev);
    return max(incl, excl);
}
int main(){
    int arr[] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << "The length of the LIS is " << LIS(arr, 0, n, INT_MIN); // LDS INT_MAX
}


// gpt one
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    
    int n = nums.size();
    vector<int> dp(n, 1);  // dp[i] will store the length of the longest increasing subsequence ending at index i
    
    // Build the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {  // If nums[i] is greater than nums[j], update dp[i]
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());  // The longest LIS is the maximum value in dp array
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << lengthOfLIS(nums) << endl;
    return 0;
}




// 2
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int a[N], dp[N];

int32_t main() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = 1;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';
}
