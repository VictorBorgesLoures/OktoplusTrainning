#include <iostream>

using namespace std;

int main() {

    int portas[2];

    cin >> portas[0] >> portas[1];

    if (portas[0] == 0)
        cout << "C" << endl;
    else {
        if(portas[1] == 1)
            cout << "A" << endl;
        else
            cout << "B" << endl;
    }

    return 0;
}