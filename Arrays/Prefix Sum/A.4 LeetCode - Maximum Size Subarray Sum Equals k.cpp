#include<bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(vector<int>& arr, int k) {
    
    unordered_map<int, int> mp;
    int len = INT_MIN, sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];

        if (sum == k) { // na dile mp[0] = -1 deya lagto
            len = i + 1;
        }

        else if (mp.find(sum - k) != mp.end()) {
            len = max(len, i - mp[sum - k]);  // length = r - l hobe 5 - 2 = 3 length (3, 4, 5)
        }

        if (mp.find(sum) == mp.end()) { // keeping the first occurence / sum to make it max
            mp[sum] = i;
        }
    }

    return len;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << lenOfLongSubarr(arr, k) << endl;
    return 0;
}
