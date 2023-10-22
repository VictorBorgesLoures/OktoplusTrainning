#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, SUM; cin >> N >> SUM;
    pair<int, int> v[N];
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i+1;
    }
    sort(v, v+N);
    pair<int, int> solve = {-1,-1};
    int fim = N-1;
    while(v[fim].first > SUM)
        fim--;
    int init = 0;
    while(init != fim && v[fim-1].first+v[fim].first >= SUM) {
        while(v[init].first+v[fim].first < SUM && init < fim-1) {
            init++;
        }
        if(v[init].first + v[fim].first == SUM) {
            solve.first = v[init].second; solve.second = v[fim].second;
            break;
        }     
        fim--;
        init = 0;
    }

    if(solve.first == -1)
        cout << "IMPOSSIBLE\n";
    else
        cout << solve.first << ' ' << solve.second << '\n';
    
    return 0;
}