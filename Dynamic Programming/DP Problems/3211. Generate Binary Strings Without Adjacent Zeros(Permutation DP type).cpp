// You are given a positive integer n.
// A binary string x is valid if all substrings of x of length 2 contain at least one "1".
// Return all valid strings with length n, in any order.

// Example 1:
// Input: n = 3
// Output: ["010","011","101","110","111"]
// Explanation:
// The valid strings of length 3 are: "010", "011", "101", "110", and "111".


// Pick and not pick
class Solution {
public:
    vector<string> ans;
    void f(int prev, string &str, int n){
        if(str.length() == n){
            ans.push_back(str);
            return;
        }
        str.push_back('1'); // i can always push back 1
        f(1, str, n);
        str.pop_back();
        
        if(prev == 1){      // if the prev is 1 then only i can push 0 
            str.push_back('0');
            f(0, str, n);
            str.pop_back();
        } 
    }
    vector<string> validStrings(int n) {
        string a = "0", b = "1";

        f(0, a, n); // 010111 tyoe
        f(1, b, n); // 101100 type
        return ans;
    }
};
