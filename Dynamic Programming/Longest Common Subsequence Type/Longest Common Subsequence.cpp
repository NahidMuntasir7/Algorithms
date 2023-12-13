#include<bits/stdc++.h>
using namespace std;

int LCSLength(string X, string Y, int m, int n){
    if (m == 0 || n == 0) {
        return 0;
    }
    if (X[m - 1] == Y[n - 1]) {
        return LCSLength(X, Y, m - 1, n - 1) + 1;
    }
    return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}
 
int main(){
    string X = "ABCBDAB", Y = "BDCABA";
    cout << "The length of the LCS is " << LCSLength(X, Y, X.length(), Y.length());
}
