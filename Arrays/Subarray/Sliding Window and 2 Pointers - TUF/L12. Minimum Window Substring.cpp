// Given two strings s and t of lengths m and n respectively, return the minimum window substring
// of s such that every character in t (including duplicates) is included in the window. 
// If there is no such substring, return the empty string "".

class Solution {
public:
    string minWindow(string s, string t) {
        int len = s.length();
        if(t.length() > len) return "";
        int reqcount = t.length();

        unordered_map<char, int> mp;
        int starti = 0;
        int i = 0, j = 0;
        int ans = INT_MAX;
        for(auto c: t){ //increase freq of chars from t
            mp[c]++;
        }

        while(j < len){
            if(mp[s[j]] > 0){
                reqcount--; //that means we need it
            }
            mp[s[j]]--;
            while(reqcount == 0){
                int win = j - i + 1; // 1 window found
                if(ans > win){   
                    ans = win; // len
                    starti = i; // starting pos
                }
                //now check if we can shrink i
                mp[s[i]]++;
                if(mp[s[i]] > 0){
                    reqcount++;
                }
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? "" : s.substr(starti, ans);
    }
};
