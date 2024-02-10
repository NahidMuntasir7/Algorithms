
#include<bits/stdc++.h>
using namespace std;
    
#define ll long long
#define endl '\n'
const int N = 1e6 + 7;
    
ll parent[N];
ll size[N]; 
void make_set(ll v) {
    parent[v] = v; 
    size[v] = 1;
}
ll find_set(ll v) {
    // return (v == parent[v]) ? v : parent[v] = find_set(parent[v]);
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void union_sets(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return;
    if(size[a] < size[b]) swap(a,b);
    parent[b] = a;
    size[a] += size[b]; 
    size[b] = 0;
}
ll get_size(ll v){
    return size[find_set(v)];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    make_set(1); make_set(2); 
    union_sets(1, 2);
    cout << find_set(1) << endl;
    cout << get_size(1) << endl; 
}
