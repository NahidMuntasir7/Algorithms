#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

// print name N times 
void name_n_times(int n){
  if(n == 0) return;
  cout << "RIFAT" << endl; // O(n) time & space
  name_n_times(n - 1);
}

void name_n_times_2(int i, int n){
  if(i > n) return;
  cout << "RIFAT2" << endl; // O(n) time & space
  name_n_times_2(i + 1, n);
}

// print linearly from 1 to N
void print_one_to_n(int i, int n){
  if(i > n) return;
  cout << i << endl;
  print_one_to_n(i + 1, n);
}
// print linearly from N to 1
void print_n_to_one(int i, int n){
  if(i < 1) return;
  cout << i << endl;
  print_n_to_one(i - 1, n);
}
    
void printer(int n) {
  if (n == 0) return;

  cout << n << " "; // niche namar somoy print
  printer(n - 1);
  cout << n << " "; // backtrack - back korar somoy print
}

int main(){
    
  int n; cin >> n;
  // name_n_times(n);
  // name_n_times_2(1, n);
  // print_one_to_n(1, n);
  // print_n_to_one(5, 5);
  n = 4;
  printer(n);
}
