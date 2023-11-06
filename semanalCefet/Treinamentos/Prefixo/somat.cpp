#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, K; cin >> N >> K;
    int v[N+1], prefix[N+1];
    for (int i = 1; i < N+1; i++)
        cin >> v[i];
    
    prefix[0] = -K;
    for (int i = 1; i < N+1; i++)
    {
        if(v[i] > K) // i==7
            prefix[i] = -K;
        else {
            prefix[i] = prefix[i-1]+v[i];
            if(prefix[i] > 0) {
                prefix[i] = -K+v[i];
            }
            if(v[i] == K)
                prefix[i] = K+1;
        }
    }
    long long count = 0, qtd=0;
    for (int i = 1; i < N+1; i++) {
        if(prefix[i] == 0 && K != 0)
            count++;
        else if(prefix[i] == K+1) {
            qtd++;
        }
        if(i+1 < N+1 && prefix[i+1] != K+1 && qtd > 0) {
            for (long long c = 1; c <= qtd; c++)
                count+=c;            
            qtd=0;
        }
    }
    if(qtd > 0) {
        for (int c = 1; c <= qtd; c++)
            count+=c;  
    }
    cout << count << endl;


    return 0;
}