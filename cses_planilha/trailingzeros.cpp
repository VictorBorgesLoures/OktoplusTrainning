#include <bits/stdc++.h>

using namespace std;

long long solve(long long number) {
    long long count = 0;
    for (long long i = 5; i <= number; i+=5)
    {
        long long div = i;
        while(div%5==0) {
            div/=5;
            count++;
        }
    }
    
    return count;
    
}

int main() {

    long long n;cin>>n;

    cout << solve(n) << endl;

    return 0;
}