#include <iostream>

using namespace std;

int main() {

    int N, D;
    cin >> N >> D;

    int pedacos[N];
    for (int i = 0; i < N; i++)
        cin >> pedacos[i];
    
    int qtd = 0;
    int count = 0;
    int ended = 0;
    int i = 0;
    int c = 0;

    while(!ended) {

        if(i >= c) {
            count += pedacos[i];
        }
        
        if(count == D) {
            qtd++;
            i = N-1;
        } else if(count > D && i < N-1) {
            count -= pedacos[i];
        }

        i++;
        if(i >= N) {
            i = 0;
            count = 0;
            c++;
        }
        if(c >= N)
            ended = 1;
    }

    i=0;
    c=N-1;
    count = 0;

    for (int k = 0; k < N/2+1; k++)
    {
        count += pedacos[i];
        if(count == D) {
            qtd++;
            break;
        } else {
            if(i != c) {
                if(count < D) {
                    count += pedacos[c];
                    if(count == D) {
                        qtd++;
                        break;
                    } else if(count > D)
                        break;
                } else {                
                    count -= pedacos[i];
                    count += pedacos[c];
                    if(count == D) {
                        qtd++;
                        break;
                    } else if(count > D)
                        break;  
                }
            }
        }
        i++;
        c--;
    }    

    cout << qtd << endl;

    return 0;
}