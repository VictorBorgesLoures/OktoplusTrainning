#ifndef ABB_H    // INCLUDE GUARD
#define ABB_H

// INTERFACE DA ARVORE BINÁRIA DE BUSCA (ABB)

typedef struct no no;

bool buscar(no* a, int valor);
no* criar(int valor_raiz);
no* inserir(no* a, int valor);
void largura(no* n);
void liberar(no** n);
void percorrer(no *n);
no* remover(no* a, int valor);
//Retorna a quantidade de nós internos na árvore
int internos(no* n);
//Retorna a quantidade de números ímpares presentes na árvore
int qtde_impares(no* n);

#endif // ABB_H