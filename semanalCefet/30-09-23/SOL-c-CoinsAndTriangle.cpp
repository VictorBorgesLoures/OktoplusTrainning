#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; int T;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T;
        int qtd = 0;
        int row = 1;
        while(qtd + row <= T) {
            qtd += row;
            row ++;
        }
        cout << row-1 << endl;
    }
    
    return 0;
}