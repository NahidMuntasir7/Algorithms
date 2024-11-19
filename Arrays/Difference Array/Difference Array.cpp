#include<bits/stdc++.h>
using namespace std;

const int N = 105;
int d[N], ans[N], a[N];

int32_t main() {
  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
  
    while (q--) {
        int l, r, x; cin >> l >> r >> x;
        d[l] += x;
        d[r + 1] -= x;
    }
  
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + d[i];
        cout << ans[i] + a[i] << ' ';
    }
  
    return 0;
}
