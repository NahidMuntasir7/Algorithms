// Problem statement

// You are given a sorted array ‘arr’ of length ‘n’, which contains positive integer positions of ‘n’ gas stations on the X-axis.
// You are also given an integer ‘k’.
// You have to place 'k' new gas stations on the X-axis.
// You can place them anywhere on the non-negative side of the X-axis, even on non-integer positions.

// Let 'dist' be the maximum value of the distance between adjacent gas stations after adding 'k' new gas stations.
// Find the minimum value of dist.

// -------- min of (max) ----------

// Example:
// Input: ‘n' = 7 , ‘k’=6, ‘arr’ = {1,2,3,4,5,6,7}.

// Answer: 0.5

// Explanation:
// We can place 6 gas stations at 1.5, 2.5, 3.5, 4.5, 5.5, 6.5. 
// Thus the value of 'dist' will be 0.5. It can be shown that we can't get a lower value of 'dist' by placing 6 gas stations.


#include <bits/stdc++.h>
using namespace std;

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
