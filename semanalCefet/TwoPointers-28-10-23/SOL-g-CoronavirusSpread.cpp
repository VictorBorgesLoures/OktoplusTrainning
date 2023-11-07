#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int N;
        cin >> N;
        int v[N];
        for (int i = 0; i < N; i++)
            cin >> v[i];
        int count = 1; int small = N, big = 1;
        for (int i = 1; i < N; i++)
        {
            if(v[i]-v[i-1] <= 2) {
                count++;
            } else {
                small = min(small, count);
                big = max(big, count);
                count = 1;
            }
        }
        
        cout << min(small, count) << " " << max(big, count) << '\n';
            
        T--;
    }
}