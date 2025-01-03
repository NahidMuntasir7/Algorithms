// Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

// 3 possibility
// 1. -1 5 4 5 6 7 -4 -1 total array
// 2. -1 5 (4 5 6) 7 -4 -1 middle part = kadane
// 3. -1 5) 4 5 6 7 (-4 -1  this part = total - *minimum* middle sum

// max of these three



class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi1 = INT_MIN, sum1 = 0, totalsum = 0;

         for(int i = 0; i < nums.size(); i++){
            totalsum += nums[i];

            sum1 = sum1 + nums[i];   
            maxi1 = max(maxi1, sum1);  
            if(sum1 < 0) sum1 = 0;
        }  

        int maxofmini = INT_MIN, sum2 = 0;
 
         for(int i = 0; i < nums.size(); i++){
            sum2 = sum2 + nums[i] * (-1);   
            maxofmini = max(maxofmini, sum2);  
            if(sum2 < 0) sum2 = 0;
        } 
        int maxi2 = totalsum - maxofmini * (-1); 
        
        if(maxi2 == 0) return maxi1;
        return max(maxi1, maxi2);
        
    }
};
