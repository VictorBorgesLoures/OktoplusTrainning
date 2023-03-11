#include <iostream>
#include <string>
#include <climits>
#include <stack>

using namespace std;

int isMatch(char i, char c) {
    int value = 0;
    if(i == '{')
        c == '}' ? value = 1 : value = 0;

    return value;
    
}

int main() {

    int T;
    cin >> T;
    string exp;
    stack<char> expressoes;

    char wellMade = 'S';
    for (int i = 0; i < T+1; i++)
    {
        getline(cin,exp);
        int size = exp.size();

        for (int c = 0; c < size; c++)
        {
            if(exp[c] == '}') {
                if(expressoes.size() > 0) {
                    if(!isMatch(expressoes.top(),exp[c])) {
                        wellMade = 'N';
                        break;
                    }
                } else {
                    wellMade = 'N';
                    break;
                }
                expressoes.pop();
            } else {
                if(exp[c] == '{')
                    expressoes.push(exp[c]);
            }
        }         
    }

    if(expressoes.size() > 0)
        wellMade = 'N';
    cout << wellMade << endl;
    

    return 0;
}