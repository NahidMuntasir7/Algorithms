#include<bits/stdc++.h>
using namespace std;
    
int findMaxSumSubsequence(vector<int> const &nums, int i, int n, int prev){
    if (i == n) return 0;
  
    int excl = findMaxSumSubsequence(nums, i + 1, n, prev);
    int incl = 0;
    if (prev + 1 != i) {
        incl = findMaxSumSubsequence(nums, i + 1, n, i) + nums[i];
    }
    return max(incl, excl);
}
int findMaxSumSubsequence_2(vector<int> const &nums, int i, int n){  // without previous // use this
    if (i >= n) return 0; // as i + 2
  
    int excl = findMaxSumSubsequence_2(nums, i + 1, n);
    int incl = findMaxSumSubsequence_2(nums, i + 2, n) + nums[i];
    return max(incl, excl);
}
 
int main(){
    vector<int> nums = { 1, 2, 9, 4, 5, 0, 4, 11, 6 };
    int n = nums.size();
    cout << "The maximum sum is " << findMaxSumSubsequence(nums, 0, n, INT_MIN) << endl;
    cout << "The maximum sum is " << findMaxSumSubsequence_2(nums, 0, n);
}
