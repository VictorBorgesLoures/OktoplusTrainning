#include <iostream>

using namespace std;

int main() {

    int N;
    int C = 0;

    int B[2];
    cin >> N;
    for(int i=0; i < N;i++) {
        cin >> B[0] >> B[1];
        if (B[0] > B[1])
            C += B[1];
    }

    cout << C << endl;


    return 0;
}