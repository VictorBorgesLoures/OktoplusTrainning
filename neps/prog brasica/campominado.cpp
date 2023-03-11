#include <iostream>

using namespace std;

int main()
{

    int N;
    cin >> N;
    int vet[N];
    int bomb[N];
    for (int i = 0; i < N; i++)
    {
        cin >> vet[i];
        bomb[i] = 0;
    }

    for (int i = 0; i < N; i++)
    {
        if (vet[i] == 1)
        {
            if (i - 1 >= 0)
                bomb[i - 1]++;
            bomb[i]++;
            if (i + 1 < N)
                bomb[i + 1]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << bomb[i] << endl;
    }

    return 0;
}