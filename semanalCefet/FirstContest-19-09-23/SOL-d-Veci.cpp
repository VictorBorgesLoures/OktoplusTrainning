#include <bits/stdc++.h>
using namespace std;

int main()
{

    string n;
    getline(cin >> ws, n);
    string cp = n;
    next_permutation(cp.begin(), cp.end());
    if(cp <= n)
        cout << "0\n";
    else 
        cout << cp << '\n';
    
    return 0;
}