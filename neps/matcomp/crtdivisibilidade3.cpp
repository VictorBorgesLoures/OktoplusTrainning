#include <iostream>

using namespace std;

int ctoi(char a) {
    int number = a-'0';
    if(number >= 0 && number < 10)
        return number;
    return -1;
}

int main() {

    string N; cin >> N;
    char g[10] = {'0','1','2','3','4','5','6','7','8','9'};
    
    int sumOdd = 0, sumEven = 0;
    for (int i = 0; i < N.size(); i++)
    {
        int n = ctoi(N[i]);
        if((i+1)%2 == 0)
            sumEven += n;
        else
            sumOdd += n;
    }

    if(sumOdd == sumEven)
        cout << "S" << endl;
    else 
        cout << "N" << endl;    

    return 0;
}