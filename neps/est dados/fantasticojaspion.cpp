#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int T;
    cin >> T;
    vector<pair<string, string>> dicionario;
    for (int i = 0; i < T; i++)
    {
        int M, N;
        cin >> M >> N;
        for (int c = 0; c < M; c++)
        {
            string key, trad;
            cin >> key;
            cin.ignore();
            getline(cin, trad);
            dicionario.push_back(make_pair(key, trad));
        }

        for (int c = 0; c < N; c++)
        {
            string frase;
            getline(cin, frase);
            int s = 0;
            string temp = "";
            vector<string> palavras;
            while(frase[s] != '\0') {
                if(frase[s] != ' ')
                    temp += frase[s];
                else {
                    palavras.push_back(temp);
                    temp = "";
                }
                s++;
            }
            palavras.push_back(temp);
            string fraseToP = "";
            int pSize = palavras.size();
            for (int q = 0; q < pSize; q++)
            {
                string p = palavras[q];
                int found = 0;
                for (int k = 0; k < dicionario.size(); k++)
                {
                    if(dicionario[k].first == p) {
                        fraseToP+= dicionario[k].second;
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    fraseToP += p;
                }
                fraseToP += " ";
            }
            
           cout << fraseToP << endl;
        }
       cout << endl;
    }

    return 0;
}