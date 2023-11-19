#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a,b,c; cin >> a >> b >> c;
        if(a > b)
            cout << "First\n";
        else if(b > a) {
            cout << "Second\n";
        } else {
            if(c%2 == 0) {
                cout << "Second\n";
            } else {
                cout << "First\n";
            }
        }
    }
    
    
    return 0;
}