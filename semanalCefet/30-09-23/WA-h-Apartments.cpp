#include <bits/stdc++.h>

using namespace std;
int buscab(pair<int, bool> *v, int n, int valor, int range) {
    int init = 0;
    int fim = n-1;
    while(init <= fim) {
        int mid = (init+fim) /2;
        if(v[mid].first <= valor+range && v[mid].first >= valor-range)
            return mid;
        else if(v[mid].first > valor) {
            fim = mid -1;
        } else {
            init = mid +1;
        }
    }
    return -1;
}
int main() {
    int N; cin >> N;
    int qtd, number, range;
    pair<int, bool> v[N]; cin >> qtd; cin >> range;
    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = false;
    }
    sort(v, v+N);
    int count = 0;
    for (int i = 0; i < qtd; i++)
    {
        cin >> number;
        int busca = buscab(v, N, number, range);
        
        count+=(busca == -1? 0 : 1);
    }
    cout << count << endl;
    

    return 0;
}