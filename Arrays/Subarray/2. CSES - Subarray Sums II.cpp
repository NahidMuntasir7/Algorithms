//Given an array of n integers, your task is to count the number of subarrays having sum x. (negative included)

#include<bits/stdc++.h>
using namespace std;
int main(){
 int n,x;
    cin >> n >> x;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    long long sum = 0, cnt = 0;
 
    map<long long, int> seen;
 
    seen[0]++; // seen[0] = 1
 
    for(int i = 0; i < n; i++){
        sum += arr[i];
        cnt += seen[sum - x];  // l <- x -> r so, r - l = x or, l = r - x.  current r er jonno suitable l ache kina check..
        seen[sum]++; //
    }
    cout << cnt << endl;
}
