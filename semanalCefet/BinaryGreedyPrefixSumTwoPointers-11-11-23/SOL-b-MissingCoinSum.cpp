#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    long long v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    sort(v, v + N);
    long long value = 0;
    for (int i = 0; i < N; i++)
    {
        if(value+1 < v[i]) {
            break;
        } else 
            value += v[i];
    }
     
    cout << value+1 << endl;    
    return 0;
}