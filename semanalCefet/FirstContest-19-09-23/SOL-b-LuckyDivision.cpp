#include <bits/stdc++.h>
using namespace std;

bool isLucky(string n)
{
    for(int i = 0; i < n.size(); i++)
        if (n[i] != '7' && n[i] != '4')
            return false;
    return true;
}

int main()
{
    string n;
    cin >> n;
    if(!isLucky(n)) {
        int nm = stoi(n);
        for (int i = 4; i <= nm; i++)
        {
            if(isLucky(to_string(i)) && nm%i == 0) {
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";

    } else 
        cout << "YES\n";    

    return 0;
}