#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, L; cin >> N >> L;
    int lanters[N+2];
    lanters[0] = 0;
    lanters[N+1] = L;
    for (int i = 1; i < N+1; i++)
        cin >> lanters[i];
    sort(lanters, lanters+N+2);
    cout << fixed << setprecision(9);
    double maior = (double)(lanters[1] - lanters[0]);
    for (int i = 1; i < N; i++)
    {
        maior = max(maior, (double)(lanters[i+1] - lanters[i])/2);
    }
    maior = max(maior, (double)(lanters[N+1] - lanters[N]));
    cout << maior << endl;
    
    return 0;
}