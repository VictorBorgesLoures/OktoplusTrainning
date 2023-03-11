#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    int values[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int c = 0; c < N; c++)
        {
            cin >> values[i][c];
        }
    }

    int sumLines[N] = {0};
    int sumColumns[N] = {0};
    int sumPrimaryDiag = 0;
    int sumSecondaryDiag = 0;

    for (int i = 0; i < N; i++)
    {
        for (int c = 0; c < N; c++)
        {
            sumLines[i] += values[i][c];
            if(i == c)
                sumPrimaryDiag += values[i][c];
            sumColumns[i] += values[c][i];
        }
        sumSecondaryDiag += values[i][N-i-1];
    }

    int sameSum = 1;

    for (int i = 0; i < N; i++)
    {     
        if(sumLines[i] != sumPrimaryDiag || sumColumns[i] != sumPrimaryDiag) {
            sameSum = 0;
            break;
        }
    }
    
    if(sameSum && sumPrimaryDiag == sumSecondaryDiag) {
        cout << sumPrimaryDiag << endl;
    } else
        cout << -1 << endl;

    return 0;
}