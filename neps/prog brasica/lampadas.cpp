#include <iostream>

using namespace std;

int main() {

    int N, S, A = 0, B = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> S;
        if (S == 1)
            A == 0 ? A = 1 : A = 0;
        else if (S == 2) {
            A == 0 ? A = 1 : A = 0;
            B == 0 ? B = 1 : B = 0;
        }
    }

    cout << A << endl;
    cout << B << endl;    

    return 0;
}