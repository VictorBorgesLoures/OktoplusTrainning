#include <iostream>
 
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

int main(){
    
    cin>>n>>k;
    
    for(int i=1; i<=n; i++){
        pai[i]=i;
    }
    
    char op;
    int banco1, banco2;
    
    for(int i=1; i<=k; i++){
        
        cin>>op>>banco1>>banco2;
        if(op=='F'){
            join(banco1, banco2);
        }
        else{
            if(find(banco1)==find(banco2)){
                cout<<"S\n";
            }
            else{
                cout<<"N\n";
            }
        }
    }
    
    return 0;
}