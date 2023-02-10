#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
#define  ll long long

ll spf[N], sod[N], nod[N];

int main(){

ios_base::sync_with_stdio(0);
cin.tie(0);

for(ll i = 2; i <= N; i++){
    spf[i] = i;
}

for(ll i = 2; i <= N; i++){
    for(ll j = i; j <= N; j += i){
       spf[j] = min(spf[j],i);
    }
}

for(ll i = 1; i <= N; i++){
    for(ll j = i; j <= N; j += i){
        sod[j] += i;
        nod[j]++;
    }
}

ll n, x, cpy;
cin >> n;

while(n--){
    cin >> x;
    cpy = x;

    set<ll> dpf;  //distinct prime factor
    ll tpf = 0, gpf = 0;  //total pf

    while(x > 1){
        dpf.insert(spf[x]);
        tpf++;
        gpf = max(gpf,spf[x]);
        x /= spf[x];
    }

    cout << spf[cpy] << " " << gpf << " " << dpf.size() << " " << tpf << " " << nod[cpy] << " " << sod[cpy] << '\n' ;

  }
}
