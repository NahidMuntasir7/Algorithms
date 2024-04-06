class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int flag = 0;
        for(int i = 0; i < s.size(); i++){
            if(st.empty()) st.push(s[i]);  // beats "()]"
            else if((s[i] == ')' and st.top() == '(') or (s[i] == ']' and st.top() == '[') or (s[i] == '}' and st.top() == '{')){
                if(!st.empty()) st.pop(); //pop condition
            }
            else st.push(s[i]); // beats "(])" empty na but push korte hobe..
        } 
        return st.empty();    
    }
};
