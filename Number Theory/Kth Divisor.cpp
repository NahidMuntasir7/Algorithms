#include<bits/stdc++.h>
using namespace std;
int main(){

    long long n, k;
    cin >> n >> k;

    vector<long long> v;
    for(long long i = 1; i * i <= n; i++){
        if(!(n % i)){
            v.push_back(i);
            if(i != n / i) v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());

    if(v.size() < k) cout << -1 << '\n';
    else cout << v[k - 1] << '\n';
}

