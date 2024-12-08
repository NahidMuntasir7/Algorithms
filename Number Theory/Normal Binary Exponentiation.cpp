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
    cout << inverse(a, M) << endl; // BinExp(a, M-2, M); // a ^ (-1) % m

}

for a ^ 5 and a ^ -5  

ll a5 = power(a, 5, m);
ll inverse_a5 = power(a5, m - 2, m);  // (a ^ 5) ^ -1 % m = a ^ (-5) % m 







// a ^ -5 mod m


#include<bits/stdc++.h>
using namespace std;

long long BinExp(long long a, long long b, long long M) {
    long long ans = 1LL;
    while (b > 0) {
        if (b & 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }
    return ans;
}

long long inverse(long long a, long long M) {
    return BinExp(a, M - 2, M); // Fermat's Little Theorem for modular inverse
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, M;
    cin >> a >> b >> M;

    cout << "a^b % M = " << BinExp(a, b, M) << endl;

    // To find a^(-5) % M
    long long a5 = BinExp(a, 5, M); // a^5 % M
    long long inverse_a5 = inverse(a5, M); // (a^5)^(-1) % M = a^(-5) % M

    cout << "a^(-5) % M = " << inverse_a5 << endl;

    return 0;
}



