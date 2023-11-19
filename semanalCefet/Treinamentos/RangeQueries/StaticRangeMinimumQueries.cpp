#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int value;
    node *rn;
    node *ln;
    pair<int, int> range;
    int pos;
} node;

node* add_node(node *root, int value, int pos, node* root_parent) {
    if(root == NULL) {
        node* newNode = (node*)calloc(1, sizeof(node));
        newNode->value = value;
        newNode->pos = pos;
        newNode->range.first = pos;
        newNode->range.second = root->pos-1;
        return newNode;
    }
    if(value < root->value) {
        int vR = root->value;
        int posR = root->pos;
        root->value = value;
        root->pos = pos;
        root->range.second = (root->range.second > posR ? root->range.second : pos);
        if(posR < pos) {
            if(root->ln != NULL) {
                root->ln = add_node(root->ln, vR, posR, root);
                root->ln->rn = root->rn;
                root->rn = NULL;
            } else {
                node* newNode = (node*)calloc(1, sizeof(node));
                newNode->value = vR;
                newNode->pos = posR;
                newNode->range.first = posR;
                newNode->range.second = root->pos-1;
                newNode->rn = root->rn;
                root->rn = NULL;
                root->ln = newNode;
            }
            if(root->ln->rn != NULL)
                root->ln->rn = add_node(root->ln->rn, root->value, root->pos, root->ln);
        } else {
            if(root->rn != NULL) {
                root->rn = add_node(root->rn, vR, posR, root);
            } else {
                node* newNode = (node*)calloc(1, sizeof(node));
                newNode->value = vR;
                newNode->pos = posR;
                newNode->range.first = posR;
                newNode->range.second = root->range.second;
                root->rn = newNode;
            }
            
        }
    } else {
        if(pos < root->pos) {
            if(root->ln != NULL) {
               root->ln = add_node(root->ln, value, pos, root);
            } else {
                node* newNode = (node*)calloc(1, sizeof(node));
                newNode->value = value;
                newNode->pos = pos;
                newNode->range.first = pos;
                newNode->range.second = root->pos-1;
                root->ln = newNode;
            }
            
        } else {
            if(root->rn != NULL) {
                root->rn = add_node(root->rn, value, pos, root);  
            } else {
                node* newNode = (node*)calloc(1, sizeof(node));
                newNode->value = value;
                newNode->pos = pos;
                newNode->range.first = pos;
                newNode->range.second = root->range.second;
                root->rn = newNode;
            }        
        }
    }
    return root;
}

int query_node(int a, int b, node* n) {
    if(n == NULL) {
        return -1;
    }
    //cout << "[" << a << ','<< b<< "] = " << "[" << n->range.first << ','<< n->range.second<< " | "<<n->pos << "]\n";
    if(n->pos >= a && n->pos <=b) {
        return n->value;
    } else {
        if(n->pos > a ) {
            return query_node(a, b, n->ln);
        } else {
            return query_node(a, b, n->rn);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    int v;
    cin >> v;
    node* root = (node*)calloc(1, sizeof(node));
    root->value = v;
    root->pos = 1;
    root->range.first = 1;
    root->range.second = N;

    for (int i = 2; i < N+1; i++) {
        cin >> v;
        root = add_node(root, v, i, NULL);
        stack<node*> pilha;
        /*
        pilha.push(root);
        while(!pilha.empty()) {
            node* top = pilha.top(); pilha.pop();
            if(top->ln != NULL)
                pilha.push(top->ln);
            if(top->rn != NULL)
                pilha.push(top->rn);
            cout << "[" << top->range.first << "," <<top->range.second <<" | "<< top->pos <<"] = " << top->value << '\n';
        }
        cout << "----------------------\n";
        */
        
    }
    
    for (int i = 0; i < Q; i++)
    {
        int a,b; cin >> a >> b;
        cout << query_node(a,b, root) << '\n';
    }   
    

    return 0;
}
/*
8 4
3 2 4 5 1 1 5 3
*/