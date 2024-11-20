// Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
// Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
// A subarray is defined as a contiguous block of elements in the array.
// Example 1:
// Input: nums = [3,1,4,2], p = 6
// Output: 1
// Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

(totalsum - (pre[j] - pre[i])) % p = 0
(totalsum - pre[j]) + pre[i])) % p = 0
pre[i] % p = (pre[j] - totalsum) % p

// to avoid negative
pre[i] % p = (pre[j] - totalsum + p) % p


#define ll long long
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        ll total = accumulate(nums.begin(), nums.end(), 0LL);
        int sum = total % p; // due to overflow or for mod 
        if(sum == 0) return 0;

        unordered_map<int,int> mp;
        int presum = 0;
        mp[0] = -1;
        int minlen = n;

        for(int i = 0; i < n; i++){              
            presum = (presum + nums[i]) % p;
            int t = (presum - sum + p) % p;
            if(mp.find(t) != mp.end()) minlen = min(minlen, i - mp[t]);
            mp[presum] = i; 
        }

        return minlen == n ? -1 : minlen;
    }
};
