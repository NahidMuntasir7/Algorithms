// leetcode - Combination sum

class Solution{
  public:
    void findCombination(int i, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
      if(i == arr.size()){
        if(target == 0){
          ans.push_back(ds);
        }
        return;
      }
      if(arr[i] <= target){ // to prevent negative value
        ds.push_back(arr[i]); // 1
        findCombination(i, target - arr[i], arr, ans, ds); // not i + 1 karon taking it again and again.......
        ds.pop_back(); // 2
      }
      findCombination(i + 1, target, arr, ans, ds);
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target){
      vector<vector<int>> ans;
      vector<int> ds;
      findCombination(0, target, candidates, ans, ds);
      return ans;
    }
};

//Given a set[] of non-negative integers and a value sum, the task is to print the subset of the given set whose sum is equal to the given sum.

#include <bits/stdc++.h>
using namespace std;

// Print all subsets if there is atleast one subset of set[]
// with sum equal to given sum
bool flag = 0;
void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int>& subset){
	// targetSum is zero then there exist a
	// subset.
	if (targetSum == 0) {

		// Prints valid subset
		flag = 1;
		cout << "[ ";
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << "]";
		return;
	}

	if (i == n) {
		// return if we have reached at the end of the array
		return;
	}

	// Not considering current element
	PrintSubsetSum(i + 1, n, set, targetSum, subset);

	// consider current element if it is less than or equal
	// to targetSum
	if (set[i] <= targetSum) {

		// push the current element in subset
		subset.push_back(set[i]);

		// Recursive call for consider current element
		PrintSubsetSum(i + 1, n, set, targetSum - set[i],
					subset);

		// pop-back element after recursive call to restore
		// subsets original configuration
		subset.pop_back();
	}
}

// Driver code
int main(){
	// Test case 1
	int set[] = { 1, 2, 1 };
	int sum = 3;
	int n = sizeof(set) / sizeof(set[0]);
	vector<int> subset;
	cout << "Output 1:" << endl;
	PrintSubsetSum(0, n, set, sum, subset);
	cout << endl;
	flag = 0;
	// Test case 2
	int set2[] = { 3, 34, 4, 12, 5, 2 };
	int sum2 = 30;
	int n2 = sizeof(set) / sizeof(set[0]);
	vector<int> subset2;
	cout << "Output 2:" << endl;
	PrintSubsetSum(0, n2, set2, sum2, subset2);
	if (!flag) {
		cout << "There is no such subset";
	}

	return 0;
}
