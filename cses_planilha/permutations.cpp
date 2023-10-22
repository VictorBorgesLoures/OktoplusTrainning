#include <bits/stdc++.h>

using namespace std;

int main() {

    int N; cin >> N;
    stack<int> s;
    queue<int> f;
    for (int i = 0; i < N; i++)
        f.push(i+1);

    if(N%2 == 0) {
        f.push(f.front());
        f.pop();
    }

    while(!f.empty()) {
        int n = f.front(); f.pop();
        if(s.size() > 0) {
            int sTop = s.top();
            if(sTop - n == 1 || sTop - n == -1) {
                f.push(n); 
                if(f.size() == 1)
                    break;
            }
            else 
                s.push(n);
        } else
            s.push(n);
    }

    if(!f.empty()) 
        cout << "NO SOLUTION" << endl;
    else
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }    

    return 0;
}