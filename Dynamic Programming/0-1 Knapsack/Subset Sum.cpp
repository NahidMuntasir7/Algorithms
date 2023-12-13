#include<bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> const &A, int n, int k){
    if (k == 0) {
        return true;
    }
    if (n < 0 || k < 0) {
        return false;
    }
    bool include = subsetSum(A, n - 1, k - A[n]);
    bool exclude = subsetSum(A, n - 1, k);

    return include || exclude;
}
 
// Subset Sum Problem
int main(){

    vector<int> A = { 7, 3, 2, 5, 8 };
    int k = 14; // sum
    int n = A.size();
 
    if (subsetSum(A, n - 1, k)) {
        cout << "Subsequence with the given sum exists";
    }
    else {
        cout << "Subsequence with the given sum does not exist";
    }
}
