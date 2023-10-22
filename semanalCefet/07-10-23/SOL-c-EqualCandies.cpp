#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;cin >> N;
    for (int i = 0; i < N; i++)
    {
        int QTDBoxes; cin >> QTDBoxes;
        unsigned long long sum = 0; int menor = INT_MAX, v;
        for (int i = 0; i < QTDBoxes; i++) {
            cin >> v;
            sum += v;
            menor = min(menor, v);
        }
        sum -= QTDBoxes*menor;
        cout << sum << '\n';
        
    }
    
    
    return 0;
}