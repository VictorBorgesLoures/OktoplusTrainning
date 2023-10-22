#include <bits/stdc++.h>
#include "quicksort/quicksort.h"

using namespace std;

//Gera um arquivo a partir de outros 2
void mesclar(string fileName1, string fileName2);
//Gera um arquivo de acordo com o máximo e mínimo informado
void gerarArquivo(string fileName,int qtd, int min, int max);
//Ordena um arquivo de forma decrescente
void decrescente(string fileName);
//Exibe os números de um arquivo binário
void exibir(string fileName);

//g++ ex03.cpp ./quicksort/quicksort.cpp;
int main() {
    srand(time(NULL));

    gerarArquivo("./dados/arq1.dat", 100, 1, 30);
    decrescente("./dados/arq1.dat");
    cout << "Conteúdo do arquivo 1: ";
    exibir("./dados/arq1.dat");
    
    gerarArquivo("./dados/arq2.dat", 100, 1, 30);
    decrescente("./dados/arq2.dat");
    cout << "Conteúdo do arquivo 2: ";
    exibir("./dados/arq2.dat");

    mesclar("./dados/arq1.dat", "./dados/arq2.dat");
    cout << "Conteúdo do arquivo 3: ";
    exibir("./dados/arq3.dat");

    return 0;
}

void gerarArquivo(string fileName, int qtd, int min, int max) {
    fstream arq;
    arq.open(fileName, ios::binary | ios::out);
    if(arq.is_open()) {
        for (int i = 0; i < qtd; i++)
        {
            int valor = min + (rand()%(max-min+1));
            arq.write((char*) &valor, sizeof(int));
        }
        
        arq.close();
    }
}

void exibir(string fileName) {
    fstream arq;
    arq.open(fileName, ios::binary | ios::in);
    if(arq.is_open()) {
        int valor;
        arq.read((char*) &valor, sizeof(int));
        while(arq.good()) {
            cout << valor << " ";
            arq.read((char*) &valor, sizeof(int));
        }

        arq.close();
    }
    cout << "\n";
}

void decrescente(string fileName) {
    fstream arq;
    arq.open(fileName, ios::binary | ios::in | ios::ate);
    if(arq.is_open()) {
        int tam = arq.tellg()/sizeof(int);
        arq.seekg(0);
        int v[tam];
        int valor;
        arq.read((char*) &valor, sizeof(int));
        int index = 0;
        while(arq.good()) {
            v[index] = valor;
            arq.read((char*) &valor, sizeof(int));
            index++;
        }
        
        quicksort(v, 0, tam-1);        
        arq.close();
        
        arq.open(fileName, ios::binary | ios::out );
        if(arq.is_open()) {
            index = 0;
            while(arq.good() && index < tam) {
                int vVetor = v[index];
                arq.write((char*) &vVetor, sizeof(int));
                index++;
            }
            arq.close();
        }            
    }
}

void mesclar(string fileName1, string fileName2) {
    fstream arq1, arq2, arq3;
    arq1.open(fileName1, ios::binary | ios:: in);
    arq2.open(fileName2, ios::binary | ios:: in);
    arq3.open("./dados/arq3.dat", ios::binary | ios:: out);
    if(arq1.is_open() && arq2.is_open() && arq3.is_open()) {
        int v1, v2, prev;
        arq1.read((char*) &v1, sizeof(int));
        arq2.read((char*) &v2, sizeof(int));
        if(arq1.good()) {
            prev = v1+1;
            if(arq2.good()) {
                if(v2 > v1)
                    prev = v2+1;
            }
        } else if(arq2.good())
            prev = v2+1;
        
        while(arq1.good() || arq2.good()) {
            if(arq1.good()) {
                if(arq2.good()) {
                    if(v1 > v2) {                    
                        if(prev != v1) {
                            prev = v1;
                            arq3.write((char*) &v1, sizeof(int));
                        }
                        arq1.read((char*) &v1, sizeof(int));                        
                    } else {
                        if(prev != v2) {
                            prev = v2;
                            arq3.write((char*) &v2, sizeof(int));
                        }
                        arq2.read((char*) &v2, sizeof(int));                        
                    }
                } else {
                    if(prev != v1) {
                        prev = v1;
                        arq3.write((char*) &v1, sizeof(int));
                    }
                    arq1.read((char*) &v1, sizeof(int));
                }
            } else {
                if(prev != v2) {
                    prev = v2;
                    arq3.write((char*) &v2, sizeof(int));
                }
                arq2.read((char*) &v2, sizeof(int));
            }
        }
        
        arq1.close();
        arq2.close();
        arq3.close();
    }
}