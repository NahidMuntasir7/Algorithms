//  Primes in a Range [L, R]
void segmentedSieve(int L, int R) {
    int limit = sqrt(R) + 1;
    vector<int> primes = sieve(limit);
    vector<bool> isPrime(R - L + 1, true);
    for (int prime : primes) {
        int start = max(prime * prime, (L + prime - 1) / prime * prime);
        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            cout << (L + i) << " ";
        }
    }
}


// Count Primes in a Range [L, R]

int countPrimesInRange(int L, int R) {
    int limit = sqrt(R) + 1;
    vector<int> primes = sieve(limit);
    vector<bool> isPrime(R - L + 1, true);
    for (int prime : primes) {
        int start = max(prime * prime, (L + prime - 1) / prime * prime);
        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }
    int count = 0;
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) count++;
    }
    return count;
}


// another

#include<bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes to find primes up to sqrt(R)
vector<int> sieve(int limit) {
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i * i <= limit; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Segmented sieve to find primes in the range [L, R]
void segmentedSieve(int L, int R) {
    // Step 1: Find all primes up to sqrt(R)
    int limit = sqrt(R) + 1;
    vector<int> primes = sieve(limit);

    // Step 2: Create a boolean array to mark primes in range [L, R]
    vector<bool> isPrime(R - L + 1, true);

    // Step 3: Mark non-prime numbers in the range [L, R]
    for (int prime : primes) {
        // Find the first number in the range [L, R] that is a multiple of prime
        int start = max(prime * prime, (L + prime - 1) / prime * prime); // max to handle case when prime^2 is greater than L
        
        // Mark all multiples of 'prime' as non-prime
        for (int j = start; j <= R; j += prime) {
            isPrime[j - L] = false;
        }
    }

    // Step 4: Output all primes in the range [L, R]
    if (L == 1) isPrime[0] = false; // 1 is not prime
    
    for (int i = 0; i <= R - L; ++i) {
        if (isPrime[i]) {
            cout << (L + i) << " ";
        }
    }
    cout << endl;
}

int main() {
    int L, R;
    cin >> L >> R;

    segmentedSieve(L, R);

    return 0;
}

