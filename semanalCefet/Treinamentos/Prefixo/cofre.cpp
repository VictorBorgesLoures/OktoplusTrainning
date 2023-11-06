#include <bits/stdc++.h>

using namespace std;

int main() {
    int N,Q; cin >> N >> Q;
    int v[N];
    int freq[10] = {0}; long long pref[N+2] = {0};
    for (int i = 0; i < N; i++)
        cin >> v[i];

    int ant = 0, p;
    for (int i = 0; i < Q; i++)
    {
        cin >> p;
        if(p >= ant) {
            pref[ant+1]++;
            pref[p+1]--;
        } else {
            pref[ant]--;
            pref[p]++;
        }
        ant = p;
    }

    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += pref[i+1];
        freq[v[i]] += sum;
    }

    for (int i = 0; i < 10; i++)
        cout << freq[i] << " ";
    cout << '\n';
    
    
    return 0;
}