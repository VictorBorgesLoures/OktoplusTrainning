#include <iostream>

using namespace std;

int find(int x, int *v) {
    if(v[x] != x) {
        int p = find(v[x], v);
        v[x]=p;
        return p;
    } else
        return x;
}

int fusao(int x, int y, int *v) {
    int px = find(x, v);
    int py = find(y, v);
    if(px > py) {
        v[y] = px;
    } else {
        v[x] = py;
    }

    return 0;
}

int main() {

    int N, K;
    cin >> N >> K;
    int bancos[N];

    for (int c = 0; c < N; c++)
        bancos[c] = c;   
    
    for (int i = 0; i < K; i++)
    {
        int e,s;
        char O;
        cin >> O >> e >> s;
        e--; s--;
        if(O == 'C') {
            if(find(s, bancos) == find(e, bancos)) {
                cout << "S" << endl;
            } else {
                cout << "N" << endl;
            }
        } else {
            fusao(e,s,bancos);
        }
    }
    
    

    return 0;
}