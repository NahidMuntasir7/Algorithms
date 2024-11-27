#include<bits/stdc++.h>
using namespace std;
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};

    // all x < v ; v = 5
    // or vec = {1, 2, 3, 4, 6, 7}; // v = 5 is not in vec

    int lb = lower_bound(vec.begin(), vec.end(), 5) - vec.begin(); 
    cout << lb << endl; // 4

    // all x > v ; v = 5
    // or vec = {1, 2, 3, 4, 6, 7}; // v = 5 is not in vec

    int ub = vec.size() - (upper_bound(vec.begin(), vec.end(), 5) - vec.begin()); // n - i
    cout << ub << endl; // 2


    vector<int> vv = {1, 2, 3, 3, 4, 5, 6, 7};
    // for 3 lb = 2, ub = 4

    lb = lower_bound(vv.begin(), vv.end(), 10) - vv.begin(); // not in = last index + 1 (both lb & ub)
    ub = upper_bound(vv.begin(), vv.end(), 7) - vv.begin(); // ub equal = last index + 1

    cout << lb << endl; // 8
    cout << ub << endl; // 8

}
