// maximum subarray length which sum is <= t
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t; cin >> n >> t;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll sum = 0, count = 0, last = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum <= t){
            count++;
        }
        else{
            sum -= arr[last];
            last++;
        }
    }
    cout << count << endl;
}
