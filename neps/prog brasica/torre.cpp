#include <iostream>

using namespace std;

int main() {

    int D;
    cin >> D;
    int matriz[D][D];
    int pesos[D][D];

    for (int i = 0; i < D; i++)
    {
        for (int c = 0; c < D; c++)
        {
            cin >> matriz[i][c];
            pesos[i][c] = 0;
            pesos[i][c] -= matriz[i][c] *2;
        }
    }

    int maior = 0;
    int i=0,j=0;
    int lineWeight[D] = {0};
    int columnWeight[D] = {0};
    while(i < D) {
        lineWeight[i] += matriz[i][j];
        columnWeight[i] += matriz[j][i];
        j++;
        if (j == D) {         
            j=0;
            i++;
        }
    }

    for (int i = 0; i < D; i++)
    {
        for (int j = 0; j < D; j++)
        {
            pesos[i][j] += lineWeight[i];
            pesos[i][j] += columnWeight[j];
        }        
    }    

    i=0,j=0;
    while(i < D) {
        if(pesos[i][j] > maior)
            maior = pesos[i][j];

        j++;
        if (j == D) {
            j=0;
            i++;
        }
    }    

    cout << maior << endl;    

    return 0;
}