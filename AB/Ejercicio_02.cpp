//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>
using namespace std;

struct Node {
    char data;
    int id;
    Node *right;
    Node *left;
};

Node *createNode (int, int);
void insertNode (Node*&, int, int);
void createTree (Node*&);
void showTree (Node*, int);
void toPrint(Node*);

int main () {
    Node *tree = NULL;
    int count = 0;
    int opcion;
    createTree(tree);

    do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Mostrar el arbol"<<endl;
		cout<<"4.- Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;

		switch (opcion)	{
		case 1:
			cout<<"\nMostrando arbol completo: \n\n";
			showTree(tree, count);
			cout<<endl;
			break;
		case 3: 
            break;
        case 4:
            break;
		default: break;
		}
	} while(opcion != 4);
    return 0;
}

Node *createNode (int value, int id) {
    Node *new_Node = new Node();
    new_Node->data = value;
    new_Node->id = id;
    new_Node->left = NULL;
    new_Node->right = NULL;
    return new_Node;
}

void insertNode (Node*&tree, int value, int id) {
    int iValueRoot;
    if (tree == NULL) {
        Node *new_Node = createNode(value, id);
        tree = new_Node;
    } 
    else {
        iValueRoot = tree->id;
        if (id >= iValueRoot) 
            insertNode(tree->right, value, id);
        else
            insertNode(tree->left, value, id);
    }    
}

void createTree(Node*&tree) {
    int identifiers[9] = {65,60,66,59,62,67,61,64,63};
    int iAscii[9] = {65,66,67,68,69,73,70,71,72};

    for (int i = 0; i < 9; ++i) 
        insertNode (tree, iAscii[i], identifiers[i]);
}

void showTree (Node*tree, int count) {
    if (tree == NULL) {
        return;
    }
    else {
        showTree(tree->right, count+1);

        for (int i = 0; i < count; i++) {
            cout<<"   ";
        }
        cout<<tree->data<<endl;
        showTree(tree->left, count+1);       
    }
}
