#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q; cin >> N >> Q;
    long long dorm[N+1];
    dorm[0] = 0;
    for (int i = 1; i < N+1; i++)
    {
        cin >> dorm[i];
        dorm[i]+=dorm[i-1];
    }
    
    long long deliver;
    int at = 0;
    for (int i = 0; i < Q; i++)
    {
        cin >> deliver;
        /*
        if(deliver > dorm[at]) {
            at = lower_bound(dorm, dorm+N, deliver)-dorm; // 1559 ms
        }
        */
        while(deliver > dorm[at]) { // 1528 ms
            at++;
        }
        cout << at << " " << deliver - dorm[at-1] << endl;
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