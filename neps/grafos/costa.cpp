#include <bits/stdc++.h>

using namespace std;

int main() {

    int M, N;
    char C;
    cin >> M >> N;
    char mapa[M][N];
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> C;
            mapa[i][j] = C;
        }

    int contador = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(mapa[i][j] == '#') {
                char esq, dir, cima, baixo;
                esq = (j-1 < 0 ? '.' : mapa[i][j-1]);
                dir = (j+1 == N ? '.' : mapa[i][j+1]);
                cima = (i-1 < 0 ? '.' : mapa[i-1][j]);
                baixo = (i+1 == M ? '.' : mapa[i+1][j]);
                if(esq == '.' 
                || dir == '.' 
                || cima == '.' 
                || baixo == '.')
                    contador++;
            }
        
        }
        
    }

    cout << contador << '\n';    

    return 0;
}