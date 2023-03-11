#include <iostream>

using namespace std;

struct sorveteiro {
    int inicio, fim;
};

int main()
{

    int P, S;
    cin >> P >> S;
    sorveteiro sorveteiros[S];

    for (int i = 0; i < S; i++)
    {
        cin >> sorveteiros[i].inicio >> sorveteiros[i].fim;
    }

    sorveteiro intervalos[S];
    int count = 0;

    for (int i = 0; i < S; i++)
    {
        int found = 0;
        if (count > 0)
        {
            for (int c = 0; c < count; c++)
            {

                if ((intervalos[c].inicio <= sorveteiros[i].fim && intervalos[c].fim >= sorveteiros[i].fim) || (intervalos[c].inicio <= sorveteiros[i].inicio && intervalos[c].fim >= sorveteiros[i].inicio) || (sorveteiros[i].inicio <= intervalos[c].inicio && sorveteiros[i].fim >= intervalos[c].fim ))
                {
                    if (sorveteiros[i].fim > intervalos[c].fim)
                        intervalos[c].fim = sorveteiros[i].fim;

                    if (sorveteiros[i].inicio < intervalos[c].inicio)
                        intervalos[c].inicio = sorveteiros[i].inicio;

                    found = 1;
                }
            }
        }
        if (!found)
        {
            intervalos[count] = sorveteiros[i];
            count++;
        }
    }
    
    sorveteiro intervalos2[count];
    int count2 = 0;

    for (int i = 0; i < count; i++)
    {
        int found = 0;
        if (count2 > 0)
        {
            for (int c = 0; c < count2; c++)
            {

                if ((intervalos2[c].inicio <= intervalos[i].fim && intervalos2[c].fim >= intervalos[i].fim) || (intervalos2[c].inicio <= intervalos[i].inicio && intervalos2[c].fim >= intervalos[i].inicio) || (intervalos[i].inicio <= intervalos2[c].inicio && intervalos[i].fim >= intervalos2[c].fim))
                {
                    if (intervalos[i].fim > intervalos2[c].fim)
                        intervalos2[c].fim = intervalos[i].fim;

                    if (intervalos[i].inicio < intervalos2[c].inicio)
                        intervalos2[c].inicio = intervalos[i].inicio;

                    found = 1;
                }
            }
        }
        if (!found)
        {
            intervalos2[count2] = intervalos[i];
            count2++;
        }
    }

    for (int i = 0; i < count2; i++)
    {
        cout << intervalos2[i].inicio << " " << intervalos2[i].fim << endl;
    }
    
    return 0;
}
/*
1000 3
400 1000
80 200
10 400

1000 3
80 200
400 1000
10 400

 */