// Given an array of integers arr of even length n and an integer k.

// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

// Return true If you can find a way to do that or false otherwise.

// Example 1:

// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).



// We need to pair elements such that their sum is divisible by k. This means for each element with remainder r, there must be a corresponding element with remainder k - r to form a valid pair. 
// Special care must be taken for elements with remainder 0, as they need to pair among themselves.

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderCount(k, 0);
        
        for (int num : arr) {
            int rem = ((num % k) + k) % k; 
            remainderCount[rem]++;
        }
        if (remainderCount[0] % 2 != 0) { // why special care 0? because there will be no mp[k] for mp[0]... all will be mp[0] as n * k % k = 0
            return false;
        }
        
        for (int i = 1; i < k; ++i) { // starts from 1 to k - 1
            if (remainderCount[i] != remainderCount[k - i]) {
                return false; 
            }
        }
        
        return true;
    }
};

