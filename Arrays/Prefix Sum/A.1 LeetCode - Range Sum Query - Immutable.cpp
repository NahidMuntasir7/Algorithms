// 0 based array and range given... do prefix sum 

class NumArray {
    vector<int> pre; // here...

public:
    NumArray(vector<int>& nums) {
        pre.push_back(0);
        
        for(int i = 0; i < nums.size(); i++){
            pre.push_back(pre.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        right = right + 1, left = left + 1; // as 0 based given

        return pre[right] - pre[left - 1];
    }
};

