// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// Count the number of subarrays sum equal to X

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


// *** Approach 2 ***

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return SUMARRAY(nums, goal) - SUMARRAY(nums, goal - 1);  // (sum <= goal) - (sum <= goal - 1)
    }
    
    int SUMARRAY(vector<int>& nums, int goal) {
        if (goal < 0) return 0;

        int count = 0, i = 0, j = 0, sum = 0;
        while (i < nums.size()) {
            sum += nums[i]; 
            while (sum > goal) {
                sum -= nums[j];
                j++;
            }
            count += i - j + 1;
            i++;
        }
        return count;
    }
};


