#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    vector<int> tres;
    int maxDays = 0,v;
    for (int i = 0; i < N; i++)
    {
        cin >> v;
        tres.push_back(v);
    }
    sort(tres.begin(), tres.end());
    for (int i = 1; i < N+1; i++)
    {
        maxDays = max(tres[N-i]+i, maxDays);
    }
    
    cout << maxDays+1 << endl;
    

    return 0;
}