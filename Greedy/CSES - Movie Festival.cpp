#include<bits/stdc++.h>
using namespace std;
 
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second){
        return a.second < b.second ;
    }
    else return a.first < b.first;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin() ,v.end(), cmp);
    int cnt = 1;
    int temp = v[0].second;
  
    for(int i = 1; i < n; i++){      
        if(v[i].first >= temp){
            cnt++ ;
            temp = v[i].second;
        }
    }
    cout << cnt << endl;
}

