#include <bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin >> test;
    for (int i = 1; i <= test; i++){
        string a;
        int b;
        cin >> a >> b;
        int j = 0;
        if (a[0] == '-') j = 1;
        if (b < 0) b = abs(b);
        long rim = 0;
        for ( ; j < a.size(); j++)
        {
            rim = rim*10 + (a[j] - '0');
            rim %= b;
        }
        if (rim == 0) cout << "Case " << i << ": divisible" <<'\n';
        else cout << "Case " << i << ": not divisible" <<'\n';
    }
}
