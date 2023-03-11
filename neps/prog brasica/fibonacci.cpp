#include <iostream>

using namespace std;

int fibonacci(int x) {
    if( x <= 1 )
        return 1;
    else
        return fibonacci(x-1) + fibonacci(x-2);
}

int main() {

    int V;
    cin >> V;
    cout << fibonacci(V) << endl; 

    return 0;
}