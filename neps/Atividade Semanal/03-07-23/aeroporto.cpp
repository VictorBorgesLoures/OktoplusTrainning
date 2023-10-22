#include <bits/stdc++.h>

using namespace std;

int main() {

    int a,v, teste = 1, saida, chegada;
    cin >> a >> v;
    while(a!=0 && v != 0) {
        int freq[a] = {0};

        for (int i = 0; i < v; i++)
        {
            cin >> saida >> chegada;
            freq[--saida]++;
            freq[--chegada]++;
        }
        

        cout << "Teste " << teste++ << '\n';
        int maior = 0;
        for (int i = 1; i < a; i++)
            if(freq[maior] < freq[i])
                maior = i;
        for (int i = 0; i < a; i++)
            if(freq[maior] == freq[i])
                cout << i+1 << " ";
        cout << "\n";  
        cin >> a >> v;
        if(a != 0 && v!=0)
            cout << '\n';
    }

    return 0;
}