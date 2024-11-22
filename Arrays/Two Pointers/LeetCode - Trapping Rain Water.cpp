// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


// last max er hishebe water count  (7) 1 2 (9) 4 2 -----> right max is >|
//                                  | left max is >  <----- 3 5 (7) 2 4 (9)                 

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, left_max = height[0], sum = 0;
        int j = height.size() - 1, right_max = height[j];
        while (i < j) {
            if (left_max <= right_max) {
                sum += (left_max - height[i]);
                i++;
                left_max = max(left_max, height[i]);
            } 
            else {
                sum += (right_max - height[j]);
                j--;
                right_max = max(right_max, height[j]);
            }
        }
        return sum;
    }
};

