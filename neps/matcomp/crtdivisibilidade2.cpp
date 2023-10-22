#include <iostream>

using namespace std;

int main() {

    string N; cin >> N;
    char g[10] = {'0','1','2','3','4','5','6','7','8','9'};
    if(((int)(N[N.size()-2]-'0')*10 + (int)(N[N.size()-1]-'0')) % 4 == 0)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    int sum = 0;
    for (int i = 0; i < N.size(); i++)
        sum+= (int)(N[i]-'0');

    if(sum%9 == 0)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    if(N.size() > 1) {
        if((N[N.size()-1] == g[0] && N[N.size()-2] == g[0]) 
        || (N[N.size()-1] == g[5] && N[N.size()-2] == g[2]) 
        || (N[N.size()-1] == g[0] && N[N.size()-2] == g[5]) 
        || (N[N.size()-1] == g[5] && N[N.size()-2] == g[7]))
            cout << "S" << endl;
        else
            cout << "N" << endl;
    } else {
        if(N[0] == g[0])
            cout << "S" << endl;
        else
            cout << "N" << endl;
    }

    return 0;
}