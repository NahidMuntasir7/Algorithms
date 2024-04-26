#include<bits/stdc++.h>
using namespace std;

int findLongestPalindrome(string X, int i, int j){ // i -> start and j -> end 
    if (i > j) return 0;
    if (i == j) return 1; // 1 letter

    if (X[i] == X[j]){
        return findLongestPalindrome(X, i + 1, j - 1) + 2;
    }
    return max(findLongestPalindrome(X, i, j - 1), findLongestPalindrome(X, i + 1, j));
}
 
int main(){
    string X = "ABBDCACB";
    int n = X.length();
 
    cout << "The length of the longest palindromic subsequence is " << findLongestPalindrome(X, 0, n - 1);
}                                                                                       // i -> start and j -> end 
