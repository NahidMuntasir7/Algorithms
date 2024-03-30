// 1. Constant window
// 2. longest subarray / substring where <condition>
// 3. number of subarray / substring where <condition>
// 4. shortest / minimum window where <condition>

// 1. Constant window

1. sum till k
from k + 1 -> sum += arr[r] r++; 
from 0 ->     sum -= arr[l] l++;
if(sum == K) ...



// 2. longest subarray / substring where <condition>

for(int l,r = 0; r < n; r++){
    do_something_by_adding(nums[r]);
    while (!check_condition(k)){
        do_something_by_removing(nums[l]);
        l++;
    }
    update_the_answer();
}

// Given an array of n positive integers, your task is to count the number of subarrays having sum x. (positive)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int start = 0, end = 0, cnt = 0;
    long long sum = 0;
 
    while(start < n){
        sum += arr[start];
        while(sum >= x){
           if(sum == x) cnt++; // to do
           sum -= arr[end];
           end++;
         }
         start++;
      }
      cout << cnt << endl;
}


// LeetCode - Length of Longest Subarray With at Most K Frequency (cnt <= k)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int maxLen = 0;
        
        for(int right = 0, left = 0 ; right < nums.size() ; right++){
            freq[nums[right]]++;
            
            while(freq[nums[right]] > k){  // opposite
                freq[nums[left]]--;
                left++;
            }
            
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};
