#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

void reversee(int l, int r, int a[]){
  if(l >= r) return;
  swap(a[l], a[r]);
  reversee(l + 1, r - 1, a);
}

void reverse_one_var(int i, int n, int a[]){
  if(i >= n / 2) return;
  swap(a[i], a[n - i - 1]); // one variable
  reverse_one_var(i + 1, n, a);
}

bool palindrome(int i, string &s){
  if(i >= (s.size() / 2)) return true;
  if(s[i] != s[s.size() - i - 1]) return false;
  return palindrome(i + 1, s);  // return na lekhleo same
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  int a[5];
  for(int i = 0; i < 5; i++){
    cin >> a[i];
  }
  // reversee(0, 4, a);
  reverse_one_var(0, 5, a);

  for(int i = 0; i < 5; i++){
    cout << a[i] << " ";
  }
  cout << endl;
  
  string s = "aba";
  cout << palindrome(0, s) << endl;
}
