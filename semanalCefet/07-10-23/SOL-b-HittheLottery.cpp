#include <bits/stdc++.h>

using namespace std;

int main() {
    int ballance;
    cin >> ballance;
    int values[5] = {1,5,10,20,100};
    int idx = 4, bills = 0;

    while(ballance > 0) {
        if(ballance - values[idx] >= 0) {
            ballance -= values[idx];
            bills++;
        } else
            idx--;
    }        
    cout << bills << '\n';
    return 0;
}