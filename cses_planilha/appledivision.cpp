#include <bits/stdc++.h>

using namespace std;

int menor(vector<long long> v) {
    int menor = 0;
    for (int i = 1; i < v.size(); i++)
        if(v[i] < v[menor])
            menor = i;

    return menor;
    
}

int main() {

    int n;cin >> n;
    long long numbers[n];
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        totalSum += numbers[i];
    }
    cout << "TOTAL SUM : " << totalSum << endl;
    long long half = totalSum/2;
    long long halfSum = 0;
    sort(numbers, numbers+n);
    queue<long long> sumNumbers;
    for (int i = 0; i < n; i++) {
        if(halfSum > half) {
            bool removed = true;
            while(removed) {
                removed = false;
                long long removing = sumNumbers.front();
                cout << "Removing : " << removing << endl;
                halfSum-= removing;
                if(halfSum > half) {
                    sumNumbers.pop();
                    removed = true;
                } else {
                    if(sumNumbers.size() == 1)
                        halfSum += removing;
                }

            }
            break;
        } else {
            halfSum += numbers[i];
            sumNumbers.push(numbers[i]);
        }
    }
    
    if(totalSum - halfSum > half) {
        cout << ((totalSum - halfSum) - halfSum) << endl;
    } else {
        cout << (halfSum - (totalSum - halfSum)) << endl;
    }
    
    return 0;
}