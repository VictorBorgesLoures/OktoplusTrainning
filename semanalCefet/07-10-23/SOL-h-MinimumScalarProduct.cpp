#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int caso = 1;
    for (int i = 0; i < N; i++)
    {
        int S, v;cin >> S;
        long long v1[S], v2[S];

        for (int c = 0; c < S; c++)
            cin >> v1[c];

        for (int c = 0; c < S; c++)
            cin >> v2[c];

        sort(v1, v1+S);       
        sort(v2, v2+S);
        int init = 0, end = S-1;
        long long sum = 0;
        while(init <= end) {
            sum += (v1[init] * v2[end-init]);
            init++;
        }

        cout << "Case #" << caso << ": " << sum << '\n';
        caso ++;        
    }  

    return 0;
}