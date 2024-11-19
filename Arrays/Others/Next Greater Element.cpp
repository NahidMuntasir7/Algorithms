class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<int> st;

        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() and arr[i] > arr[st.top()]){
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
