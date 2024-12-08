// Check if a number is a Mersenne Prime
// Problem: Check if a number of the form (2 ^ n) - 1
// Approach: Check if  (2 ^ n) - 1 is prime using the isPrime function.


bool isMersennePrime(int n) {
    int num = (1 << n) - 1;
    return isPrime(num);
}


// Prime Sum Problem
// Approach: Use the Sieve of Eratosthenes to precompute primes up to n, then sum them.

int sumOfPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int sum = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) sum += i;
    }
    return sum;
}


// Prime Sum Pair

void primeSumPair(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n / 2; ++i) {
        if (isPrime[i] && isPrime[n - i]) {
            cout << i << " " << n - i << endl;
            break;
        }
    }
}

