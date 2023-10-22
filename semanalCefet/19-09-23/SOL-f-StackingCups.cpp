#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    vector<pair<int, string>> cups;
    cin >> n;
    string color;
    for (int i = 0; i < n; i++)
    {
        getline(cin >> ws, color);
        int sPos = 0;
        pair<int, string> pair;
        sPos = color.find(" ");
        if(color.substr(0, sPos-1)[0]-'a' < 0) { // number first
            pair.first = stoi(color.substr(0, sPos))/2;
            pair.second = color.substr(sPos+1, color.size()-1);
        } else {
            pair.second = color.substr(0, sPos);
            pair.first = stoi(color.substr(sPos+1, color.size()-1));
        }

        cups.push_back(pair);
    }

    sort(cups.begin(), cups.end());
    for (int i = 0; i < cups.size(); i++)
        cout << cups[i].second << "\n";
    
    return 0;
}