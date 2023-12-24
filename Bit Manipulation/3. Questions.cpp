// 1. playing with bits

// a = 10, b = 15 how many set bits are there in total from a to b, ans = 17
  // bruteforce to count set bits one by one
  // another way to calculate odd and even at the same time
#include<bits/stdc++.h>
using namespace std;
int CountSetBits(int n){
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int a, b; cin >> a >> b;
        int cnt = 0; 
        for(int i = a; i <= b; i++){
            if((i & 1) == 0 and i < b){
                cnt += 2 * CountSetBits(i) + 1; // even and odd
                i++;
                continue;
            }
            cnt += CountSetBits(i); // first or last b if odd
        }
        cout << cnt << endl;
    }
}  

//2. Hackerrank - Maximizing XOR
// given two integers l and r. find the maximum value of a xor b. where l <= a <= b <= r.
  
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);	
    int x, y;   cin >> x >> y;
    int maxXor = 0;
    for (int i = x; i <= y; i++){
        for (int j = i; j <= y; j++){ // bruteforce :|
            int currentXor = (i ^ j);
            maxXor = max(maxXor, currentXor);
        }
    }
    cout << maxXor << '\n';
    return 0;
}

// 3. GFG - Unique Number 2
// Find two non repeating element in an array of repeating elements. ex : 1 1 2 3 ans -> 2, 3 
res = 1 ^ 1 ^ 2 ^ 3 = 2 ^ 3      2 -> 1  0    | who got 0-th bit set? temparr = 1 ^ 1 ^ 3  so, a = 3
                                 3 -> 1  1    | a = 3 and res = 2 ^ 3 so, b = res ^ a = 2...
                                   -> 0 (1) so, one diff spotted.

#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int arr[n];

    int res = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        res ^= arr[i];
    }
    int tempRes = res, index = 0;
    while(tempRes){
        if(tempRes & 1) break;  // koto no index e 1 ache
        index++;
        tempRes >>= 1;
    }
    int mask = (1 << index);
    vector<int> tempArr;

    for(int i = 0; i < n; i++){
        if(arr[i] & mask) tempArr.push_back(arr[i]);
    }
    int a = 0;
    for(auto it : tempArr){
        a ^= it;
    }
    int b = res ^ a;

    if(a > b) cout << b << " " << a << endl;
    else cout << a << " " << b << endl;
}
