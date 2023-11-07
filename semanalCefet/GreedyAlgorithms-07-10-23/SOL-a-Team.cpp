#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int v;
    int count, mCount = 0;
    for (int i = 0; i < N; i++) {
        count = 0;
        for (int c = 0; c < 3; c++)
        {
            cin >> v;
            if(v == 1)
                count++;
        }
        if(count > 1) {
            mCount++;
        }
    }

    cout << mCount << '\n';        
        
    
    return 0;
}