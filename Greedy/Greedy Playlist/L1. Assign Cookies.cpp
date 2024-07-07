// Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

// Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; 
// and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
// Your goal is to maximize the number of your content children and output the maximum number.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, cnt = 0;

        while(i < g.size() and j < s.size()){
            if(g[i] <= s[j]){
                i++;
                j++;
                cnt++;
            }
            else if(g[i] > s[j]){
                j++;
            }
        }
        return cnt;
    }
};

