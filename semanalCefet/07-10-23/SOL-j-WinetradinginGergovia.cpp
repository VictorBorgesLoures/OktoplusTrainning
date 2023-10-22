#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    while(N != 0) {
        vector<long long> v;
        int n;
        for (int i = 0; i < N; i++) {
            cin >> n;
            v.push_back(n);
        }
        long long sum = 0; long long atual = 0;
        for (int i = 0; i < N; i++)
        {
            atual += v[i];
            sum += abs(atual);
        }        
        cout << sum << '\n';
        cin >> N;
    }
    

    return 0;
}