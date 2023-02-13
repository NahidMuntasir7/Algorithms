#include<bits/stdc++.h>
using namespace std;

int largestPower(int n, int p){
    int x = 0;
    while (n){
        n /= p;
        x += n;
    }
    return x;
}

int main(){
    int n = 10, p = 3;
    cout <<largestPower(n, p) << endl;
}
