// You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
// You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
// Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.

// Example :
// Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2
// Output: 3


#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    for (int i = 0; i < n; i++) {  // count the number of bouquets
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}
int roseGarden(vector<int> arr, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    int n = arr.size(); // size of the array
    if (val > n) return -1; // impossible case.
    
    int mini = INT_MAX, maxi = INT_MIN;  // find maximum and minimum
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
  
    int low = mini, high = maxi;  // apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k)) {
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low; // low will be pointing last valid high
}

int main(){
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1) cout << "We cannot make m bouquets.\n";
    else cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}
