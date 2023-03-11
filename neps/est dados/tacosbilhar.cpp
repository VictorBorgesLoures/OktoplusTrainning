#include <iostream>
#include <set>

using namespace std;

int main() {

    int C, T;
    cin >> C;
    int fabricados = 0;
    set<int> tacosS;
    for (int i = 0; i < C; i++)
    {
        cin >> T;
        if(tacosS.find(T) != tacosS.end()) {
            tacosS.erase(T);
        } else {
            fabricados+= 2;
            tacosS.insert(T);
        }
    }

    cout << fabricados << endl;
    
    return 0;
}