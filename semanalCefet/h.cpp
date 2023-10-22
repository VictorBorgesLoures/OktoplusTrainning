#include <bits/stdc++.h>

using namespace std;
int buscab(int *v, int n, int valor, int range) {
    int init = 0;
    int fim = n-1;
    while(init <= fim) {
        int mid = (init+fim) /2;
        if(v[mid] <= valor+range && v[mid] >= valor-range)
            return mid;
        else if(v[mid] > valor) {
            fim = mid -1;
        } else {
            init = mid +1;
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int qtd, number, range, v[N]; cin >> qtd; cin >> range;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 0; i < qtd; i++)
    {
        cin >> number;
        cout << buscab(v, N, number, range) << endl;
        
    }
    

    return 0;
}