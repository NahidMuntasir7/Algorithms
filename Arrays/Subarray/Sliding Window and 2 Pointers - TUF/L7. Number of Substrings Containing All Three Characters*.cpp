// Given a string s consisting only of characters a, b and c.
// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// **NUMBER** of Subarrays

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> present(3, 0);
        int n = s.length();
        int i = 0, j = 0;
        int count = 0;
        while(j < n){
            present[s[j]-'a']++;
            while(present[0] > 0 && present[1] > 0 && present[2] > 0){ // its following the condition - check further...
                count += n - j;
                present[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return count;
    }
};


// Same - Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int count = 0;
        int left = 0, right = 0, n = nums.size();
        unordered_map<int, int> freq;

        int mx = *max_element(nums.begin(), nums.end()); 

        while (right < n) {
            freq[nums[right]]++;
            while (freq[mx] >= k) { // its following the condition - check further... 
                count += n - right; // [ (1, 2, 3, 3), 4*, 5*, 6*] (n - right = 7 - 3 = 4 ta subarray)
                freq[nums[left]]--;
                left++;                   
            } 
            right++;    
        }
        return count;    
    }
};
