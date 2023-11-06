#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    pair<int, int> v[N];
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    int init = 0, fim = N-1;    
    sort(v, v+N);
    while(fim > init && v[init].first+v[fim].first != K) {
        if(v[init].first+v[fim].first > K) {
            fim--;
        } else {
            init++;
        }
    }

    if(v[init].first+v[fim].first == K && v[init].second != v[fim].second) {
        cout << v[init].second+1 << ' ' << v[fim].second+1 << '\n';
    } else 
        cout << "IMPOSSIBLE\n";
    
    return 0;
}