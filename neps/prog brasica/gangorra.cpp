#include <iostream>

using namespace std;

int main() {

    int v1[2], v2[2];

    cin >> v1[0] >> v1[1] >> v2[0] >> v2[1];

    if (v1[0] * v1[1] == v2[0] * v2[1])
        cout << 0 << endl;
    else {
        if(v1[0] * v1[1] < v2[0] * v2[1])
            cout << 1 << endl;
        else 
            cout << -1 << endl;
    }    

    return 0;
}