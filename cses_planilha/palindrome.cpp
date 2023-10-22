#include <bits/stdc++.h>

using namespace std;

int main() {

    string s; getline(cin >> ws, s);
    stack<char> finalString;
    int v[27] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        int mod = (int)(s[i]) - 'A';
        v[mod] +=1;
    }

    int odds = 0;
    int oddQtd = 0;
    int oddIndex = -1;

    string printString = "";
    for (int i = 0; i < 27; i++)
    {
        if(odds > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }

        if(v[i]%2 != 0) {
            odds++;
            oddIndex = i;
            oddQtd = v[i];
        } else {
            while(v[i] > 0) {
                v[i]-=2;
                printString += (char)(i+'A');
                finalString.push((char)(i+'A'));
            }
        }
    }

    for (int i = 0; i < oddQtd; i++)
    {
        printString += ((char)(oddIndex+'A'));
    }
    
    while(!finalString.empty()) {
        char top = finalString.top(); finalString.pop();
        printString += top;
    }
    cout << printString << endl;

    return 0;
}