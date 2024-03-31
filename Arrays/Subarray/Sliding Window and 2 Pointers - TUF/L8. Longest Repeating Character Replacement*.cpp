// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
// You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// ** can be written as - longest subarray where the number of different character is <= k **
// this is the optimized one - if instead of while...

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int i = 0, j = 0, maxCount = 0;
        int result = 0;
        while (i < s.length()) {
            count[s[i] - 'A']++;
            maxCount = max(maxCount, count[s[i] - 'A']); // ** if instead of while **
            if (i - j + 1 - maxCount > k) { // number of different char = length - max frequency
                count[s[j] - 'A']--;        // condition (diff <= k)
                j++;
            }
            result = max(result, i - j + 1);
            i++;
        }
        return result;
    }
};
