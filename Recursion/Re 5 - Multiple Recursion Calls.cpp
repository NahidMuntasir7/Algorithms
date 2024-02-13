#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

int fibo(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;
  // if(n <= 1) return n;
  int last = fibo(n - 1); // O(2 ^ n)
  int slast = fibo(n - 2);

  return last + slast;
}
    
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fibo(5);
}

