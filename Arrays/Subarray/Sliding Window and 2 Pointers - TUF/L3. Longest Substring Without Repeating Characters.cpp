class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;
        int ans = 0, end = 0;

        for(int start = 0; start < s.size(); start++){
            if(!st.count(s[start])){
                st.insert(s[start]);
                ans = max(ans, start - end + 1);
            }
            else{
                while(st.count(s[start])){
                    st.erase(s[end]);
                    end++;
                }
                st.insert(s[start]);
            }
        }
        return ans;  
    }
};
