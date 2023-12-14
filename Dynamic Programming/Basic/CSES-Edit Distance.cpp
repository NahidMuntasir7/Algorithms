// The edit distance between two strings is the minimum number of operations required to transform one string into the other.
// The allowed operations are:
// 1. Add one character to the string.
// 2. Remove one character from the string.      LOVE <-> MOVIE
// 3. Replace one character in the string.
// For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
// Your task is to calculate the edit distance between two strings.

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
int dp[5001][5001];
 int solve(int i, int j, string &s1, string &s2){
    if(i == s1.length() || j == s2.length()){
        return max(s1.length() - i, s2.length() - j);
    }
    if(dp[i][j] != -1) return dp[i][j];
    int ans;
    if(s1[i] == s2[j]){
        ans = solve(i + 1, j + 1, s1, s2);
    }
    else{
        int op1 = 1 + solve(i, j + 1, s1, s2); //add
        int op2 = 1 + solve(i + 1, j, s1, s2); //remove
        int op3 = 1 + solve(i + 1, j + 1, s1, s2); //replace
 
        ans = min({op1, op2, op3});
    }
    return dp[i][j] = ans;
}
int main() {
    memset(dp, -1, sizeof dp);
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(0, 0, s1, s2);
}
