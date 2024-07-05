// ** next greater element type **

// forward

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() and temperatures[i] > temperatures[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};

// backward

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and temperatures[st.top()] <= temperatures[i]){
                st.pop();
            }
            
            if(st.empty()) ans[i] = 0;
            else ans[i] = st.top() - i;
            st.push(i);
        }

        return ans;
    }
};
