#include <bits/stdc++.h>

using namespace std;

int main() {

    int N, K; cin >> N >> K;
    int v[N];
    for (int i = 0; i < N; i++)
        cin >> v[i];
    
    int value = K;
    int init=0, fim =0, c=0;
    while(fim < N) {
        value -= v[fim];
        cout << "Value: " << value << endl;
        cout << init << " : " << fim << endl;
        if(v[fim] == K) {
            if(value == 0) { // qtd k == 0 e value == 0, varios zeros em sequencia
                if(init != fim && ((fim < N-1 && v[fim+1] != K ) || fim+1 == N) ) { // proximo valor diferente de zero
                    cout << "AQUI: ";
                    int qtd = fim - init;
                    c-= qtd;
                    cout << c;
                    for (int q = 1; q <= qtd+1; q++)
                        c+= q;
                    cout << " > " << c;
                    cout << '\n';
                    fim++;
                    init = fim;
                } else {
                    fim++;
                    c++;
                }
            } else {
                // value < 0
                value += v[init++];
            }
        
        } else {
            if(value == 0) {
                fim++;
                c++;
            } else if(value > 0) {
                fim++;
            } else { // value < 0, passou
                cout << "?";
                if(init >= fim) {
                    fim++;
                } else {
                    value += v[fim];    
                    value += v[init++];
                }
            }
        }
    }
    cout << c << '\n';

    return 0;
}