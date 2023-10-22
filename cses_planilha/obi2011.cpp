#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int p[n], c = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int aux = p[0];
    int cS = 0;
    for (int i = 1; i < n; i++)
    {
        if (p[i] < aux)
        {
            cS++;
        }
        else
        {
            aux = p[i];
            c += cS;
            cS = 0;
        }
    }
    if(cS > 0) {
        cS = 0;
        int lastMax = aux;
        int i = 1;
        aux = p[n - i];
        for (++i; i < n; i++)
        {
            if (p[n-i] < aux)
            {
                cS++;
            }
            else
            {
                aux = p[n-i];
                c += cS;
                cS = 0;
            }
            if (aux == lastMax) break;
        }
    }    

    cout << c << "\n";
    return 0;
}