#include <bits/stdc++.h>

using namespace std;

int main() {

    int N; cin >> N;
    int prev = 0, n;
    long long count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> n;
        if(n < prev) {
            count += prev-n;
            n = prev;
        }
        prev = n;
    }
    /*
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        v[i] = n;
        if(i > 0 && v[i] < v[i-1]) {            
            int resto = v[i-1]%v[i];
            int div = v[i-1]/v[i];
            count+= div*v[i] + resto - v[i];
            v[i]= div*v[i] + resto;
        }
    }
    */

    cout << count << endl;    

    return 0;
}