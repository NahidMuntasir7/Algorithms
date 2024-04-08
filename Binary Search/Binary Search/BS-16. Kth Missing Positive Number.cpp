// Problem statement
// You are given a strictly increasing array 'vec' and a positive integer 'k'.
// Find the 'kth' positive integer missing from 'vec'.

// Example :
// Input: vec = [2,4,5,7] , k = 3
// Output: 6

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size(); 
       int low = 0;
       int high = n-1;
       while(low <= high){
        int mid = low + (high - low) / 2;
        int missingNumber = arr[mid] - (mid + 1); // finding missing number by subtracting the original number with the value to be present at that index
        if(missingNumber < k){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
       }
       // low and high->points towards the range the answer will lie,they will be in opposite polarity.
       // we return the answer as arr[high]+more 
       // more = k- missingNumber
       // more = k - (arr[high]-high-1))
       // therefore arr[high]+more = arr[high]+k-arr[high]+high+1
       // which is equal to k+high+1
       // but low = high+1 
       // so we can return  either low+k or high+1+k

      return low + k;

    }
};

