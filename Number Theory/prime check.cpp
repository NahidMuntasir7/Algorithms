// normal 

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}


// Miller-Rabin Test

long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

bool millerRabin(long long n, int k) {
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;

    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 3);
        long long x = modExp(a, d, n);

        if (x == 1 || x == n - 1)
            continue;

        bool isComposite = true;
        for (int j = 0; j < r - 1; j++) {
            x = modExp(x, 2, n);
            if (x == n - 1) {
                isComposite = false;
                break;
            }
        }

        if (isComposite) return false;
    }

    return true;
}

int main() {
    srand(time(0));

    long long n;
    int k = 5;

    cout << "Enter a number to test primality: ";
    cin >> n;

    if (millerRabin(n, k)) {
        cout << n << " is probably prime." << endl;
    } else {
        cout << n << " is composite." << endl;
    }

    return 0;
}
