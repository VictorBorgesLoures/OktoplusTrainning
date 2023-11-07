#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int time; cin >> time;
    int fullTime = 4*60;
    int remaningTime = fullTime-time;
    int count = 0;
    int i = 1;
    while(remaningTime > 0 && count < N)
    {
        remaningTime -= i*5;
        count++;
        i++;
    }

    count = remaningTime < 0 ? count-1 : count;
    
    cout << count << endl;
    
    return 0;
}