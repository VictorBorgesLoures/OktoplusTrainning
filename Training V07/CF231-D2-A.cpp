#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,nProblems = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int know = 0;
        for (int j = 0; j < 3; j++)
        {
            int number;
            cin >> number;
            if(number == 1)
                know++;
        }
        if(know >= 2)
            nProblems++;
    }
    
    cout << nProblems << '\n';

    return 0;
}