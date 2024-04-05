int main() {

    int n,ans;
    cin >> n;
 
 
    if(n % 2 == 0 && (n / 2) % 2 == 0){
        cout << n / 2 << " " << n / 2 << endl;
    }
    else if(n % 2 == 0 && (n/2) % 2 != 0){
        cout << n / 2 - 1 << " " << n / 2 + 1 << endl;
    }
 
    else if(n % 2 != 0){
 
       ans = 3 * (3 + 2 * (n / 10 - 1)); // :))))))))))))))))
 
       cout << n - ans << " " << ans << endl;
    }
 
 }
