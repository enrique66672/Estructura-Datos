//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNode (int);
void insertNode (Node*&, int, int&);
void showTree (Node*, int);

int main () {
    Node *tree = NULL;
    int inodesT = 0, count = 0;
    int opcion, data;

    do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Insertar un nuevo nodo"<<endl;
		cout<<"2.- Mostrar el arbol / numero de nodos"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;

		switch (opcion)	{
		case 1:
			cout<<"Ingrese el dato: "<<endl;
			cin>>data;
			insertNode(tree, data, inodesT);
			break;
		case 2:
            cout<<"Numero de nodos: "<<inodesT<<endl;
			cout<<"\nMostrando arbol completo: \n\n";
			showTree(tree, count);
			cout<<endl;
			break;
		case 3: break;
		default: break;
		}
	} while(opcion != 3);

    return 0;
}

Node *createNode (int value) {
    Node *new_Node = new Node();

    new_Node->data = value;
    new_Node->right = NULL;
    new_Node->left = NULL;
    
    return new_Node;
}

void insertNode (Node*&tree, int value, int&iNodesT) {
    int valueRoot;

    if (tree == NULL) {
        Node *new_Node = createNode(value);
        tree = new_Node;
        iNodesT++;
    }
    else {
        if (value >= tree->data) {
            insertNode(tree->right, value, iNodesT);
        }
        else {
            insertNode(tree->left, value, iNodesT);
        }
    } 
}

void showTree (Node*tree, int count) {
    if (tree == NULL) {
        return;
    } else {
        showTree(tree->right, count+1);

        for (int i = 0; i < count; i++) {
            cout<<"   ";
        }
        cout<<tree->data<<endl;
        showTree(tree->left, count+1);
    }
}
