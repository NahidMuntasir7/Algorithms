// You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. 
// Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

// At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. 
// Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

// Examples:

// Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
// Output: 3
// Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.



// more than one plartform needed when it is intersecting
// so need to find out maximum number of intersections



#include<bits/stdc++.h>
using namespace std;
 
int countPlatforms(int n, int arr[], int dep[]){
    sort(arr, arr + n);
    sort(dep, dep + n);
 
    int ans = 1;
    int count = 1;
    int i = 1, j = 0;
    while(i < n && j < n){
        if(arr[i] <= dep[j]) {
            count++;   //one more platform needed
            i++;
        }
        else{
            count--; //one platform can be reduced
            j++;
        }
        ans = max(ans, count); //updating the value with the current maximum
    }
    return ans;
 }
 
 int main(){
     
    int arr[] = {900, 945, 955, 1100, 1500, 1800};
    int dep[] = {920, 1200, 1130, 1150, 1900, 2000};
    int n = sizeof(dep) / sizeof(dep[0]);
    cout << "Minimum number of Platforms required " << countPlatforms(n, arr, dep) << endl;
 }
