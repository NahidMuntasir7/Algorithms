// Given an array of n positive integers, your task is to count the number of subarrays having sum x. (positive)

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int i = 0, j = 0, cnt = 0;
    long long sum = 0;
 
    while(i < n){
        sum += arr[i];
        while(sum >= x){
           if(sum == x) cnt++;  // sliding window
           sum -= arr[j];
           j++;
         }
         i++;
      }
      cout << cnt << endl;
}
 
 
 
 
