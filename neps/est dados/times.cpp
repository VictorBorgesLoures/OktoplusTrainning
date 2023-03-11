#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int N, T;
    cin >> N >> T;

    vector<pair<int, string>> jogadores;

    for (int i = 0; i < N; i++)
    {
        pair<int, string> jogador;
        cin >> jogador.second >> jogador.first;
        jogadores.push_back(jogador);
    }

    sort(jogadores.begin(), jogadores.end());

    vector<vector<string>> Times;
    for (int c = 0; c < T; c++)
    {
        vector<string> time;
        Times.push_back(time);
    }
    int contJogadores = N - 1;
    int c = 0;
    while (contJogadores >= 0)
    {
        Times[c].push_back(jogadores[contJogadores].second);
        contJogadores--;
        c++;
        if (c == T)
            c = 0;
    }

    for (int i = 0; i < Times.size(); i++)
        sort(Times[i].begin(), Times[i].end());

    for (int i = 0; i < Times.size(); i++)
    {
        cout << "Time " << i + 1 << endl;
        for (int j = 0; j < Times[i].size(); j++)
            cout << Times[i][j] << endl;
        cout << endl;
    }

    return 0;
}