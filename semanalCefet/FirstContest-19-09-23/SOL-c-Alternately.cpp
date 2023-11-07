#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    int n;
    cin >> n;
    getline(cin >> ws, S);

    for (int i = 0; i < n-1; i++)
    {        
        if(S[i] == S[i+1]) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}