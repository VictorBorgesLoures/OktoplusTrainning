#include <iostream>

using namespace std;

int main() {

    int N, P, L;
    cin >> N;
    int pessoas[N];

    for (int i = 0; i < N; i++)
    {
        cin >> pessoas[i];
    }

    cin >> L;

    for (int i = 0; i < L; i++)
    {
        cin >> P;
        for (int t = 0; t < N-i; t++)
        {
            if(pessoas[t] == P) {
                for (int c = t; c < N-i; c++)
                {
                    pessoas[c] = pessoas[c+1];
                }
                break;
            }
        }
        
    }
    
    for (int i = 0; i < N - L; i++)
    {
        cout << pessoas[i] << " ";
    }

    return 0;
}