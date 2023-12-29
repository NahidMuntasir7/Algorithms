// https://codeforces.com/problemset/problem/1915/E

#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> v(n);
        ll ev = 0, od = 0, ok = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        unordered_map<ll, ll> diff;
        for(int i = 0; i < n; i++){
            if(i & 1) od += v[i];
            else ev += v[i];
            ll cdiff = od - ev;
            if(!cdiff or diff.find(cdiff) != diff.end()){
                ok = 1;
                break;
            }
            diff[cd] = i;
        }
        if(!ok) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}
