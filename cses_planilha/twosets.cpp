#include <bits/stdc++.h>

using namespace std;

long long sumN(int n) {
    long long sum = 0;
    for (long long i = 0; i < n; i++)
        sum += i+1;
    
    return sum;
}

long long count(long long *v, long long n) {
    long long count = 0;
    for (long long i = 0; i < n; i++)
        if(v[i])
            count ++;

    return count;
}

int main() {

    long long n; cin >> n;

    if(sumN(n)%2 == 0) {
        cout << "YES" << endl;
        long long div = sumN(n)/2;
        long long v[n] = {0};
        long long sum = 0;

        for (long long i = n-1; i >= 0; i--)
        {
            sum+= i+1;
            v[i] = 1;
            if(sum == div)
                break;
            else {
                if(sum < div) {
                    if(i == 0) {
                        sum-= (i+1);
                        v[i] = 0;
                        for (long long c = 0; c < n; c++)
                            if(v[c]) {
                                v[c] = 0;
                                sum -= (c+1);
                                i = c;
                                break;
                            }  
                    }
                } else {
                    sum-= (i+2);
                    v[i+1] = 0;
                }
            }
        }
        

        /*
        for (long long i = 0; i < n; i++) {
            sum += i+1;
            v[i] = 1;
            if(sum == div) {
                break;
            } else {
                if(sum < div) {
                    if(i == n-1) {
                        sum-= (i+1);
                        v[i] = 0;
                        for (long long c = n-1; c >= 0; c--)
                            if(v[c]) {
                                v[c] = 0;
                                sum -= (c+1);
                                i = c;
                                break;
                            }                        
                    }
                } else {
                    sum-= ((i+1)*2-1);
                    v[i] = 0;
                    v[i-1] = 0;
                    i--;
                }
            }
        }
        */
        int countN = count(v, n);
        cout << countN << endl;
        for (long long i = 0; i < n; i++)
            if(v[i])
                cout << i+1 << " ";
        
        cout << endl;

        cout << n - countN << endl;
        for (long long i = 0; i < n; i++)
            if(!v[i])
                cout << i+1 << " ";
        cout << endl;        
        
    } else 
        cout << "NO" << endl;

    return 0;
}