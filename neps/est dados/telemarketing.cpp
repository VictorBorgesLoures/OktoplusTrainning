#include <iostream>

using namespace std;

int main() {

    int N, L;

    cin >> N >> L;
    int ligacoes[L];

    for (int i = 0; i < L; i++)
    {
        int t;
        cin >> t;
        ligacoes[i] = t;
    }
    
    return 0;
}