#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N; cin >> N;
    long long v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 1; i < N; i++)
        v[i] += v[i-1];
    
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        long long rest = v[i]%N;
        if(rest == 0)
            count++;
        else if(v[i] > N) {
            auto it = upper_bound(v, v+N, rest);
            int count2 = 1;
            while(*it == rest) {
                it--;
                count2++;
            }
            if(*it == rest)
                count++;
        }
    }

    cout << count << '\n';  

    return 0;
}
