#include <bits/stdc++.h>

using namespace std;

int main() {
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
                if(j-i >= 0)
                    P[j-i] += m[i][j];
                else 
                    P[C-1 + abs(j-i)] += m[i][j];

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
                if(j-i >= 0)
                    res += P[j-i];
                else
                    res += P[C-1 + abs(j-i)];

                bigger = max(bigger, res);
            }
        }
        cout << bigger << '\n';          
    }
    
    return 0;
}