#include <iostream>

using namespace std;

int main() {
    double notas[2];

    cin >> notas[1] >> notas[0];

    double media = (notas[0] + notas[1]) / 2;

    if(media >= 7 )
        cout << "Aprovado" << endl;
    else if(media < 7 && media >= 4)
        cout << "Recuperacao" << endl;
    else
        cout << "Reprovado" << endl;

    return 0;
}