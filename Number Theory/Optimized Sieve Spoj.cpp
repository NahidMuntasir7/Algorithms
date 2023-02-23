#include<bits/stdc++.h>
using namespace std;

const int N = 1e8;

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

     for(int i=1; i < primes.size(); i+=100){
       cout<< primes[i-1] << endl;
      }

  }


/* 
 #include<bits/stdc++.h>
 using namespace std;
 
 #define ll long long
 const int N = 1e6 + 7;

vector<int> primes;

void sievee(){
    vector<bool> sieve(N+1, true) ;
    sieve[0] = sieve[1] = false;

    for(int i = 2; i*i <= N; i++){
        if(sieve[i]){
            for(int j = i*i; j <= N; j+=i){
               sieve[j] = false;
            }
        }
     }
     for(int i = 2; i <= N; i++) {
        if(sieve[i]) primes.push_back(i);
    }
}
 
 int main(){

     ios_base::sync_with_stdio(0);
     cin.tie(0);
     sievee();
    
     for(int i = 0; i < 10 ; i++){
        cout << primes[i] << " ";
     }
 }
*/
