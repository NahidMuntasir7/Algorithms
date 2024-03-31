// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// Count subarray sum equal to X

// Approach 1
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        long long sum = 0, cnt = 0;
 
        unordered_map<long long, int> seen;
        seen[0]++;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            cnt += seen[sum - goal];  // l <- x -> r so, r - l = x or, l = r - x.  current r er jonno suitable l ache kina check..
            seen[sum]++;
        }
        return cnt;      
    }
};


// Approach 2



