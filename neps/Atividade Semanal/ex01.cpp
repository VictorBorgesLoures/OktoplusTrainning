#include <bits/stdc++.h>
#include "abb/abb.h"

using namespace std;

//g++ ex01.cpp ./abb/abb.cpp;
int main() {

    no* raiz = criar(30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 32);
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 23);
    raiz = inserir(raiz, 31);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 12);
    raiz = inserir(raiz, 22);
    raiz = inserir(raiz, 37);
    raiz = inserir(raiz, 45);

    percorrer(raiz); // Em ordem;
    cout << "\n";
    largura(raiz); // Pré-ordem;    //A: Este percurso não é em pré-ordem

    //A: Faltou desconsiderar a raiz no cômputo dos nós internos
    int qtdNosInternos = internos(raiz);
    cout << "\nQuantidade de nós internos: " << qtdNosInternos;
    int qtdNumerosImpares = qtde_impares(raiz);
    cout << "\nQuantidade de númeos ímpares: " << qtdNumerosImpares << endl;

    return 0;
}