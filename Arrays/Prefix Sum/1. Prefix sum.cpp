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

// GPT

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; // Input size of array
    vector<int> arr(n), prefixSum(n);

    for (int i = 0; i < n; i++) cin >> arr[i]; // Input array

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    for (int sum : prefixSum) 
        cout << sum << " ";
    return 0;
}

int query(int l, int r, vector<int>& prefixSum) {
    if (l == 0) return prefixSum[r];
    return prefixSum[r] - prefixSum[l - 1];
}
