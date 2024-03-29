class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, lo = 0, hi = height.size() - 1;

        while(lo < hi){
            int curr_area = min(height[lo], height[hi]) * (hi - lo);
            ans = max(ans, curr_area);

            if(height[lo] < height[hi]) lo++;
            else hi--;
        } 
        return ans;  
    }
};
