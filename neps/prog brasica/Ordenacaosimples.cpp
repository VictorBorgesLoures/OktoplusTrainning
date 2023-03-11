#include <iostream>

using namespace std;

int menorCrescente(int N, int vet[], int init) {
    if (init +1 > N)
        return 0;
    int menor = vet[init];
    int mIndex = init;
    for (int i = init+1; i < N; i++)
        if(vet[i] < menor) {
            menor = vet[i];
            mIndex = i;
        }
    int temp = vet[init];
    vet[init] = menor;
    vet[mIndex] = temp;
    cout << menor << " ";
    menorCrescente(N, vet, init+1);
    return 0;
}

int main() {

    int N;
    cin >> N;
    int numbers[N];
    for (int i = 0; i < N; i++)
        cin >> numbers[i];
    
    menorCrescente(N, numbers, 0);    

    return 0;
}