#include<bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = 5;
  vector<int> p;
  for (int i = 1; i <= n; i++) {
    p.push_back(i);
  }
  do {
    // do something on p
    for (auto x: p) cout << x << ' '; cout << '\n';
  } while (next_permutation(p.begin(), p.end()));
  return 0;
}
