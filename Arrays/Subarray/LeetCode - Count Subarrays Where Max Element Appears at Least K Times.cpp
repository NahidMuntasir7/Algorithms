class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int count = 0;
        int left = 0, right = 0, n = nums.size();
        unordered_map<int, int> freq;

        int mx = *max_element(nums.begin(), nums.end()); 

        while (right < n) {
            
            freq[nums[right]]++;
            
            while (freq[mx] >= k) {
                count += n - right; // [ (1, 2, 3, 3), 4*, 5*, 6*] (n - right = 7 - 3 = 4 ta subarray)
                freq[nums[left]]--;
                left++;                   
            } 
            right++;    
        }
        return count;    
    }
};

/* for(int l,r=0; r<n; r++){
    do_something_by_adding(nums[r]);
    while (!check_condition(k)){
        do_something_by_removing(nums[l]);
        l++;
    }
    update_the_answer();
}
*/
