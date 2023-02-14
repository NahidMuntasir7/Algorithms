#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, sod = 1, temp;
    cin >> n;
    temp = n;
    for(int i = 2, p; i * i <= n; i++){
        p = i;
        while(!(temp % i)){
            temp /= i;
            p *= i;
        }
        if(p != i) sod *= (p - 1) / (i - 1);
    }
    if(temp > 1) sod *= (temp * temp - 1) / (temp - 1);
    cout << sod << '\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
