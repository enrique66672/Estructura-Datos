//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNode (int);
void insertNode (Node*&, int);
void showTree (Node*, int);
void treeWalk (Node*);

int main () {
    Node *tree = NULL;
    int count = 0;
    int opcion, data;

    do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Insertar un nuevo nodo"<<endl;
		cout<<"2.- Mostrar el arbol"<<endl;
        cout<<"3.- Recorrido especial"<<endl;
		cout<<"4.- Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;

		switch (opcion)	{
		case 1:
			cout<<"Ingrese el dato: "<<endl;
			cin>>data;
			insertNode(tree, data);
			break;
		case 2:
			cout<<"\nMostrando arbol completo: \n\n";
			showTree(tree, count);
			cout<<endl;
			break;
		case 3: 
            treeWalk(tree);
            cout<<endl;
            break;
        case 4:
            break;
		default: break;
		}
	} while(opcion != 4);
    return 0;
}

Node *createNode (int value) {
    Node *new_Node = new Node();
    new_Node->data = value;
    new_Node->left = NULL;
    new_Node->right = NULL;
    return new_Node;
}

void insertNode (Node*&tree, int value) {
    int iValueRoot;
    if (tree == NULL) {
        Node *new_Node = createNode(value);
        tree = new_Node;
    } 
    else {
        iValueRoot = tree->data;
        if (value >= iValueRoot) 
            insertNode(tree->right, value);
        else
            insertNode(tree->left, value);
    }
    
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

void treeWalk (Node*tree) {
    if (tree == NULL) {
        return;
    }
    else {
        cout<<tree->data<<"-";
        treeWalk(tree->right);
        treeWalk(tree->left);
    }
    
}
