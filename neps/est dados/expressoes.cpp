#include <iostream>
#include <stack>

using namespace std;

int isMatch(char i, char c) {
    int value = 1;
    if(i == '{')
        c == '}' ? value = 1 : value = 0;
    else if(i == '[')
        c == ']' ? value = 1 : value = 0;
    else if(i == '(')
        c == ')' ? value = 1 : value = 0;

    return value;
    
}

int main() {

    int T;
    cin >> T;
    string exp;
    stack<char> expressoes;

    for (int i = 0; i < T; i++)
    {
        char wellMade = 'S';
        cin >> exp;
        if( exp.size()%2 != 0) {
            wellMade = 'N';
        } else {
            int size = exp.size();
            
            for (int c = 0; c < size; c++)
            {
                if(exp[c] == '}' || exp[c] == ']' || exp[c] == ')') {
                    if(!isMatch(expressoes.top(),exp[c])) {
                        wellMade = 'N';
                        break;
                    }
                    expressoes.pop();
                } else {
                    expressoes.push(exp[c]);
                }
            } 
        }
        
        cout << wellMade << endl;

    }
    

    return 0;
}