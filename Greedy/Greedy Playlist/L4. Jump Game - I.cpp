// Given an array where each element represents the maximum number of steps you can jump forward from that element, 
// return true if we can reach the last index starting from the first index. Otherwise, return false.

// Example 1:
// Input:nums = [2, 3, 1, 0, 4]
                
// Output: True
// Explanation: 
// We start at index 0, with value 2 this means we can jump to index 1 or 2.
// From index 1, with value 3, we can jump to index 2, 3, or 4. However, if we jump to index 2 with value 1, we can only jump to index 3.
// So we jump to index 1 then index 4 reaching the end of the array.
// Hence, we return true.


// solution

bool canJump(vector<int>& nums) {
    int maxIndex = 0;
    for(int i = 0; i < nums.size(); i++){
        if (i > maxIndex){
            return false;
        }
        maxIndex = max(maxIndex, i + nums[i]);
    }
    return true;
}
                            
// my sol

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 and nums[0] == 0) return true;
        set<int> s;
        bool tr = true;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(s.upper_bound(i) != s.end()){ // if there is any jump greater than current index
                    // cool no problem // tr = true;
                }
                else {
                    if(i != nums.size() - 1) return false; // no jump and not in the last index
                }
            }
            else{
                s.insert(i + nums[i]); // max jump index from current index
            }
        }  
        return tr;  
    }
};
