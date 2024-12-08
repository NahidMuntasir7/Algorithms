for negative numbers:
a mod m = ((a % m) + m) % m

Addition/Subtraction: For subtraction of numbers under modulo:
(a - b) mod m = ((a mod m) - (b mod m) + m) mod m // (both + and -)
(a + b) mod m = ((a mod m) + (b mod m)) mod m

Multiplication:
(a * b) mod m = ((a mod m) * (b mod m)) mod m

Division:
a / b mod m = (a * b^(-1)) mod m




// division a / b mod m

// Division: a / b mod M = a * b^(-1) mod M  ;)

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

long long inverse(long long b, long long M) {
    return BinExp(b, M - 2, M); // Fermat's Little Theorem for modular inverse
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, M;
    cin >> a >> b >> M;

    // Compute b's modular inverse mod M
    long long b_inv = inverse(b, M);

    // Division: a / b mod M = a * b^(-1) mod M
    long long result = (a * b_inv) % M;

    cout << "a / b mod M = " << result << endl;

    return 0;
}



