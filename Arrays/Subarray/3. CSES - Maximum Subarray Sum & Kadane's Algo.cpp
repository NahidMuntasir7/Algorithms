// First Version if you need the maximum subarray sum in all cases, **including arrays with all negative numbers**.

#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    ll arr[n];
 
    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll maxi = INT_MIN, sum = 0;
 
    for(ll i = 0; i < n; i++){
        sum = max(sum + arr[i], arr[i]);   //... -1 -5 -2 ... in this case we will take -2 ...
        maxi = max(maxi, sum);  // taking max of all changing sum ...
    }
    cout << maxi << endl;
}



// Kadane's Algorithm: this one handles negative values but sets sum to 0 when all negative

    ll maxi = INT_MIN, sum = 0;
 
    for(ll i = 0; i < n; i++){
        sum = sum + arr[i];      // sum
        maxi = max(maxi, sum);   // maximum
        if(sum < 0) sum = 0;     // savior
    }

