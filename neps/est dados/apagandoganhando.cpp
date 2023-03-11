#include <iostream>
#include <string>

using namespace std;

int main() {

    int N, D;

    cin >> N >> D;

    while(N > 0 && D > 0) {

        string number;
        cin >> number;
        string newNumber = "";
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            if (count < D) {
                int maior = i;
                if(i+D-count < N ) {
                    //cout << "Pode-se varrer : " << D-count << endl;
                    int contador = 0;
                    for (int c = i+1; c < i+D-count+1; c++)
                    {
                        if((int)number[c] > (int)number[maior]) {
                            maior = c;
                        }
                        contador++;
                    }
                    //cout << "Varreu-se : " << contador << endl;
                    //cout << "Pulando " << maior-i << endl;
                    count += (maior-i);
                    i = maior;
                }
            } 
            if(newNumber.size() == N-D)
                break;
            //cout << " número inserido : " << number[i] << endl;
            newNumber += number[i];   
        }
        
        cout << newNumber << endl;
        cin >> N >> D;
    }

    return 0;
}

/*
4 2
3759
6 3
123123
7 4
1000000
7 3
1001234
7 3
1212234
7 3
1232234
6 2
103759
15 4
103759584781035
0 0
*/