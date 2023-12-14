#include<bits/stdc++.h>
using namespace std;

int findMaxProfit(int n){
    if (n <= 1) {
        return n;  // 0 or 1
    }
    int maxValue = n; // i can take the total length
    for (int i = 1; i <= n; i++) {
        maxValue = max(maxValue, findMaxProfit(n - i) * i); // the max product of various length (lengths sum will be n)
    }
    return maxValue;
}
 
int main(){
    // n is rod length
    int n = 15;
    cout << "The Maximum profit is " << findMaxProfit(n);
}
