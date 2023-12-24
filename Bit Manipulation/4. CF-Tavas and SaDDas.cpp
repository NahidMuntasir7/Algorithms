#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<ll> anss;
    for(int k = 1; k <= 10; k++){     // number's digit is increasing
        for(int mask = 0; mask < (1 << k); mask++){ // creating masks (for each length all combination check) 
            ll ans = 0;
            for(int i = 0; i < k; i++){  // for 1 mask constructing the digit
                if(mask & (1 << i)){
                    ans *= 10;
                    ans += 7;
                }
                else{
                    ans *= 10;
                    ans += 4;
                }
            }
            anss.push_back(ans);
        }
    }
    sort(anss.begin(), anss.end());

    cout << lower_bound(anss.begin(), anss.end(), n) - anss.begin() + 1 << endl; // finding x in log(n) tc (1 based indexing)
}
