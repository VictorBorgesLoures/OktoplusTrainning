#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long numbers[n], X;
    cin >> X;
    for (int i = 0; i < n; i++)
        cin >> numbers[i];
    sort(numbers, numbers+n);

    int i=0,j=n-1;
    while(i <= j) {
        if(numbers[j]-numbers[i] == X || numbers[i]-numbers[j] == X) {
            cout << "Yes" << '\n';
            return 0;
        }

        if(X >= 0) {
            if(numbers[j]-numbers[i] > X) {
                i++;
            } else {
                j--;
                while(i > 0 && numbers[j]-numbers[i] <= X)
                    i--;         
            }
        } else {
            if(numbers[i]-numbers[j] < X) {
                j--;
            } else {
                i++;
                while(j < n && numbers[i]-numbers[j] >= X)
                    j++;
            }
        }

    }
    cout << "No" << '\n';
    return 0;
}