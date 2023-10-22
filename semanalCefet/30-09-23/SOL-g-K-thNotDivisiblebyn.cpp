#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        long long n, k; cin >> n >> k;
        long long div = k/(n-1);
        long long r = k%(n-1);
        if(r==0)
            cout << n*div-1 << endl;
        else 
            cout << n*div+r << endl;
    }
    
}