#include <iostream>

using namespace std;

int main()
{

    int G, P, V;
    cin >> G >> P;

    while (G > 0 && P > 0)
    {

        int Pilotos[P] = {0};
        int grid[G][P] = {-1};
        for (int i = 0; i < G; i++)
        {
            for (int c = 0; c < P; c++)
            {
                cin >> V;
                grid[i][c] = V - 1;
            }
        }

        int K, K1, ponto;
        cin >> K;

        for (int i = 0; i < K; i++)
        {
            cin >> K1;
            for (int c = 0; c < K1; c++)
            {
                cin >> ponto;
                for (int t = 0; t < G; t++)
                {
                    Pilotos[grid[t][c]] += ponto;
                }
            }
            int maior = 0;
            for (int i = 1; i < P; i++)
            {
                if (Pilotos[i] > Pilotos[maior])
                    maior = i;
            }
            for (int i = 0; i < P; i++)
            {
                if (Pilotos[i] == Pilotos[maior])
                    cout << i + 1 << " - ";
            }
            cout << endl;
            for (int i = 0; i < P; i++)
            {
                Pilotos[i] = 0;
            }
        }

        cin >> G >> P;
    }

    return 0;
}