#include<bits/stdc++.h>
using namespace std;

long long BinExp(long long a, long long b, long long M){
    long long ans = 1LL;
    while(b > 0){
        if(b & 1){
        ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
        return ans;
}


long long inverse(long long a, long long M){
    return BinExp(a, M - 2, M);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, M;
    cin >> a >> b >> M;

    cout << BinExp(a, b, M) <<endl;
    cout << inverse(a, M) << endl; // BinExp(a, M-2, M);

}


