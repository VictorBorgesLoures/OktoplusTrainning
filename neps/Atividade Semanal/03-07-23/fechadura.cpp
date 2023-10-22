#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, M, tam;
    cin >> N >> M;
    int fechadura[N];
    for (int i = 0; i < N; i++)
    {
        cin >> tam;
        fechadura[i] = tam;
    }

    int init = 0, end = N-1, movimentos=0;
    while(init < end) {
        while(fechadura[init] < M) {
            fechadura[init]++;
            fechadura[init+1]++;
            movimentos++; 
        }
        while(fechadura[init] > M) {
            fechadura[init]--;
            fechadura[init+1]--;
            movimentos++; 
        }

        while(fechadura[end] < M) {
            fechadura[end]++;
            fechadura[end-1]++;
            movimentos++; 
        }

        while(fechadura[end] > M) {
            fechadura[end]--;
            fechadura[end-1]--;
            movimentos++; 
        }
        init++;
        end--;
    }
    cout << movimentos << '\n';
    
    return 0;
}