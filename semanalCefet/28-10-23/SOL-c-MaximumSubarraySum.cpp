#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N; cin >> N;
    long long v[N], prefix[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    prefix[0] = v[0];
    long long maior = prefix[0];
    for (int i = 1; i < N; i++) {
        if(v[i] > prefix[i-1] + v[i]) {
            prefix[i] = v[i]; 
        } else {
            prefix[i] = v[i] + prefix[i-1];
        }
        maior = max(maior, prefix[i]);
    }
    
    cout << maior;
    return 0;
}