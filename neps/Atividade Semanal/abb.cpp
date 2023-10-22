#include <bits/stdc++.h>
#include "abb.h"

using namespace std;

struct no {
    int info;
    no *sae;    // sub-árvore a esquerda
    no *sad;    // sub_árvore a direita
};

bool buscar(no* a, int valor) {
    if(a == NULL)
        return false;
    
    if(valor == a->info)
        return true;
    else if(valor < a->info)
        return buscar(a->sae, valor);
    else
        return buscar(a->sad, valor);
}

no* criar(int valor_raiz) {
    no *raiz = (no*) calloc(1, sizeof(no));
    if(raiz != NULL)
        raiz->info = valor_raiz;
    
    return raiz;
}

no* inserir(no* n, int valor) {
    if(n == NULL)
        return criar(valor);

    if(valor < n->info)
        n->sae = inserir(n->sae, valor);
    else
        n->sad = inserir(n->sad, valor);
    
    return n;
}

void largura(no* n) {
    queue<no*> f;
    f.push(n);
    while(!f.empty()) {
        no* atual = f.front();
        cout << atual->info << " ";
        f.pop();
        if(atual->sae)
            f.push(atual->sae);
        if(atual->sad)
            f.push(atual->sad);
    }
}

void liberar(no** n) {
    if(n == NULL)
        return;
    
    no* temp = *n;
    liberar(&((*n)->sae));
    liberar(&((*n)->sad));
    free(temp);
}

void percorrer(no *n) {
    if(n == NULL)
        return;

    percorrer(n->sae);
    cout << " " << n->info;
    percorrer(n->sad);
}

no* minimo(no* n) {
    if(n->sae != NULL)
        return minimo(n->sae);

    return n;
}

no* remover(no* n, int valor) {
    if(n == NULL)
        return NULL;
    
    if(valor < n->info) {
        n->sae = remover(n->sae, valor);
    } else if(valor > n->info) {
        n->sad = remover(n->sad, valor);
    } else {
        no* temp = NULL;
        if(n->sae == NULL && n->sad == NULL) {
            free(n);
            return NULL;
        } else if(n->sae == NULL) {
            temp = n->sad;
            free(n);
            return temp;
        } else if(n->sad == NULL) {
            temp = n->sae;
            free(n);
            return temp;
        } else {
            temp = minimo(n->sad);
            n->info = temp->info;
            n->sad = remover(n->sad, temp->info);
        }
    }

    return n;
}

//A: Faltou desconsiderar a raiz
int internos(no* n) {
    queue<no*> fila;
    int qtdNos = 0;
    fila.push(n);

    while(!fila.empty()) {
        no* atual = fila.front(); fila.pop();
        if(atual->sad != NULL) {
            fila.push(atual->sad);
        }
        if(atual->sae != NULL) {
            fila.push(atual->sae);
        }
        if(atual->sad != NULL || atual->sae != NULL)
            qtdNos++;
    }

    return qtdNos;
}

int qtde_impares(no* n) {
    if(n == NULL)
        return 0;
    
    int sum = 0;
    if(n->info%2 != 0)
        sum++;
    sum += qtde_impares(n->sad);
    sum += qtde_impares(n->sae);

    return sum;
}
