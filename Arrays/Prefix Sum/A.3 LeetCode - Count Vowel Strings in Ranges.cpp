// Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_set<char> st= {'a', 'e', 'i', 'o', 'u'};

        vector<int> arr(words.size(), 0);
      
        for(int i = 0; i < words.size(); i++){
            if(st.count(words[i].front()) and st.count(words[i].back())) arr[i] = 1;
        }
        vector<int> pre;
        pre.push_back(0);

        for(int i = 0; i < arr.size(); i++){
            pre.push_back(pre.back() + arr[i]);
        }

        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0] + 1, r = queries[i][1] + 1; // 0 based
            ans.push_back(pre[r] - pre[l - 1]);
        }

        return ans;
    }
};



// less code
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        unordered_set<char> st= {'a', 'e', 'i', 'o', 'u'};

        vector<int> arr(words.size(), 0);
        vector<int> pre;
        pre.push_back(0);
        
        for(int i = 0; i < words.size(); i++){
            if(st.count(words[i].front()) and st.count(words[i].back())) arr[i] = 1;
             pre.push_back(pre.back() + arr[i]); // 
        }
        
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0] + 1, r = queries[i][1] + 1; // 0 based
            ans.push_back(pre[r] - pre[l - 1]);
        }

        return ans;
    }
};
