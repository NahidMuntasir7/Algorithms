// Find the length of the longest substring with at most k distinct characters (cnt <= k)
// like the previous one
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp; 
      
        int mx = 0; 
        int left = 0; 
        int n = s.size(); 
      
        for (int right = 0; right < n; right++) {
            mp[s[right]]++;

            while (mp.size() > k) {       // ** O(n) optimization by putting "if" instead of while **
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            mx = max(mx, right - left + 1); // ** if(mp.size() <= k) mx = max(mx, right - left + 1); **
        }
        return mx;
    }
};
 


