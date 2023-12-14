#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> apples(n);
    for(int i = 0; i < n; i++){
        cin >> apples[i];
    }
    ll ans = 1e18;

    for(int mask = 0; mask < (1 << n); mask++){
        ll sumA = 0, sumB = 0;
 
        for(int pos = 0; pos < n; pos++){
            if(mask & (1 << pos))          // 1 ke shifting to check each bit of mask from right to left
                sumA += apples[pos];
            else 
                sumB += apples[pos];
        }
        ans = min(ans, abs(sumA - sumB));
    }
    cout << ans << endl;
}
