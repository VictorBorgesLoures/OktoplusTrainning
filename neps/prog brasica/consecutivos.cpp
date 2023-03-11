#include <iostream>

using namespace std;

int main() {

    int N, V, P = 0, tempV, tempP = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> V;
        if(tempV != V) {
            tempP = 0;
            tempV = V;
        }
        tempP++;
        if (tempP > P)
            P = tempP;
    }

    cout << P << endl;
    

    return 0;
}