#include <iostream>
#include <string>
#include <vector>

#define MAXN 100100

using namespace std;

int n, k, pai[MAXN], peso[MAXN];

int find(int x){
    
    if(pai[x]==x){
        return x;
    }
    return pai[x]=find(pai[x]);
}
 
void join(int x, int y){
    
    x=find(x);
    y=find(y);
    
    if(x==y){
        return;
    }
    
    if(peso[x]<peso[y]){
        pai[x]=y;
    }
    if(peso[x]>peso[y]){
        pai[y]=x;
    }
    
    if(peso[x]==peso[y]){
        
        pai[x]=y;
        peso[y]++;
    }
}

int main() {

    int N,M;
    cin >> N >> M;

    while(N > 0 && M > 0) {

        int GP[N];
        int pai[N];

        for (int i = 0; i < N; i++)
        {
            int p;
            cin >> p;
            pai[i] = i;
            peso[i] = 0;
        }
        

        for (int i = 0; i < M; i++)
        {
            int op, g1,g2;
            cin >> op >> g1 >> g2;
            if(op == 1) {

            }
        }
        

        cin >> N >> M;
    }

    return 0;
}