#include <iostream>
#include <algorithm>

using namespace std;

bool verificar_caixa(pair<int, int> *c, int n, int entrada, int saida);

int main() {

    int C, N, E, S, count = 0;
    cin >> C >> N;
    int currentTime = 0;
    pair<int, int> caixas[C];
    for (int i = 0; i < C; i++)
        caixas[i] = make_pair(0,0);    

    for (int k = 0; k < N; k++)
    {
        cin >> E >> S;
        if(verificar_caixa(caixas, C, E, S)) count++;
    }

    cout << count << endl;

    return 0;
}

bool verificar_caixa(pair<int, int> *c, int n, int entrada, int saida) {

    for (int i = 0; i < n; i++)
    {
        if(entrada >= (c[i].first + c[i].second)) {
            cout << "Entrando no caixa: " << c[i].first << " : " << c[i].second << endl;
            c[i].first = entrada;
            c[i].second = saida;
            cout << "Novo horário: " << c[i].first << " : " << c[i].second << endl;
            return false;
        }
    }

    sort(c, c+n);

    bool passouTempo = false;

    if((c[0].first + c[0].second) > (entrada +20)) {
        cout << "PASSOU O TEMPO" << endl;
        passouTempo = true;
    }
    cout << "Entrando no caixa: " << c[0].first << " : " << c[0].second << endl;
    c[0].first = c[0].first  + c[0].second;
    c[0].second = saida;
    cout << "Novo horário: " << c[0].first << " : " << c[0].second << endl;
    return passouTempo;

}