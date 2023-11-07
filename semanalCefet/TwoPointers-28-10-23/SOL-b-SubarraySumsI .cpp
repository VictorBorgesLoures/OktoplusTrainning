#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; long long K; cin >> N >> K;
    long long v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int init = 0, fim = 0;    
    int count = 0;
    long long sum = 0;
    while(init < N && fim < N) {
        if(fim < N)
            sum+= v[fim];
        if(sum == K) {
            count++;
            fim++;
        } else if(sum < K) {
            if(fim == N)
                break;
            else {
               fim++;
            }
        } else {
            sum-=v[init];
            init++;
            if(fim < N)
                sum -= v[fim];
        }

    }
    cout << count << '\n';
    
    return 0;
}