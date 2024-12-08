Check if a number is a Mersenne Prime
Problem: Check if a number of the form (2 ^ n) - 1
Approach: Check if  (2 ^ n) - 1 is prime using the isPrime function.


bool isMersennePrime(int n) {
    int num = (1 << n) - 1;
    return isPrime(num);
}
