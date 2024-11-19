// prefix xor of 0 indexed

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
       vector<int> pre;
       pre.push_back(0);

       for(int i = 0; i < arr.size(); i++){
            pre.push_back(pre.back() ^ arr[i]);
        } 
       
       vector<int> ans;

       for(int i = 0; i < queries.size(); i++){
            int l = queries[i][0] + 1, r = queries[i][1] + 1; // 0 based given
            ans.push_back(pre[r] ^ pre[l - 1]); // - == ^ in xor
        }
        return ans;

    }
};


// another

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries){
        int n = arr.size(), l, r;
        vector<int> pref(n + 1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] ^ arr[i - 1];

        vector<int>ans;
        for(auto &Q:queries)
        {
            l = Q[0], r = Q[1] + 1;
            ans.push_back(pref[r] ^ pref[l]);
        }
        return ans;
    }
};

