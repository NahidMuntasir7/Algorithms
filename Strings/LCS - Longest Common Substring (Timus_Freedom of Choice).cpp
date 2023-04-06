#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

int modpow(long long a, long long n, const int m) {
    int r = 1 % m;
    a %= m;
    if(n < 0) a += m;
    while (n) {
        if(n & 1) r = (long long) r * a % m;
        a = (long long) a * a % m;
        n >>= 1;
    }
    return r;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
    pw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
    }
    ip1 = modpow(p1, MOD1 - 2, MOD1);
    ip2 = modpow(p2, MOD2 - 2, MOD2);
    ipw[0] = {1, 1};
    for(int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
    }
}

struct Hashing {                         // 1 index based
    int n;
    string s;
    vector<pair<int, int>> hs;
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hs.emplace_back(0, 0);
        for(int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
            p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
            hs.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) {
        assert(1 <= l && l <= r && r <= n);
        pair<int, int> ans;
        ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
        ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

int lcs(Hashing &ha, Hashing &hb, int len){
    set<pair<int, int>> st;
    for(int i = 1; i + len - 1 <= ha.n; i++){
        st.insert(ha.get_hash(i, i + len - 1));
    }
    for(int i = 1; i + len - 1 <= hb.n; i++){
        if(st.count(hb.get_hash(i, i + len - 1))) return i;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    prec(); ///

    int n; cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    
    Hashing ha(sa), hb(sb);

    int l = 1, r = n;      // 1 index based bhai

    pair<int, int> ans = {0, -1};  // {0, 0} is also ok...
    while(l <= r){
        int mid = (l + r) / 2;
        int ok = lcs(ha, hb, mid);
        if(ok != -1){
            ans = {mid, ok};
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << sb.substr(ans.second - 1, ans.first) << '\n';
}

