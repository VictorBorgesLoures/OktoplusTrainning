#include <bits/stdc++.h>

using namespace std;

double imbalance(vector<int> *v, int n) {
    double imbalenceN = 0;
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum+=v[i];
    double media = sum/n;
    cout << media << endl;
    for (int i = 0; i < n; i++)
        imbalenceN+=abs(v[i]-media);
    return imbalenceN;
}

int main() {

    //C numbers of chambers. S numbers of specimens.
    int C, S; cin >> C >> S;
    int set = 1;
    cout << fixed << setprecision(5);
    while(C && S) {
        vector<int> chambers[C];
        int specimens[S];

        for (int i = 0; i < S; i++)
            cin >> specimens[i];
        sort(specimens, specimens+S);
        int init = 0, end = S-1;
        int currentChamber = 0;
        if(S%2 != 0) 
           chambers[currentChamber++].push_back(specimens[end--]);
        while(init < end) {
            chambers[currentChamber].push_back(specimens[init++]);
            chambers[currentChamber++].push_back(specimens[end--]);
        }

        cout << "Set #"<< set<<'\n';
        for (int i = 0; i < C; i++)
        {
            cout << ' ' << to_string(i) << ": ";
            for (int c = 0; c < chambers[i].size(); c++)
                cout << to_string(chambers[i][c]) << ' ';
            cout << '\n';            
        }
        cout << "IMBALANCE = " << imbalanceN(chambers, C);
        set++;
        cin >> C >> S;
    }

    return 0;
}