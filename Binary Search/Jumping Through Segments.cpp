// https://codeforces.com/contest/1907/problem/D
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

vector<int> l, r;
 
        bool valid(int k) {
            int x = 0, y = 0;
            for(int i = 0; i < l.size(); i++) {
                x += k;
                y -= k;
                x = min(x, r[i]);   // ekta line e k poriman length add korle
                y = max(y, l[i]);   // taa next line er sathe overlap kore ki na...
                if(y > x) return false;
            }
            return true;
        }

                
        int main(){
            ios_base::sync_with_stdio(false);   
            cin.tie(NULL);

            int t;
            cin >> t;
            while (t --){
                int n; cin >> n;
                l =  vector<int> (n) ;
                r =  vector<int> (n);
            
            for(int i = 0; i < n; i++) {
                cin >> l[i] >> r[i];
            }
 
            
            int left = 0, right = 1e9, ans;
            while(left <= right) {
                int mid = (left + right) / 2;
                if(valid(mid)) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
 
            cout << ans << "\n";
            }
        }
