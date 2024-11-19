#include<bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];

        if (prefixSum == k) { // na dile mp[0] = -1 deya lagto
            res = i + 1;
        }

        else if (mp.find(prefixSum - k) != mp.end()) {
            res = max(res, i - mp[prefixSum - k]);  // length = r - l hobe 5 - 2 = 3 length (3, 4, 5)
        }

        if (mp.find(prefixSum) == mp.end()) { // keeping the first occurence / sum to make it max
            mp[prefixSum] = i;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    cout << lenOfLongSubarr(arr, k) << endl;
    return 0;
}
