// Problem statement
// You are given an array of integers 'arr' and an integer 'limit'.
// Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, 
// the sum of the division's result is less than or equal to the given integer's limit.

// Note: Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.

// Sample Input 1 :
// 5
// 1 2 3 4 5
// 8  
// Sample Output 1 :
// 3


#include <bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    int sum = 0;  // Find the summation of division values
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div)); // ** ceil value **
    } 
    return sum;
}

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size();
    if (n > limit) return -1; // edge case: for n = 3 er jonno max jekono divisor e 1 + 1 + 1 dibe.. limit = 2 hole never possible..
    int low = 1, high = *max_element(arr.begin(), arr.end()); // high is max element
                                   // max soho er porer jekono valuer jonno 1 + 1 + 1 + .... dibe
    // Apply binary search
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}
