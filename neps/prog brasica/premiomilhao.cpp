#include <iostream>

using namespace std;

int main() {

    int N, A, D, C = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
       cin >> A;
       C += A;
       if (C >= 1000000) {
            D = i+1;
            break;
       }
    }
    
    cout << D;

    return 0;
}