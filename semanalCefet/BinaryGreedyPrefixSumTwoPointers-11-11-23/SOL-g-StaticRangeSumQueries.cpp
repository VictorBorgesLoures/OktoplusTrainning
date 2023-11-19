#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    long long v[N+1];
    v[0] = 0;
    for (int i = 1; i < N+1; i++)
    {
        cin >> v[i];
        if(i>0)
            v[i] += v[i-1];
    }
    
    while(Q > 0) {
        int a,b; cin >> a >> b;
        cout << v[b] - v[a-1] << '\n';
        Q--;
    }
    
}