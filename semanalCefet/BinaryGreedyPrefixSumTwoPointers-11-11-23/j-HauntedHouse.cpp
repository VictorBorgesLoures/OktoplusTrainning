#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,x,tot=0; cin >> n >> x;
    int esq=0,dir=n-1;

    int vet[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    sort(vet,vet+n);

    while (esq<=dir)
    {
        if(vet[esq]+vet[dir]<=x){
            esq++;
            dir--;
            tot++;
        }
        else{
            dir--;
            tot++;
        }
    }
    
    cout << tot << '\n';

    return 0;
}