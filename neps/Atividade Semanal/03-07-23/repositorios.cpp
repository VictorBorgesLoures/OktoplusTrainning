#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int C, N, numero, versao;
    cin >> C >> N;
    vector<pair<int, int>> pComp;
    for (int i = 0; i < C; i++)
    {
        cin >> numero >> versao;
        pComp.push_back(make_pair(numero, versao));
    }
    for (int i = 0; i < N; i++)
    {
        cin >> numero >> versao;
        bool found = false;
        for (int c = 0; c < pComp.size(); c++)
        {
            if (pComp[c].first == numero)
            {
                pComp[c].second = (pComp[c].second < versao ? versao : pComp[c].second);
                found = true;
                break;
            }
        }
        if (!found)
            pComp.push_back(make_pair(numero, versao));
    }

    for (int i = 0; i < pComp.size(); i++)
    {
        cout << pComp[i].first << ' ' << pComp[i].second << '\n';
    }

    return 0;
}