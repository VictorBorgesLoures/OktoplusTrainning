#include <iostream>

using namespace std;

int main() {

    int N, M, T, A, B;
    cin >> N >> M;
    int ilhas[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            ilhas[i][j] = 0;
   
    for (int i = 0; i < M; i++)
    {
        cin >> T >> A >> B;
        --B;
        --A;
        if(T == 1) {
            ilhas[A][B] = 1;
            ilhas[B][A] = 1;
        } else {
            if(ilhas[A][B] == 1 && ilhas[B][A] == 1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
    }
    return 0;
}