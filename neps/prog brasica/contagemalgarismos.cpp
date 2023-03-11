#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N;
    cin >> N;
    string values;
    char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int qtd[10] = {0};
    for (int i = 0; i < N; i++)
    {
        string valor;
        cin >> valor;
        values += valor;
    }
    
    for (int i = 0; i < values.length(); i++)
    {
        for (int c = 0; c < 10; c++)
        {
            if(values[i] == numbers[c])
                qtd[c] += 1;
        }
        
    }

    for (int i = 0; i < 10; i++)
    {
        cout << i << " - " << qtd[i] << endl;
    }

    return 0;
}