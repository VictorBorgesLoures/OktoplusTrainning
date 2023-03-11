#include <iostream>
#include <math.h>

using namespace std;

int main() {

    double X, Y;

    cin >> X >> Y;

    std::cout.precision(4);
    cout << std::fixed << pow(X, Y) << endl;

    return 0;
}