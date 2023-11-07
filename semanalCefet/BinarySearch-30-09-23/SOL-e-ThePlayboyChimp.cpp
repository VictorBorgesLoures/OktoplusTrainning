#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int l[N+1];
    l[0] = -1;
    for (int i = 1; i < N+1; i++)
        cin >>l[i];
    int Q, q; cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        cin >> q;
        int lb = *(lower_bound(l, l+N+1, q)-1);
        int up = *(upper_bound(l, l+N+1, q));
        if(lb == -1)
            cout << 'X';
        else
            cout << lb;
        if(up == *(l+N+1)) {
            cout << " X" << endl;
        } else
            cout << ' ' << up << endl;
    }

    return 0;
}

/*
4
1 4 5 7
4
4 6 8 10


4
1 4 5 7
4
3 6 8 10

4
3 4 5 7
4
2 6 8 10
*/