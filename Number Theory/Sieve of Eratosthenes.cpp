#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;

int main(){

vector<bool> sieve(N,true);
sieve[0] = false;
sieve[1] = false;

for(int i = 2; i*i <= N ; i++){
    if(sieve[i]){
        for(int j = i*i; j <= N; j+=i){
            sieve[j] = false;
        }
    }
}

long long n;
cin >> n;
while(n--){
    long long x; cin >> x;
    long long a = sqrt(x);
    if(sieve[a] == true && a * a == x){
        cout << "YES" <<'\n';
    }

    else cout << "NO" <<'\n';
  }
}
