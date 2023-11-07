#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; cin >> T;
    while(T> 0) {
        int N, K; cin >> N >> K;
        long long v[N], prefix[N], prefix2[N];
        for (int i = 0; i < N; i++)
            cin >> v[i];
        prefix[0] = v[0];
        for (int i = 1; i < N; i++)
            prefix[i] = prefix[i-1] + v[i];
        for (int i = 0; i < K+1; i++) {
            prefix2[i] = prefix[i];
        }
        long long maior = prefix[K-1];
        for (int i = K; i < N; i++)
        {
            prefix2[i] = prefix[i] - prefix[i-K];
            maior = max(maior, prefix2[i]);
        }
        cout << maior<< endl;
        T--;
    }

    return 0;
}