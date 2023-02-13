#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, p, ans;
    cin >> t;
    for(int tt = 1; tt <= t; tt++){
        cin >> p >> n;

        vector<int> v(10001 + 1);
        int temp;
        for(int i = 1; i <= n; i++){
            temp = i;
            for(int j = 2; j * j <= i; j++){
                while(!(temp % j)){
                    temp /= j;
                    v[j]++;
                }
            }
            if(temp > 1) v[temp]++;
        }
        ans = INT_MAX;
        temp = p;
        for(int i = 2, cnt; i * i <= p; i++){
            if(!(temp % i)){
                cnt = 0;
                while(!(temp % i)){
                    temp /= i;
                    cnt++;
                }
                ans = min(ans, v[i] / cnt);
            }
        }
        if(temp > 1){
            ans = min(ans, v[temp]);  // v[temp] / 1
        }
        cout << "Case " << tt << ":\n";
        if(ans <= 0) cout << "Impossible to divide" << '\n';
        else cout << ans << '\n';
    }
}
