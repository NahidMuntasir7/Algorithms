// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 
// Example 1:

// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".


class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int i = 0, j = s.size() - 1;
        while(i < j){
            if(!st.count(s[i])) i++;
            else if(!st.count(s[j])) j--;
            else{
                swap(s[i], s[j]);
                i++; j--;
            }
        }
        return s;
    }
};



// another -_-

class Solution {
public:
    string reverseVowels(string s) {
        vector<char> ch;
        vector<int> ind;
        set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i = 0; i < s.size(); i++){
            if(st.count(s[i])){
                ch.push_back(s[i]);
                ind.push_back(i);
            }
        }    
        reverse(ch.begin(), ch.end());
        for(int i = 0; i < ch.size(); i++){
            s[ind[i]] = ch[i]; 
        }
        return s;
    }
};
