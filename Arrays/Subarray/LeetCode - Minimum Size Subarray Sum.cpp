class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX, sum = 0, start = 0, end = 0, n = nums.size();
        while(start < n){
            sum += nums[start];
            while(sum >= target){
                len = min(len, start - end + 1);
                sum -= nums[end];
                end++;
            }
            start++;
        } 
        if(len == INT_MAX) return 0;
        else return len;
    }
};
