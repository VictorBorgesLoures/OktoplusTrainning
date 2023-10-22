#include <bits/stdc++.h>
 
using namespace std;

bool sortTempos(int a, int b) {
    if(abs(a) < abs(b))
        return true;
    return false;
}
 
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    vector<int> tempos;
    int n, entrada, saida; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> entrada >> saida;
        tempos.push_back(entrada);
        tempos.push_back(-saida);
    }
 
    sort(tempos.begin(), tempos.end(), sortTempos);
    int maior = 1, idx = 1, maiorAtual = 1;
    while(idx < tempos.size()) {
        while(abs(tempos[idx-1]) == abs(tempos[idx]) && idx < tempos.size()) {
            maiorAtual--;
            idx++;
        }
        if(tempos[idx] > 0)
            maiorAtual++;
        else 
            maiorAtual--;
        maior = max(maior, maiorAtual);
        idx++;
    }
    maior = max(maior, maiorAtual);
    cout << maior << '\n';
    
    return 0;
}
