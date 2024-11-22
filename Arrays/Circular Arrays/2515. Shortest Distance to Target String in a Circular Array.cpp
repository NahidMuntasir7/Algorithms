// You are given a 0-indexed circular string array words and a string target. A circular array means that the array's end connects to the array's beginning.

// Formally, the next element of words[i] is words[(i + 1) % n] and the previous element of words[i] is words[(i - 1 + n) % n], where n is the length of words.
// Starting from startIndex, you can move to either the next word or the previous word with 1 step at a time.

// Return the shortest distance needed to reach the string target. If the string target does not exist in words, return -1.




class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        vector<int> v;

        for(int i = 0; i < words.size(); i++){
            if(words[i] == target) v.push_back(i);
        }
        int ans = 0, mini = INT_MAX, n = words.size() - 1;

        if(v.size() == 0) return -1;
        else{
            for(int i = 0; i < v.size(); i++){
                ans = min((n - startIndex) + (1 + v[i]), (startIndex + 1) + (n - v[i])); // <-- distance  and --> distance
                ans = min(ans, abs(v[i] - startIndex));  // direct distance
                mini = min(mini, ans);
            }
        }
        return mini;
    }
};
