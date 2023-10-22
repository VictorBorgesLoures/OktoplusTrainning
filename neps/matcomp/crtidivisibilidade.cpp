#include <iostream>

using namespace std;

int main() {

    string N; cin >> N;

    char lastChar = N[N.size()-1];
    char g[10] = {'0','1','2','3','4','5','6','7','8','9'};
    if(lastChar == g[0] || lastChar == g[2] || lastChar == g[4] || lastChar == g[6] || lastChar == g[8] )
        cout << "S" << endl;
    else
        cout << "N" << endl;

    long long sum = 0;
    for (int i = 0; i < N.size(); i++)
        sum+= (long long)N[i];

    if(sum%3 == 0)
        cout << "S" << endl;
    else
        cout << "N" << endl;

    if(lastChar == g[0] || lastChar == g[5])
        cout << "S" << endl;
    else
        cout << "N" << endl;    
 
    return 0;
}