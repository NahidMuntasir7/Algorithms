#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int arr[n + 1], pre[n + 1] = {0};

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i - 1] + arr[i];
    }

    int l, r; cin >> l >> r;
    cout << pre[r] - pre[l - 1] << endl;
}
