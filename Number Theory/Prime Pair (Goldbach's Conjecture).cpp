bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void goldbach(int n) {
    for (int i = 2; i <= n / 2; ++i) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << i << " + " << (n - i) << " = " << n << endl;
            return;
        }
    }
}
