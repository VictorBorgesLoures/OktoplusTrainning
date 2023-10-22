#include <bits/stdc++.h>

using namespace std;

int main() {

    int N; cin >> N;
    int v[N] = {0};
    for (int i = 0; i < N-1; i++)
    {
        int n;
        cin >> n;
        v[n-1] = 1;
    }
    
    for (int i = 0; i < N; i++)
    {
        if(v[i] == 0) {
            cout << i+1 << endl;
            break;
        }
    }

    return 0;
}