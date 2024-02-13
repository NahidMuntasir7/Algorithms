#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;

void printsum(int i, vector<int> &ds, int s, int sum, int arr[], int n){ // ds - reference must
  if(i == n){
    if(s == sum){
      for(auto it : ds) cout << it << " ";
      cout << endl;
    }
    return;    
  }

  ds.push_back(arr[i]);
  s += arr[i];
  printsum(i + 1, ds, s, sum, arr, n);

  s -= arr[i];
  ds.pop_back(); 
  printsum(i + 1, ds, s, sum, arr, n);
}

bool printsum_once(int i, vector<int> &ds, int s, int sum, int arr[], int n){ // ds - reference must
  if(i == n){
    if(s == sum){
      for(auto it : ds) cout << it << " ";
      cout << endl;
      return true;
    }
    else return false;    
  }

  ds.push_back(arr[i]);
  s += arr[i];
  if(printsum_once(i + 1, ds, s, sum, arr, n) == true){
    return true;
  }
  s -= arr[i];
  ds.pop_back(); 
  if(printsum_once(i + 1, ds, s, sum, arr, n) == true){
    return true;
  }
  return false;
}

int sunseq_count(int i, int s, int sum, int arr[], int n){
  if(s > sum) return 0;
  if(i == n){
    if(s == sum) return 1;
    else return 0;
  }
  s += arr[i];
  int l = sunseq_count(i + 1, s, sum, arr, n);

  s -= arr[i];
  int r = sunseq_count(i + 1, s, sum, arr, n);

  return l + r;
}

int main(){
    
  ios_base::sync_with_stdio(0);
  cin.tie(0);
    
  int arr[] = {1, 2, 1};
  int n = 3;
  int sum = 2;
  vector<int> ds;
  //printsum(0, ds, 0, sum, arr, n);
  cout << sunseq_count(0, 0, sum, arr, n);
}
