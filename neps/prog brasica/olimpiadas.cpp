#include <iostream>

using namespace std;

int main()
{

    int N, M;

    cin >> N >> M;
    int paises[N][3] = {0};

    for (int i = 0; i < N; i++)
    {
        paises[i][0] = 0;
        paises[i][1] = 0;
        paises[i][2] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int O, P, B;
        cin >> O >> P >> B;
        paises[O - 1][0]++;
        paises[P - 1][1]++;
        paises[B - 1][2]++;
    }

    int melhor;
    int coloc[N];
    for (int y = 0; y < N; y++)
       coloc[y] = -1;

    for (int c = 0; c < N; c++)
    {
        melhor = -1;
        for (int i = 0; i < N; i++)
        {
            int found = 0;
            for (int y = 0; y < N; y++)
            {
                if (coloc[y] == i)
                    found = 1;
            }
            if (!found)
            {
                if(melhor == -1) {
                    melhor = i;
                    continue;
                }
                if (paises[i][0] > paises[melhor][0])
                    melhor = i;
                else
                {
                    if (paises[i][0] == paises[melhor][0])
                        if (paises[i][1] > paises[melhor][1])
                            melhor = i;
                        else
                        {
                            if (paises[i][1] == paises[melhor][1])
                                if (paises[i][2] > paises[melhor][2])
                                    melhor = i;
                                else
                                {
                                    if (paises[i][2] == paises[melhor][2])
                                        if (i < melhor)
                                            melhor = i;
                                }
                        }
                }
            }
        }
        coloc[c] = melhor;
    }

    for (int i = 0; i < N; i++)
    {
        cout << coloc[i] + 1 << " ";
    }

    return 0;
}