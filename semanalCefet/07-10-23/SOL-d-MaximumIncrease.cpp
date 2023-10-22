#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int count = 1, maxCount = 1, prev, atual; cin >> prev;
    for (int i = 1; i < N; i++)
    {
        cin >> atual;
        if(atual > prev) {
            count++;
        } else {
            maxCount = max(maxCount, count);
            count = 1;
        }

        prev = atual;
    }
    maxCount = max(maxCount, count);
    cout << maxCount << '\n';
    
    return 0;
}