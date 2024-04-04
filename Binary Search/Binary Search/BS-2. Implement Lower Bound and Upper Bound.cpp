// lower bound 
// smallest index such that arr[i] >= n
// arr[] = 3, 5, 8, 15, 19, 19, 19
// let n = 8  so, lower bound = 8 
// let n = 9  so, lower bound = 15 
// let n = 19 so, lower bound = 19(1st occurence)
// let n = 20..  lower bound = last index + 1 / size of the array


// implementing lower bound

int low = 0, high = n - 1;
int ans = n; // 
while (low <= high) {
    int mid = low + (high - low) / 2;
    
    if(arr[mid] >= n){
        ans = mid; // last high before the loop breaks... after this low > high
        high = mid - 1;
    }
    else low = mid + 1;
}

// STL for upper bound
int lb = lower_bound(v.begin(), v.end(), n) - v.begin(); // minus for index



// LeetCode - Search Insert Position



//upper bound
// smallest index such that arr[i] > n

    if(arr[mid] > n){   // only difference >= to > 
        ans = mid; 
        high = mid - 1;
    }
    else low = mid + 1;

// STL for lower bound
int lb = upper_bound(v.begin(), v.end(), n) - v.begin();




// LeetCode - Search Insert Position
// can be implemented using lower bound

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size() - 1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        } 
        return hi + 1;  // when not present in the array... high < low 
    }
};



// floor and ceil in an array

// floor largest number in the array <= x
// ceil  smallest  no  in the  array >= x


// floor implementation
int lo = 0, hi = nums.size() - 1, floor;
    while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] <= target){ 
                floor = nums[mid];  
                lo = mid + 1; // ----->
            }
            else hi = mid - 1;
        } 


// ceil implementation
int lo = 0, hi = nums.size() - 1, ceil;
    while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(nums[mid] >= target){ 
                ceil = nums[mid];  
                hi = mid - 1; // <-----
            }
            else lo = mid + 1;
        } 
