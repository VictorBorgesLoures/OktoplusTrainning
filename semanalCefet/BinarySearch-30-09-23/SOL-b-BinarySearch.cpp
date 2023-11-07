#include <bits/stdc++.h>

using namespace std;
int buscab(int *v, int n, int valor) {
    int init = 0;
    int fim = n-1;
    while(init <= fim) {
        int mid = (init+fim) /2;
        if(v[mid] == valor)
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
    int qtd, number, v[N]; cin >> qtd;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 0; i < qtd; i++)
    {
        cin >> number;
        int pos = buscab(v, N, number);
        while(pos > 0 && v[pos] == v[pos-1])
            pos--;
        cout << pos << '\n';
        
    }   

    return 0;
}

/*
LOWER_BOUND
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    int qtd, number, v[N]; cin >> qtd;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    for (int i = 0; i < qtd; i++)
    {
        cin >> number;
        auto pos = lower_bound(v, v+N, number);      
        cout << ((*pos != number || pos == v+N) ? -1 : pos-v)<< '\n';
    }    

    return 0;
}
*/