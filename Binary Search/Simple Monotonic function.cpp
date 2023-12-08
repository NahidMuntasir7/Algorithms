#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;


int func(int arr[], int mid){
    return arr[mid];
}
    
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int lo = 0, hi = n - 1, ans;
    while(lo <= hi){

        int mid = (lo + hi) / 2;        // 0 0 0 0 0 (1) 1 1 1 [ans = 5] first 1
        if(func(arr, mid)){
            ans = hi;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << endl;
}
