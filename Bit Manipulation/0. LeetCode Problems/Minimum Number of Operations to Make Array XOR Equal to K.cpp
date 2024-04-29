class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> bits(21, 0);
        for(auto it: nums){
            for(int i = 0; i < 20; i++){
                if(it & (1 << i)) bits[i]++;
            }
        } 
        int min = 0;  
        for(int i = 0; i < 20; i++){
            if(k & (1 << i)){
                if(bits[i] % 2 == 0) min += 1; 
            }
            else if(bits[i] % 2 == 1) min += 1;
        }
        return min;
    }
};
