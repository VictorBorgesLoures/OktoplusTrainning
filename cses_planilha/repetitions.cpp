#include <bits/stdc++.h>

using namespace std;

int main() {

    string s;
    getline(cin >> ws, s);
    int count = 0;
    int sCount = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sCount++;
        if(i+1 < s.size() && s[i] != s[i+1]) {
            count = sCount > count ? sCount : count;
            sCount = 0;
        }
    }

    count = sCount > count ? sCount : count;
    
    cout << count << endl;

    return 0;
}