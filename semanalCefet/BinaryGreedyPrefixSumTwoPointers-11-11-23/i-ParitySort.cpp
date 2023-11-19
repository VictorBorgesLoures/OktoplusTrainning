#include <bits/stdc++.h>
 
using namespace std;
 
bool isSorted(int *v, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
            return false;
    }
    return true;
}
 
int main()
{
    int T;
    cin >> T;
    while (T > 0)
    {
        int N;
        cin >> N;
        int v[N];
        int firstOdd = N;
        int firstEven = N;
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            int att = i;
            int fim = (v[i] % 2 == 0 ? firstEven : firstOdd);
            for (int c = i - 1; c >= fim; c--)
            {
                if (((v[att] % 2 == 0 && v[c] % 2 == 0) || (v[att] % 2 != 0 && v[c] % 2 != 0)) && v[att] < v[c])
                {
                    swap(v[att], v[c]);
                    att = c;
                }
            }
            if (v[att] % 2 == 0)
            {
                firstEven = min(att, firstEven);
            }
            else
            {
                firstOdd = min(att, firstOdd);
            }
        }
        cout << (isSorted(v, N) ? "Yes\n" : "No\n");
 
        T--;
    }
    return 0;
}