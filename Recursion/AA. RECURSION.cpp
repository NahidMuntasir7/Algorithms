// we are at n = 5
// we are at n = 4
// we are at n = 3
// we are at n = 2
// we are at n = 1
// we are at n = 0
// do not need to go further
// returning 0 from function with n = 0
// returning 1 from function with n = 1
// returning 3 from function with n = 2
// returning 6 from function with n = 3
// returning 10 from function with n = 4
// returning 15 from function with n = 5
// 15
  
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;


int sum(int n){
    cout << "we are at n = " << n << endl;                                                    

    if(n == 0){
        cout << "do not need to go further" << endl;
        cout << "returning " << 0 << " from function with n = " << n << endl;
        return 0;
    }

    int res = sum(n - 1) + n;
    cout << "returning " << res << " from function with n = " << n << endl;
    
    return res;
}
    
int main(){
    cout << sum(5) << endl;
}


