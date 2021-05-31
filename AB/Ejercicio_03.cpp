//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>

//Estructura de un nodo de arbol binario
struct Node {
    int data;
    Node *right;
    Node *left;
};

Node *createNode (int);
void insertNode (Node*&, int);
void showTree (Node*, int);
void treeWalk (Node*);

/**
 * En la funcion main creamos el arbol y alguna variables necesarias
 * Mostramos el menu donde tenemos las opciones de insertar el nodo, mostrar el arbol,
 * realizar el recorrido solicitado y salir, podemos ejecutar el menu de manera 
 * indefinida hasta que deseemos salir de menu.
*/
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
            cout<<endl;
            treeWalk(tree);
            cout<<endl;
            break;
        case 4: break;
		default: break;
		}
	} while(opcion != 4);

    return 0;
}

/**
 * La funcion crea un nodo pasa un dato, se asigna valor al dato del nodo con el que recibimos
 * y asignamos NULL a la izquierda y a la derecha.
*/
Node *createNode (int value) {
    Node *new_Node = new Node();

    new_Node->data = value;
    new_Node->left = NULL;
    new_Node->right = NULL;

    return new_Node;
}

/**
 * Se recibe el nodo raiz del arbol, el valor a insertar.
 * Primero se comprueba que el nodo no sea NULL en el caso que sí entonces se crea un Nodo.
 * Sino se cumple el caso base entonces empieza comparando el valor que 
 * recibimos con el valor de cada nodo, si es menor el valor se buscará insertar
 * a la izquierda y si el valor es mayor se busca por la derecha, hasta cumplir 
 * el caso base.
*/
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

/**
 * Comprueba que haya un valor en el arbol, si lo hay imprimiremos  
 * pasando desde la raíz luego la derecha y después a la izquierda.
*/
void treeWalk (Node*tree) {
    if (tree == NULL) 
        return;
    else {
        cout<<tree->data<<"-";
        treeWalk(tree->right);
        treeWalk(tree->left);
    }
    
}
