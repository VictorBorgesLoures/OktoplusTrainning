#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,l,c, steps = 0;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            cin >> n;
            if(n == 1) {
                l = i;
                c = j;
                break;
            }
        }
    }

    cout << abs(l-3)+abs(c-3) << endl;

    return 0;
}