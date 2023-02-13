#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;

    vector<bool> sieve(N+1, true) ;
    vector<long long> primes;

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve[0] = sieve[1] = false;

    for(int i = 2; i*i <= N; i++){
        if(sieve[i]){
            for(int j = i*i; j <= N; j+=i){
               sieve[j] = false;
            }
        }
     }
     for(int i = 2; i <= N; i++)  if(sieve[i]) primes.push_back(i);


     long long n, ans;

        cin >> n;
        ans = 1;
        for(long long j = 0; primes[j] * primes[j] <= n; j++){
            long long cnt = 0;
            while(!(n % primes[j])) {
                cnt++;
                n /= primes[j];
            }
            if(cnt) ans *= (cnt + 1);
        }
        if(n > 1) ans *= 2;
        cout << ans << endl; //divisors
    }




