#include <bits/stdc++.h>

using namespace std;

double getNumber(string s) {
    string n1 = "", n2 = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ':') {
            n2+= s.substr(i+1, s.size()-1);
            break;
        }
        else
            n1+= s[i];
    }
    double nm1 = stoi(n1);
    nm1 = nm1 == 12 ? 0 : nm1;
    double nm2 = stoi(n2);
    nm2/=100;
    return nm1+nm2;
}

int main() {
    int T; cin >> T;

    while(T!=0) {
        vector<pair<string, string>> v(T);
        cin >> v[0].first >> v[0].second;
        for (int i = 1; i < T; i++)
        {
            cin >> v[i].first >> v[i].second;
            int c = i;
            while(c > 0) {
                if(v[c].second == v[c-1].second) {
                    if(getNumber(v[c].first) <= getNumber(v[c-1].first))
                        swap(v[c], v[c-1]);
                } else if(v[c].second == "a.m.") {
                    swap(v[c], v[c-1]);
                } else 
                    break;
                c--;
            }
            
        }
        for (int i = 0; i < T; i++)
            cout << v[i].first << " " << v[i].second << '\n';        
        cout << '\n';
        cin >> T;
    }

    

    return 0;
}