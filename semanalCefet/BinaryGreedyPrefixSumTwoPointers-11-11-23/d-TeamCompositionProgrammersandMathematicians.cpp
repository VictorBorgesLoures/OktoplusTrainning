#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while(T > 0) {
        long long a, b; cin >> a >> b;
        if(a == 0 || b == 0 || a + b < 4)
            cout << "0\n";
        else if(a + b == 4) {
            cout << "1\n";
        } else if (a > b) {
            if(b > 1) {
                long long teams = 0;
                int v = 3;
                while(v>0 && a >0 && b >0) {
                    if(a/v > 0 && b/(4-v) >= a/v) {
                        b -= (a/v)*(4-v);
                        a -= (a/v) * v;
                        teams+= a/v;
                    }
                    v--;                    
                }
                       
                cout << teams << endl;
            } else {
                cout << "1\n";
            }
        } else if(a < b) {
            if(a > 1) {
                long long teams = 0;
                int v = 3;
                while(v>0 && a >0 && b >0) {
                    if(b/v > 0 && a/(4-v) > 0) {
                        b=b%v;
                        a=a%(4-v);
                        teams+= a/v;
                    }
                    v--;
                }
                       
                cout << teams << endl;
            } else {
                cout << "1\n";
            }
        } else {
            int qtdTeams = (a*2)/4;
            cout << qtdTeams << '\n';
        }
        T--;
    }
    
    return 0;
}