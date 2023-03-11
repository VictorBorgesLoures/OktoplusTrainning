#include <iostream>
#include <set>

using namespace std;

int main() {

    int A, B;
    cin >> A >> B;
    int cartasA[A];
    int cartasB[B];

    for (int i = 0; i < A; i++)
       cin >> cartasA[i];
    for (int i = 0; i < B; i++)
       cin >> cartasB[i];
    
    set<int> elementsA;

    for (int i = A-1; i >= 0; i--)
    {
        for (int c = B-1; c >= 0; c--)
        {
            if(cartasA[i] > cartasB[c]) {
                elementsA.insert(cartasA[i]);
                break;
            }
            if(cartasA[i] == cartasB[c])
                break;
            if(c == 0)
                elementsA.insert(cartasA[i]);
        } 
    }

    set<int> elementsB;
    for (int i = B-1; i>= 0; i--)
    {
        for (int c = A-1; c >= 0; c--)
        {
            if(cartasB[i] > cartasA[c]) {
                elementsB.insert(cartasB[i]);
                break;
            }
            if(cartasB[i] == cartasA[c])
                break;  
            if(c == 0)
                elementsB.insert(cartasB[i]);
                      
        } 
    }

     cout << (elementsA.size() > elementsB.size() ? elementsB.size() : elementsA.size()) << endl;

    return 0;
}