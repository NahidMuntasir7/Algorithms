// string  = 'abc'. the subsequences are a, b, c, ab, ac, bc, abc
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s = "abc";
    int n = s.size();
    set<string> se;

    for(int mask = 0; mask < (1 << n); mask++){
        string ss = "";
        for(int pos = 0; pos < n; pos++){
            if(mask & (1 << pos)) ss += s[pos];
        }
        se.insert(ss);
    }
    for(auto it : se){
        cout << it << endl;
    }
}
