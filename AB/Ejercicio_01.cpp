// Escriba un programa que calcule e imprima cuántos nodos tiene un árbol
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node right;
    Node left;
};

Node *createNode (int);
void insertNode (Nodo*&, int, int&);
void showTree (Node*, int);

int main () {
    Node *tree = NULL;
    int inodesT = 0;

    return 0;
}

Node *createNode (int value) {
    Node *new_Node = new Node();

    new_Node->data = value;
    new_Node->right = NULL;
    new_Node->left = NULL;
    
    return new_Node;
}

void insertNode (Nodo*&tree, int value, int&iNodesT) {
    int valueRoot;

    if (tree == NULL) {
        Node *new_Node = createNode(value);
        tree = new_Node;
        iNodesT++;
    }
    else {
        if (value >= tree->data) {
            insertNode(tree->right, value);
        }
        else {
            insertNode(tree->left, value);
        }
    } 
}