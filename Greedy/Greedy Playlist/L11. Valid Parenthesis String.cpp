// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "(*)"
// Output: true


class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st, star;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*') star.push(i);
            else if(s[i] == '(') st.push(i);
            else if(s[i] == ')' and !st.empty()) st.pop();
            else if(s[i] == ')' and st.empty()){
                if(!star.empty()){
                    star.pop();
                }
                else return false;
            }
        } 

        while(!st.empty() and !star.empty()){
            if(st.top() > star.top()) return false;
            st.pop(); star.pop();
        }
        
        if(st.empty()) return true;
        return false;

    }
};
