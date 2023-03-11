#include <iostream>

using namespace std;

int main() {

    char O;
    cin >> O;

    double v1,v2;

    cin >> v1 >> v2;

    std::cout.precision(2);

    if(O == 'M') {
        cout << std::fixed << v1 * v2 << endl;
    } else {
        cout << std::fixed << v1 / v2 << endl;
    }

    return 0;
}