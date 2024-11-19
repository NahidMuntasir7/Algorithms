// number of subarrays
// Given an array of n positive integers, your task is to count the number of subarrays having sum x. (positive)

// *** positive numbers 1 to 10^9 *** no negative and zeroo ***

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
 
 
 
 
