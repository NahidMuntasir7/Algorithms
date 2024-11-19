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
    ll best = INT_MIN, sum = 0;
 
    for(ll i = 0; i < n; i++){
        sum = max(sum + arr[i], arr[i]);   //... -1 -5 -2 ... in this case we will take -2 ...
        best = max(best, sum);  // taking max of all changing sum ...
    }
    cout << best << endl;
}



// Kadane's Algorithm
    ll maxi = INT_MIN, sum = 0;
 
    for(ll i = 0; i < n; i++){
        sum = sum + arr[i];   
        maxi = max(maxi, sum);  
        if(sum < 0) sum = 0;
    }

