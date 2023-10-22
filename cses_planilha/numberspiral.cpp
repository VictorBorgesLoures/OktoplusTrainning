#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int c = 0; c < n; c++)
    {
        long long i;
        cin >> i;
        long long j;
        cin >> j;
        if (j > i)
        {
            if (j % 2 != 0)
                cout << j * j - (i - 1) << endl;
            else
                cout << j * j - (2*j- i - 1) << endl;
        } else {
            if (i % 2 != 0)
                cout << i * i - (2*i- j - 1) << endl;
            else
                cout << i * i - (j - 1) << endl;
        }
    }

    return 0;
}