#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

void print(int i, vector<int> &ds, int arr[], int n){ // ds - reference must
  if(i == n){
    for(auto it : ds){
      cout << it << " ";
    }
    if(ds.size() == 0) cout << "{}";
    cout << endl;
    return;
  }
  ds.push_back(arr[i]);
  print(i + 1, ds, arr, n);
  ds.pop_back(); 
  print(i + 1, ds, arr, n);
}


    
int main(){
    
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    
  int arr[] = {3, 1, 2};
  int n = 3;
  vector<int> ds;
  print(0, ds, arr, n);
}
