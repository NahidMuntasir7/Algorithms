// Painter's Partition Problem

// Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents the length of each board. 
// Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board takes 1 unit of time to paint.
// You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint that 
// any painter will only paint the continuous sections of boards.

// Example :
// Input: arr = [2, 1, 5, 6, 2, 3], k = 2
// Output: 11

// ----------------------------------- min of (max) ------------------------------------
// split the array in k non empty subarrays where maximum subarray sum is minimum
// similar to book allocation (sameeee)


// Largest Subarray Sum Minimized

// Given an integer array ‘A’ of size ‘N’ and an integer ‘K'.
// Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
// Your task is to return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example:
// Input: ‘N’ = 5, ‘A’ = [1, 2, 3, 4, 5], ‘K’ = 3
// Output: 6

// Explanation: There are many ways to split the array ‘A’ into K consecutive subarrays. 
// The best way to do this is to split the array ‘A’ into [1, 2, 3], [4], and [5], where the largest sum among the three subarrays is only 6.


// book allocation code will work here

#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages) {
    int n = arr.size(); //size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++) {
        if (pagesStudent + arr[i] <= pages) {
            //add pages to current student
            pagesStudent += arr[i];
        }
        else {
            //add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    //book allocation impossible:
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());  // n = book and m = student
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1; // <<<--------- (going towards to the max)
        }
    }
    return low; // last valid high
}

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
