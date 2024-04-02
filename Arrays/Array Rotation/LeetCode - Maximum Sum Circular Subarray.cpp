class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi1 = INT_MIN, sum1 = 0, totalsum = 0;

         for(int i = 0; i < nums.size(); i++){
            totalsum += nums[i];

            sum1 = sum1 + nums[i];   
            maxi1 = max(maxi1, sum1);  // maximum
            if(sum1 < 0) sum1 = 0;
        }  

        int maxofmini = INT_MIN, sum2 = 0;
 
         for(int i = 0; i < nums.size(); i++){
            sum2 = sum2 + nums[i] * (-1);   
            maxofmini = max(maxofmini, sum2);  // minimum
            if(sum2 < 0) sum2 = 0;
        } 
        int maxi2 = totalsum - maxofmini * (-1); // total - minimum => circular
        
        if(maxi2 == 0) return maxi1; // empty subarray... when all negative (totalsum - maxofmini == 0)
        return max(maxi1, maxi2);                                        // -3 -5 -1 here, total sum = -9, max of mini = -9 so, ans = 0; no subarray will be taken  
                                                                                                                                      // but ans will be -1
    }
};
