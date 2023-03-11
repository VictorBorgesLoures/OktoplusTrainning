#include <iostream>
#include <math.h>

using namespace std;

int main() {

    int N;
    double V;
    cin >> N;

    std::cout.precision(4);

    for (int i = 0; i < N; i++)
    {
        cin >> V;
        double raiz = pow(V, 0.5);
        cout << std::fixed << raiz << endl;
    }    

    return 0;
}