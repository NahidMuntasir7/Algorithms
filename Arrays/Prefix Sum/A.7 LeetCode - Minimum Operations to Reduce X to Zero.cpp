// You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
// Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.

// This question ask for removal from left or right, that means , all other leftover element would be a **subarray**.
// We have to minimum operation if leftover element subarray would be as large as possiible.


// Lets see with an example to understand better.
// [1,1,4,2,3], x = 5
// total sum of element is 10 , and we need to reduce x to 0, so that means leftover subarray sum would be total - x
// So try to find a largest subarray where this holds true and if not return -1

So. Find out the largest subarray with sum total - x..... (A.4 one)


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;
        int target = total - x;
        
        if (target == 0) return nums.size();  // ** Special case: sum of all elements equals x **
        
        unordered_map<int, int> mp;
        int len = INT_MIN, sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == target) len = i + 1; // na dile mp[0] = -1 deya lagto
            else if (mp.find(sum - target) != mp.end()) {
                len = max(len, i - mp[sum - target]);
            }
            if (mp.find(sum) == mp.end()) mp[sum] = i;
        }
        
        return len == INT_MIN ? -1 : nums.size() - len;
    }
};



  



