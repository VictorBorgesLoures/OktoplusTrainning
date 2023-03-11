#include <iostream>

using namespace std;

int main() {
    int N, P, Q;
    char O;

    cin >> N;
    cin >> P;
    cin >> O;
    cin >> Q;

    if(O == '+') {
        if(P+Q > N)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    } else {
        if(P*Q > N)
            cout << "OVERFLOW" << endl;
        else
            cout << "OK" << endl;
    }

    return 0;
}
