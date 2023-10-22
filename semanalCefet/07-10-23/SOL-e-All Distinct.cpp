#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        int S; cin >> S;
        int v[S];
        for (int c = 0; c < S; c++)
            cin >> v[c];
        sort(v, v+S);
        int count = 0;
        for (int i = 0; i < S-1; i++)
        {
            if(v[i] == v[i+1]) {
                count++;
            }
        }
        
        if(count%2 != 0)
            count++;
        
        cout << S-count << '\n';        
    }
    
    return 0;
}