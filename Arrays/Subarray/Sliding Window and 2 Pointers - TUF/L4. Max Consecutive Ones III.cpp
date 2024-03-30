// LeetCode

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// *** can be tured into -> find the longest subarray with atmost k zeros....

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int left = 0, ans = 0;
        for(int right = 0; right < nums.size(); right++){
                mp[nums[right]]++;
                while(mp[0] > k){
                    mp[nums[left]]--;
                    left++;
                }
                ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

// or 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, cnt = 0, ans = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                cnt++;
            }
            // when cnt becomes more than k we reduce our window 
            while( cnt > k){
                if(nums[j] == 0){
                    cnt--;
                }
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans; 
    }
};

