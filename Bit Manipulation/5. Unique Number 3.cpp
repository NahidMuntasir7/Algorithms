// array given like 1, 1, 1, 2 ,2, 2, 3. what is the unique number?

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int count[32] = {0};

    for (int i = 0; i < n; i++){
        int number = arr[i];
        int j = 0;
        while (number > 0){
            count[j] += (number & 1);
            j++;
            number = number >> 1;
        }
    }
    int ans = 0, position = 1;
    for (int i = 0; i < 32; i++){ // bit cnt array
        count[i] %= 3;           // as three numbers are common
        ans += count[i] * position; // sum += 2 ^ i * cnt[i];
        position = position << 1;
    }
    cout << "Unique Number is: " << ans << '\n';
    return 0;
}
