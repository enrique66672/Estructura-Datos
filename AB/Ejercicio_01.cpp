//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>

//Estructura de un nodo de arbol binario
struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNode (int);
void insertNode (Node*&, int, int&);
void showTree (Node*, int);

/**
 * La funcion main contiene la creacion del arbol y alguna variables necesarias
 * El menu muestra las opciones como insertar un nodo, mostrar el arbol y numero de 
 * nodos y la salida del programa.
*/
int main () {
    Node *tree = NULL;
    int inodesT = 0, count = 0;
    int opcion, data;

    do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Insertar un nodo"<<endl;
		cout<<"2.- Mostrar el arbol y numero de nodos"<<endl;
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
			cout<<"\nMostrando arbol completo: \n\n";
			showTree(tree, count);
			cout<<endl;
            cout<<"Numero de nodos: "<<inodesT<<endl;
			break;
		case 3: break;
		default: break;
		}
	} while(opcion != 3);

    return 0;
}

/**
 * La funcion crea un nodo pasa un dato, se asigna valor al dato del nodo con el que recibimos
 * y asignamos NULL a la izquierda y a la derecha.
*/
Node *createNode (int value) {
    Node *new_Node = new Node();

    new_Node->data = value;
    new_Node->right = NULL;
    new_Node->left = NULL;
    
    return new_Node;
}

/**
 * Se recibe el nodo raiz del arbol, el valor a insertar y un contador de Nodos
 * Primero se comprueba que el nodo no sea NULL en el caso que sí entonces se crea un Nodo,
 * cada vez que se crea un nodo nuevo se incrementa el contador. 
 * Sino se cumple el caso base entonces empieza comparando el valor que 
 * recibimos con el valor de cada nodo, si es menor el valor se buscará insertar
 * a la izquierda y si el valor es mayor se busca por la derecha, hasta cumplir 
 * el caso base.
*/
void insertNode (Node*&tree, int value, int&iNodesT) {
    int valueRoot;

    if (tree == NULL) {
        Node *new_Node = createNode(value);
        tree = new_Node;
        iNodesT++; // contador de nodos
    }
    else {
        valueRoot = tree->data;
        if (value >= valueRoot) 
            insertNode(tree->right, value, iNodesT);
        else 
            insertNode(tree->left, value, iNodesT);
    } 
}

/**
 * Comprueba que el arbol sea diferente de NULL
 * Imprime un arbol en foma horizontal, primero el subarbol derecho primero 
 * Deja los espacios necesarios y después imprime el subarbol izquierdo 
*/
void showTree (Node*tree, int count) {
    if (tree == NULL) 
        return;
    else {
        showTree(tree->right, count+1);

        for (int i = 0; i < count; i++) 
            cout<<"   ";

        cout<<tree->data<<endl;
        showTree(tree->left, count+1);
    }
}
