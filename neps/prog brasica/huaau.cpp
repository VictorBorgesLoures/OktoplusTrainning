#include <iostream>
#include <queue>

using namespace std;

int main() {

    string v;
    int engracada = 0;
    char vogals[5] = {'a','e','i','o','u'};
    
    cin >> v;
    queue<char> vols;
    queue<char> volsB;
    for (int i = 0; i < v.length(); i++)
    {
        for (int c = 0; c < 5; c++)
        {
            if(v[i] == vogals[c]) {
                vols.push(v[i]);
            }
        }
    }

    for (int i = v.length()-1; i >= 0; i--)
    {
        for (int c = 0; c < 5; c++)
        {
            if(v[i] == vogals[c]) {
                volsB.push(v[i]);
            }
        }
    }

    for (int i = 0; i < vols.size(); i++)
    {
        if(vols.front() != volsB.front()) {
            cout << "N" << endl;
            return 0;
        } else {
            vols.pop();
            volsB.pop();
        }

    }
    
    cout << "S" << endl;

    return 0;
}