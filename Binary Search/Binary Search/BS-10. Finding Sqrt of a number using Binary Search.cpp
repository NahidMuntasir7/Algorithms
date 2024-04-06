// alternative: in-built sqrt() function: int ans = sqrt(n);

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n;     // binary search on the answers

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            low = mid + 1;  // eliminate the left half
        }
        else {
            high = mid - 1; // eliminate the right half
        }
    }
    return high;
}
