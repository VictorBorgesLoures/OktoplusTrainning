#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v;
    int number,maior = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        if(number > maior)
            maior = number;
        v.push_back(number);
    }

    int freq = 1;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1; i++)
    {
        if(v[i] != v[i+1])
            freq++;
    }
    
    cout << freq << '\n';    
    
    return 0;
}