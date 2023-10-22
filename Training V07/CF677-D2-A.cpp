#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,h, pHeight, pathWidth = 0;
    cin >> n >> h;

    for (int i = 0; i < n; i++)
    {
        cin >> pHeight;
        int div = pHeight/h;
        pathWidth+= (div > 0 ? (pHeight%h > 0 ? div+1 : div) : 1);
    }
    
    cout << pathWidth << '\n';

    return 0;
}