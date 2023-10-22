#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, D=0, A=0;
    string jogos;
    cin >>n;
    getline(cin >> ws, jogos);
    for (int i = 0; i < n; i++)
    {
        if(jogos[i] == 'D')
            D++;
        else 
            A++;
    }

    if(D > A) {
        cout << "Danik" << '\n';
    } else if( A > D) {
        cout << "Anton" << '\n';
    } else {
        cout << "Friendship" << '\n';
    }
    

    return 0;
}