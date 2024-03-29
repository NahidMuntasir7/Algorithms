// Leetcode - Permutations
#include<bits/stdc++.h>
using namespace std;    

class Solution {
  private:
    void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {        // (extra sapce) for frequency array
        if (!freq[i]){   // not marked
          ds.push_back(nums[i]); // picking
          freq[i] = 1; // marked
          recurPermute(ds, nums, ans, freq); //going for next element
          freq[i] = 0; // backtracking er time e last taken unmarked
          ds.pop_back(); // and removed
        }
      }
    }
  public:
    vector<vector<int>> permute(vector<int> &nums) {
      vector<vector<int>> ans;
      vector<int> ds;
      int freq[nums.size()];
      for (int i = 0; i < nums.size(); i++) freq[i] = 0;
      recurPermute(ds, nums, ans, freq);
      return ans;
    }
};

int main() {
  Solution obj;
  vector<int> v {1, 2, 3};
  vector<vector<int>> sum = obj.permute(v);
  cout << "All Permutations are " << endl;
  for (int i = 0; i < sum.size(); i++) {
    for (int j = 0; j < sum[i].size(); j++)
      cout << sum[i][j] << " ";
    cout << endl;
  }
}
