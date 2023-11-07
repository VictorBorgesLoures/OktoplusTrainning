#include <bits/stdc++.h>

using namespace std;

int main() {
    int Q; cin >> Q;
    short v1[Q], v;
    int dif1 = 0, dif2 = 0;
    for (int i = 0; i < Q; i++)
    {
        cin >> v1[i];
        if(v1[i] == 1)
            dif1++;
    }
    for (int i = 0; i < Q; i++)
    {
        cin >> v;
        if(v == 1){
            if(v == v1[i])
                dif1--;
            else
                dif2++;
        }
    }

    if(dif1 == 0)
        cout << -1 << endl;
    else {
        cout << ((dif2 / dif1) +1) << endl;
    }   
    
}

/*
8
1 0 0 0 0 0 0 1
0 1 0 1 1 1 1 0
*/