// three condition for a invalid Parentheses:
// 1. )(
// 2. extra closing
// 3. extra opening

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' and st.empty()) s[i] = '@';   // beats )( and extra closing ')'
            else if(s[i] == '(') st.push(i);  // beats extra opening '(' by storing its position
            else if(s[i] == ')' and !st.empty()) st.pop(); // valid
        }   

        while(!st.empty()){ // if extra ((( remains eliminate them
            s[st.top()] = '@';
            st.pop();
        }
        string ss = "";
        for(auto it: s){
            if(it == '@') continue;
            ss += it;
        }
        return ss;
    }
};
