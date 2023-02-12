#include<bits/stdc++.h>
using namespace std;

const int N = 5e6;

vector<unsigned long long> phi(N + 1);

void phi_one_to_N(){

    for(int i = 0; i <= N; i++){
        phi[i] = i;
    }
    for(int i = 2; i <= N; i++){
        if(phi[i] == i){
            for(int j = 2*i; j <= N; j+=i){
                phi[j] *= i - 1;
                phi[j] /= i;
            }
                phi[i] = i - 1;
        }

        phi[i] = phi[i] + phi[i - 1]; //prefix sum if a range is given
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    phi_one_to_N();

    int t, a, b; cin >> t;
    for(int i=1; i <= t; i++){
        cin >> a >> b;

        cout << "Case " << i << ": ";
        cout << phi[b] - phi[a - 1] << endl;
    }
}





