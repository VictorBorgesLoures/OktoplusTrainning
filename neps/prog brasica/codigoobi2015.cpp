#include <iostream>

using namespace std;

int main() {

    int N, V, seqTemp, zeroCount = 0, Count = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> V;
        if (V == 1) {
            seqTemp = V;
            zeroCount = 0;
        }
        else if( V == 0) {
            if (seqTemp == 1)
                zeroCount++;
        }

        if (zeroCount == 2) {
            Count++;
            zeroCount = 0;
            seqTemp = 0;
        }
    }

    cout << Count << endl;
    
    return 0;
}