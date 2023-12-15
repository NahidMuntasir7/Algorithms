#include<bits/stdc++.h>
using namespace std;
    
bool subsetSum(vector<int> const &S, int n, int a, int b, int c){
    if (a == 0 && b == 0 && c == 0) {
        return true;
    }
    if (n < 0) {
        return false;
    }
    // Case 1. The current item becomes part of the first subset
    bool A = false;
    if (a - S[n] >= 0) {
        A = subsetSum(S, n - 1, a - S[n], b, c);
    }
    // Case 2. The current item becomes part of the second subset
    bool B = false;
    if (!A && (b - S[n] >= 0)) {
        B = subsetSum(S, n - 1, a, b - S[n], c);
    }
    // Case 2. The current item becomes part of the third subset
    bool C = false;
    if ((!A && !B) && (c - S[n] >= 0)) {
        C = subsetSum(S, n - 1, a, b, c - S[n]);
    }

    return A || B || C;
}
 
bool partition(vector<int> const &S){
    int n = S.size();
    if (n < 3) {
        return false;
    }
    int sum = accumulate(S.begin(), S.end(), 0);
    return !(sum % 3) && subsetSum(S, n - 1, sum / 3, sum / 3, sum / 3);
}
 
int main(){
    vector<int> S = { 7, 3, 2, 1, 5, 4, 8 };

    if (partition(S)) cout << "Set can be partitioned";
    else cout << "Set cannot be partitioned";
}
