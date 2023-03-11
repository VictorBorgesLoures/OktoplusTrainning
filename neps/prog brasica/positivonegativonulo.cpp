#include <iostream>

using namespace std;

int main() {

    int n; 
    cin >> n;

    if (n > 0)
        cout << "positivo" << endl;
    else if(n < 0)
        cout << "negativo" << endl;
    else
        cout << "nulo" << endl;

    return 0;
}