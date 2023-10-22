#include <bits/stdc++.h>
#include "hash/hash.h"

using namespace std;

//g++ ex02.cpp ./hash/hash.cpp;
int main() {

    int* vetorHash = inicialiar();
    int colisoes = inserir(vetorHash, 14);
    //cout << "Colisão 14: " << colisoes << endl;
    colisoes = inserir(vetorHash, 9);
    //cout << "Colisão 9: " << colisoes << endl;
    colisoes = inserir(vetorHash, 15);
    //cout << "Colisão 15: " << colisoes << endl;
    colisoes = inserir(vetorHash, 22);
    //cout << "Colisão 22: " << colisoes << endl;
    colisoes = inserir(vetorHash, 26);
    //cout << "Colisão 26: " << colisoes << endl;
    colisoes = inserir(vetorHash, 13);
    //cout << "Colisão 13: " << colisoes << endl;
    colisoes = inserir(vetorHash, 1);
    //cout << "Colisão 1: " << colisoes << endl;
    colisoes = inserir(vetorHash, 16);
    //cout << "Colisão 16: " << colisoes << endl;
    colisoes = inserir(vetorHash, 18);
    //cout << "Colisão 18: " << colisoes << endl;
    colisoes = inserir(vetorHash, 17);
    //cout << "Colisão 17: " << colisoes << endl;
    colisoes = inserir(vetorHash, 19);
    //cout << "Colisão 19: " << colisoes << endl;
    colisoes = inserir(vetorHash, 20);
    //cout << "Colisão 20: " << colisoes << endl;

    exibir(vetorHash);

    cout << (buscar(vetorHash, 13) ? "Achou o 13" : "Não achou o 13") << endl;
    remover(vetorHash, 13);
    cout << (buscar(vetorHash, 13) ? "Achou o 13" : "Nao achou o 13") << endl;

    exibir(vetorHash);


    free(vetorHash);
    vetorHash = NULL;

    return 0;
}