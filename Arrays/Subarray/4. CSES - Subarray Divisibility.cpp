// Given an array of n integers, your task is to count the number of subarrays where the sum of values is divisible by n.(negative included)
#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> val(n);
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    long long sum = 0, cnt = 0;
    map<long long, int> seen;
 
    seen[0]++;
    for(int i = 0; i < n; i++){
        sum += val[i] % n;  //  sum = ((sum + nums[i]) % k + k) % k; 
        sum = (sum + n) % n; // for negative.. for ex: (2 + 7) % 7 = 2 and (-2 + 7) % 7 = 5
        cnt += seen[sum];
        seen[sum]++;
    }
    cout << cnt << endl;
}
