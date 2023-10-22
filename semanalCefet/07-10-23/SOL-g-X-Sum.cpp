#include <bits/stdc++.h>

using namespace std;

int main() {
    //cin.tie(0);
    //ios_base::sync_with_stdio(false);
    int Q; cin >> Q;
    for (int T = 0; T < Q; T++)
    {
        int L, C; cin >> L >> C;
        int P[L+C-1] = {0};
        int S[L+C-1] = {0};
        int m[L][C];
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> m[i][j];
                //Colunas principais;
                if(i-j >= 0) {
                    P[i-j] += m[i][j];
                } else {
                    P[L-1 + abs(i-j)] += m[i][j];
                }
                //Colunas secundárias;
                S[i+j] += m[i][j];
            }  
        } 
        int bigger = 0;
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < C; j++)
            {
                int res = 0;
                res += S[i+j];
                res -= m[i][j];
                if(i-j >= 0) {
                    res += P[i-j];
                } else {
                    res += P[L-1 + abs(i-j)];
                }
                bigger = max(bigger, res);
            }
        }
        cout << bigger << '\n';          
    }
    
    return 0;
}