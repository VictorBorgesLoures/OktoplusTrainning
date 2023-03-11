#include <iostream>
#include <set>

using namespace std;

int main() {

    int N, P;
    cin >> N;
    int presencas[N];
    set<int> s;
    int c = 0;
    for (int i = 0; i < N; i++) {
        cin >> P;
        s.insert(P);
    }

    cout << s.size() << endl;    

    return 0;
}