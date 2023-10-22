#include <bits/stdc++.h>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;
    int t[m], freq[n]={0};
    vector<int> h;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        h.push_back(a);
    }
    
    for (int i = 0; i < m; i++)
        cin >> t[i];

    sort(h.begin(), h.end());    
    int i=0;
    while(i < m) {
        int menor = -1;
        int indice = 0;
        for (int c = 0; c < n; c++)
        {
            if(h[c] > t[i])
                break;
            else if(h[c] > menor && freq[c] == 0) {
                indice = c;
                menor = h[c];
            }
        }
        
        i++;
        cout << menor << endl;
        if(menor != -1)
            freq[indice] = 1;        
    }

    return 0;
}