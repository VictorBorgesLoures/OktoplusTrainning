#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, Q; cin >> N >> Q;
    unsigned long long v[N+1];
    v[0] = 0;
    for (int i = 1; i < N+1; i++)
        cin >> v[i];

    for (int i = 2; i < N+1; i++)
        v[i] += v[i-1];
       
    for (int i = 0; i < Q; i++)
    {
        int a, b; cin >> a >> b;
        cout << v[b] - v[a-1] << endl;
    }
    

    return 0;
}