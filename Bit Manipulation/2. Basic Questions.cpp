// 1. Finding Unique element
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[] = {1, 1, 2, 2, 3, 3, 4}; // order doesn't matter
    int ans = arr[0];
    for(int i = 1; i < 7; i++){  // x ^ x = 0
        ans ^= arr[i];  
    }
    cout << ans;  // 4
}

// 2. odd or even
    if(n & 1) odd
    else even

// 3. a = 1011 b = 1111. how many bits to change to make them same?
    a = 1010
    b = 1111
  xor = 0100
    ans = the number of set bits...

    int n = 7;
    int cnt = 0;
    while(n){
        cnt += (n & 1);
        n >>= 1;
    }
    cout << cnt; // 3

// 4. Removing the last set bit
    n & (n - 1)          n = 13 ; 13 = 110(1) , 12 = 1100 (13 & 12) = 110(0)
                         n = 12 ; 12 = 1(1)00 , 11 = 1011 (12 & 11) = 1(0)00

// 5. Swapping(xor swapping)
    a = 5, b = 7
    
    a = a ^ b = 5 ^ 7
    b = b ^ a = 7 ^ 5 ^ 7
    b = 5
    a = a ^ b = 5 ^ 7 ^ 5
    a = 7

// 6. Extract i-th bit (masking)
    n & (1 << i)        n = 13 = 1(1)01 
   13 & (1 << 2)                 0(1)00 // for 2nd bit 
                                 0(1)00
// 7. Change i-th bit
    n = n | (1 << i)    

// 8. Clearing the i-th bit
    n = n & ~(1 << i)

// 9. set i-th bit
    n = n | (1 << i)
