#include <bits/stdc++.h>

using namespace std;

int main() {

    int N,M,T,A,B;
    cin >> N >> M;
    map<int, vector<int>> ilhas;
    queue<short> respostas;

    for (int i = 0; i < M; i++)
    {
        cin >> T >> A >> B;
        --A;
        --B;
        if(T == 0) {
            bool found = false;
            for (int c = 0; c < ilhas[A].size(); c++)
                if(ilhas[A][c] == B) {
                    respostas.push(1);
                    found = !found;
                    break;
                }
            if(!found)
                respostas.push(0);
        } else {
            ilhas[A].push_back(B);
            ilhas[B].push_back(A);
        }
    }
    
    while(!respostas.empty()) {
        cout << respostas.front() << '\n';
        respostas.pop();
    }    

    return 0;
}