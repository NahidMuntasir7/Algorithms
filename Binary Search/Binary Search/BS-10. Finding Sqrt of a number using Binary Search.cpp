// alternative: in-built sqrt() function: int ans = sqrt(n);

#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int low = 1, high = n;     // binary search on the answers

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n)) {
            low = mid + 1;  // eliminate the left half
        }
        else {
            high = mid - 1; // eliminate the right half
        }
    }
    return high;
}


// square root of number upto *given precision* using binary search
// Input : number = 50, precision = 3
// Output : 7.071

#include <bits/stdc++.h>
using namespace std;
 
float squareRoot(int number, int precision){
    int start = 0, end = number;
    int mid;
    
    float ans;     // variable to store the answer

    while (start <= end) {
        mid = (start + end) / 2;
        if (mid * mid == number) {
            ans = mid;
            break;
        }
        if (mid * mid < number) {
            start = mid + 1;
            ans = mid;
        }
        else {
            end = mid - 1;
        }
    }

    float increment = 0.1;
    for (int i = 0; i < precision; i++) {
        while (ans * ans <= number) {
            ans += increment;
        }
       
        ans = ans - increment;  // loop terminates when ans * ans > number
        increment = increment / 10;
    }
    return ans;
}
 

int main(){
    cout << squareRoot(50, 3) << endl;
    cout << squareRoot(10, 4) << endl;
}
