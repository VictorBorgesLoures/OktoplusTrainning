#include <bits/stdc++.h>

using namespace std;

void exibir(vector<vector<int>> matriz) {
    for (int i = 0; i < 7; i++) {
        for (int c = 0; c < 7; c++)
            cout << matriz[i][c] << " ";
        cout << endl;
    }
}

vector<vector<int>> copyMatriz(vector<vector<int>> matriz) {
    vector<vector<int>> copia;
    for (int i = 0; i < 7; i++)
        copia.push_back(matriz[i]);
    return copia;
}
// DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURRUULDLLDDDD
// ??????R??????U??????????????????????????LD????D?
int solve(vector<vector<int>> matriz, string path, int passos, int l, int c) {
    int qtd = 0;
    if(matriz[6][0] == 1 || passos>21) {
        if(passos > 21) {
            //exibir(matriz);
            return 1;
        }
        return 0;
    }
    if(path[passos] == 'R') {
        if(c+1 < 7 && matriz[l][c+1] == 0) { // direita;
            //cout << "AQUI RIGHT" << endl;
            //vector<vector<int>> direita = copyMatriz(matriz);
            matriz[l][c+1] = 1;
            //exibir(direita);
            qtd += solve(matriz, path, passos+1, l, c+1);
        } else {
        //    cout << "Return RIGHT" << endl;
            return 0;
        }
    } else if(path[passos]== 'L') {
        if(c-1 >= 0 && matriz[l][c-1] == 0) { // esquerda;
            //cout << "AQUI LEFT: " << passos << endl;
            //vector<vector<int>> esquerda = copyMatriz(matriz);
            matriz[l][c-1] = 1;
            //exibir(esquerda);
            qtd += solve(matriz, path, passos+1, l, c-1);
        } else {
            return 0;
        }
    }else if(path[passos]== 'U') {
         if(l-1 >= 0 && matriz[l-1][c] == 0) { // cima;
            //cout << "AQUI UP" << endl;
            //vector<vector<int>> cima = copyMatriz(matriz);
            matriz[l-1][c] = 1;
            //exibir(cima);
            qtd += solve(matriz, path, passos+1, l-1, c);
        } else {
            return 0;
        }
    }else if(path[passos]== 'D') {
        if(l+1 < 7 && matriz[l+1][c] == 0) { // baixo;
            //cout << "AQUI Down" << passos << endl;
            //vector<vector<int>> baixo = copyMatriz(matriz);
            matriz[l+1][c] = 1;
            //exibir(baixo);
            qtd += solve(matriz, path, passos+1, l+1, c);
        } else {
            return 0;
        }
    } else {
        if(c+1 < 7 && matriz[l][c+1] == 0) { // direita;
           // cout << "AQUI ELSE DIR" << endl;
            //vector<vector<int>> direita = copyMatriz(matriz);
            matriz[l][c+1] = 1;
            //exibir(direita);
            qtd += solve(matriz, path, passos+1, l, c+1);
            matriz[l][c+1] = 0;
        } 

       // cout << "AQUI DEPOIS DO DIR" << endl;

        if(c-1 >= 0 && matriz[l][c-1] == 0) { // esquerda;
            //cout << "AQUI ELSE ESQ" << endl;
           // vector<vector<int>> esquerda = copyMatriz(matriz);
            matriz[l][c-1] = 1;
            //exibir(esquerda);
            qtd += solve(matriz, path, passos+1, l, c-1);
            matriz[l][c-1] = 0;
        }

        if(l-1 >= 0 && matriz[l-1][c] == 0) { // cima;
            //cout << "AQUI ELSE CIMA" << endl;
            //vector<vector<int>> cima = copyMatriz(matriz);
            matriz[l-1][c] = 1;
            //exibir(cima);
            qtd += solve(matriz, path, passos+1, l-1, c);
             matriz[l-1][c] = 0;
        }

        if(l+1 < 7 && matriz[l+1][c] == 0) { // baixo;
            //cout << "AQUI ELSE BAIXO: " << passos << endl;
            //vector<vector<int>> baixo = copyMatriz(matriz);
            matriz[l+1][c] = 1;
            //exibir(baixo);
            qtd += solve(matriz, path, passos+1, l+1, c);
            matriz[l+1][c] = 0;
        }
    }
    return qtd;
    
}

int main() {
    string entradas;
    getline(cin >>ws, entradas);
    vector<vector<int>> matriz;
    for (int i = 0; i < 7; i++) {
        vector<int> linha;
        for (int c = 0; c < 7; c++)
            linha.push_back(0);
        matriz.push_back(linha);
    }
    matriz[0][0] = 1;
    int resultado = solve(matriz, entradas, 0,0,0);
    cout << resultado << endl;

    return 0;
}

//DRURRRRRDDDLUULDDDLDRRURDDLLLLLURULURR??????????