#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, num; cin >> N;
    pair<int, int> numeros[N];
    cin >> num;
    numeros[0] = make_pair(num, -1);
    cout << 0 << " ";
    for (int i = 1; i < N; i++)
    {
        cin >> num;
        numeros[i] = make_pair(num, -1);
        int imp = -1;
        for (int c = i-1; c >= 0; c--)
        {
            if(numeros[i].first > numeros[c].first) {
                imp = c;
                numeros[i].second = c;
                break;
            } else {
                if(numeros[c].second == -1)
                    break;
                else {
                    c = numeros[c].second+1;
                }
            }
        }        

        cout << (imp == -1 ? 0 : imp+1) << " ";
    }
    cout << '\n';
    
    return 0;
}