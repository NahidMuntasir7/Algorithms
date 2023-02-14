#include<bits/stdc++.h>
using namespace std;

const int N = 2e7 + 7;

    vector<bool> sieve(N+1, true) ;
    vector<int> primes;

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


    vector<pair<int,int>> vp;


    for(int i = 1; i<=1e5 + 5; i++){
        if(primes[i] + 2 == primes[i + 1]) vp.push_back({primes[i], primes[i + 1]});
    }

    int n;
    while(cin >> n){
        cout << '(' << vp[n - 1].first << ", " << vp[n - 1].second << ')' << '\n';
    }
}
