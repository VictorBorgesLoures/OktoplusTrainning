#include <iostream>
#include <map>

using namespace std;

int main() {

    int C, P;
    cin >> C >> P;
    map<int, int> instaladas;
    map<int, int> disponiveis;

    for (int i = 0; i < C; i++)
    {
        int v,q;
        cin >> v >> q;
        
        instaladas.insert(make_pair(v,q));
        instaladas[v] = q;
        
    }

    for (int i = 0; i < P; i++)
    {
        int v,q;
        cin >> v >> q;
        disponiveis.insert(make_pair(v,q));   
        disponiveis[v] = q;
        
    }

    pair<int, int> melhor = {0, 0};

    for (map<int ,int>::iterator it=instaladas.begin(); it!=instaladas.end(); ++it){
        if(disponiveis[it->first]) {
            if(disponiveis[it->first]> melhor.second) {
                melhor.first = it->first;
                melhor.second = disponiveis[it->first];
            }
        }
    }

    cout<< melhor.first<< " "<< melhor.second<< endl;

    return 0;
}