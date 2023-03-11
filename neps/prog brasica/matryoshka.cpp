#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main() {

    int N, B;
    cin >> N;

    vector<int> bonecas1;
    vector<int> bonecas2;
    list<int> foraOrdem;

    for (int i = 0; i < N; i++) {
        cin >> B;
        bonecas1.push_back(B);
    }
    bonecas2 = bonecas1;

    sort(bonecas1.begin(), bonecas1.end());
    
    for (int i = 0; i < N; i++)
    {
        if(bonecas1[i] != bonecas2[i])
            foraOrdem.push_front(bonecas2[i]);
    }

    foraOrdem.sort();
    int count = foraOrdem.size();
    cout << count << endl;

    for (int i = 0; i < count; i++)
    {
        cout << foraOrdem.front() << " ";
        foraOrdem.pop_front();
    }

    return 0;
}