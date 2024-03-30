// LeetCode - Fruit Into Baskets
// maximum length of subarray with at most 2 types of numbers

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        unordered_map<int,int> mp;
        for(int left = 0, right = 0; right < fruits.size(); right++){
            mp[fruits[right]]++;
            while(mp.size() > 2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]); //
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
