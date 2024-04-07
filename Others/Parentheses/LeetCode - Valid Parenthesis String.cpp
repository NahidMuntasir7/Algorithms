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

        if(st.empty()) return true;
        else{
            while(!st.empty() and !star.empty()){
                if(st.top() > star.top()) return false;
                st.pop(); star.pop();
            }
        }
        if(st.empty()) return true;
        return false;

    }
};
