#include<bits/stdc++.h>
using namespace std;

long long BinMultiply(long long a, long long b, long long M){
    long long ans = 0LL;
    a = a % M;
    while(b > 0){
        if(b & 1){
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
        return ans;
}

long long BinExp(long long a, long long b, long long M){
    long long ans = 1LL;
    a = a % M;
    while(b > 0){
        if(b & 1){
        ans = BinMultiply(ans, a, M);
        }
        a = BinMultiply(a, a, M);
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
    cout << BinMultiply(a, b, M) <<endl;
    cout << BinMultiply(a, inverse(b, M), M) <<endl;

}


