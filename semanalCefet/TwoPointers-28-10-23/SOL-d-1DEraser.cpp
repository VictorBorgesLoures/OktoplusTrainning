#include <bits/stdc++.h>

using namespace std;

int main() {
    int T; cin >> T;
    while(T> 0) {
        int N, K; cin >> N >> K;
        char v[N];
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int init = 0, fim = K-1;
        int count = 0;
        while(fim < N) {
            if(v[init] == 'B') {
                for (int i = init; i <= fim; i++)
                    v[i] = 'W';    
                count++;        
            }
            init++;
            fim++;
        }
        for (int i = N-K; i < N; i++)
        {
            if(v[i] == 'B') {
                count++;
                break;
            }
        }        
        cout << count << '\n';
        T--;
    }
}
