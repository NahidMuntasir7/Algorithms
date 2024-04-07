// Problem Statement: A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, 
// which denotes the time (in hours) for all the bananas to be eaten.
// Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. If the pile contains less than ‘k’ bananas, then 
// the monkey consumes all the bananas and won’t eat any more bananas in that hour. 

// Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.

// Example 1:
// Input Format:
//  N = 4, a[] = {7, 15, 6, 3}, h = 8
// Result:
// 5
// (eats ------> this way)

#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {   // find the maximum
    int maxi = INT_MIN;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly) {   // find total hours
    int totalH = 0;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(v[i]) / (double)(hourly));
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    int low = 1, high = findMax(v);

    //apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low; //
}

int main(){
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}
