#include <bits/stdc++.h>

using namespace std;

int main()
{
    int qtdConsultas, entrada, saida, ultimaSaida, conflitos = 0;
    queue<pair<int, int>> consultas;
    cin >> qtdConsultas;
    for (int i = 0; i < qtdConsultas; i++)
    {
        cin >> entrada >> saida;
        consultas.push(make_pair(entrada, saida));
    }
    pair<int, int> atual; atual=consultas.front(); consultas.pop();
    while(!consultas.empty()) {
        pair<int, int> prox; prox=consultas.front(); consultas.pop();
        if(prox.first == atual.first) {
            conflitos++;
            if(prox.second < atual.second)
                atual = prox;
            continue;
        } 
        if(prox.first < atual.second)
            conflitos++;
        else
            atual = prox;
    }
    
    cout << qtdConsultas - conflitos << endl;

    return 0;
}