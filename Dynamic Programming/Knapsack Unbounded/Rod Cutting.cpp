#include<bits/stdc++.h>
using namespace std;

int rodCut(int price[], int n){ // use this
    if (n == 0) {
        return 0;
    }
    int cost = INT_MIN;
    for (int i = 1; i <= n; i++){
        cost = max(cost, rodCut(price, n - i) + price[i - 1]);
    }
    return cost;
}
int rodCutt(int price[], int n){
    if (n == 0) {
        return 0;
    }
    int maxValue = INT_MIN;
    for (int i = 1; i <= n; i++){
        int cost = rodCut(price, n - i) + price[i - 1];
        maxValue = max(maxValue, cost);
    }
    return maxValue;
} 
int main(){
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };

    int n = 4;
    cout << "Profit is " << rodCut(price, n) << endl;
    cout << "Profit is " << rodCutt(price, n) << endl;
}
