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

// here M is prime — so Fermat's Little Theorem applies.
// here b and M are coprime (i.e., gcd(b, M) = 1) — otherwise the inverse doesn’t exist.

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

    // For safe handling of negative a or b, you may want to normalize them:

    a = (a % M + M) % M;
    b = (b % M + M) % M;
    
    // Compute b's modular inverse mod M
    long long b_inv = inverse(b, M);

    // Division: a / b mod M = a * b^(-1) mod M
    long long result = (a * b_inv) % M;

    cout << "a / b mod M = " << result << endl;

    return 0;
}




// here M is non prime - Modular Inverse using Extended Euclidean Algorithm (for non-prime M)


#include <bits/stdc++.h>
using namespace std;

// Extended Euclidean Algorithm
long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long g = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse using extended GCD
long long modInverse(long long b, long long M) {
    long long x, y;
    long long g = extendedGCD(b, M, x, y);
    if (g != 1) return -1; // No modular inverse if not coprime
    return (x % M + M) % M; // Make sure it's positive
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, M;
    cin >> a >> b >> M;

    a = (a % M + M) % M;
    b = (b % M + M) % M;

    long long b_inv = modInverse(b, M);
    if (b_inv == -1) {
        cout << "Modular inverse does not exist (b and M are not coprime)\n";
    } else {
        long long result = (a * b_inv) % M;
        cout << "a / b mod M = " << result << '\n';
    }

    return 0;
}



