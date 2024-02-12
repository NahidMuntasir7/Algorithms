#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

void sum_of_n_par(int i, int sum){ // parameterized
  if(i < 1){
    cout << sum << endl; // oi break/base point er sum print (i = 0 er)
    return;              // ** printed particular parameter **
  }
  sum_of_n_par(i - 1, sum + i);
}

int sum_of_n_fun(int n){ // functional
  if(n == 0) return 0;
  return n + sum_of_n_fun(n - 1); // function is returning
}   
int main(){
    
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  sum_of_n_par(4, 0);
  cout << sum_of_n_fun(5);
}
