#include <bits/stdc++.h>
using namespace std;

bool isLucky(string number, short * alreadyLuck) {
    if(alreadyLuck[stoi(number)] == 1)
        return true;
    if(alreadyLuck[stoi(number)] == 2)
        return false;
    bool isL = true;
    for (int i = 0; i < number.size(); i++)
    {
        if(number[i] != '4' && number[i] != '7') {
            isL = false;
            break;
        }
    }

    int numberInt = stoi(number);
    if(!isL) {
        if(numberInt%4 == 0 || numberInt%7 == 0)
            isL = true;
        else
            for (int i = numberInt/2; i > 0; i--) {
                if(isLucky(to_string(i), alreadyLuck) && numberInt%i == 0) {isL=true;break;}
            }
        
    }
    !isL ? alreadyLuck[numberInt] = 2 : alreadyLuck[numberInt] = 1;
    return isL;
}

int main() {
    string n;
    cin >> n;
    short alreadyLuck[1000] = {0};
    cout << (isLucky(n, alreadyLuck) ? "YES" : "NO") << endl;

    return 0;
}