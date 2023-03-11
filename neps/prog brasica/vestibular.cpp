#include <iostream>

using namespace std;

int main() {

    int N;
    cin >> N;
    char V1[N], V2[N];

    for (int i = 0; i < N; i++)
    {
        cin >> V1[i];
    }

    int C = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> V2[i];
        if(V1[i] == V2[i])
            C++;;
    }

    cout << C << endl;

    return 0;
}