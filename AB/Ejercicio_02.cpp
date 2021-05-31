//By: Juan Gerardo Molina Garcia and Roque Ramos Miguel Enrique
#include <iostream>

/**
 * El nodo posee el dato de tipo char, un identificador para poder acomodarlo de la manera
 * especificada, un dato entero que guardara el nivel donde se encuentra cada nodo y las 
 * direcciones izquierda y derecha.
*/
struct Node {
    char data;
    int id;
    int lvl;
    Node *right;
    Node *left;
};

/**
 * Tenemos el nodo apunta a un Nodo de tipo arbol y una direccion 
 * siguinete del mismo tipo de nodo.
*/
struct NodeQ {
    Node *root;
    NodeQ *next;
};

/**
 * Nodo cola marcara el inicio y el finde la cola, apunta a los nodos
 * tipo cola
*/
struct Queue {
    NodeQ *front;
    NodeQ *back;
};


Node *createNode (int, int, int);
void insertNode (Node*&, char, int, int);
void createTree (Node*&);
void showTree (Node*, int);
void initQueue (Queue&);
void push (Queue&, Node*);
Node *pop (Queue&);
void widthTravel (Node*);

/**
 * La funcion main tiene la inicializacion del arbol y un par de variables
 * necesarioas, tambien se hace una llamada a la funcion de creacion de arbol
 * que contruye el erbol planteado en el problema.
 * Tenemos el menu con las opcionde mostrar el arbol y de realizar el recorrido.
*/
int main () {
    Node *tree = NULL;
    int count = 0;
    int opcion;
    createTree(tree);

    do {
		cout<<"\n\t MENU"<<endl;
		cout<<"1.- Mostrar el arbol"<<endl;
        cout<<"2.- Recorrido por amplitud"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"Ingrese una opcion: "<<endl;
		cin>>opcion;

		switch (opcion)	{
		case 1:
			cout<<"\nMostrando arbol completo: \n\n";
			showTree(tree, count);
			cout<<endl;
			break;
		case 2:
            cout<<"\nImpresion por amplitud"<<endl;
            widthTravel(tree); 
            cout<<endl;
            break;
        case 3: break;
		default: break;
		}
	} while(opcion != 3);
    
    return 0;
}

/**
 * La funcion crea un nodo pasa el valor para mostrar, el identificador y el nivel 
 * realizamos las asignaciones a cada uno de los valores, y asignamos [NULL] a los
 * hijos izquierdo y derecho.
*/
Node *createNode (char value, int id, int lvl) {
    Node *new_Node = new Node();

    new_Node->data = value;
    new_Node->id = id;
    new_Node->lvl = lvl;
    new_Node->left = NULL;
    new_Node->right = NULL;
    
    return new_Node;
}

/**
 * Se recibe el nodo raiz del arbol, el valor a insertar, el identificador y el nivel.
 * Primero se comprueba que el nodo no sea NULL en el caso que sí entonces se crea un Nodo.
 * Sino se cumple el caso base entonces empieza comparando el valor que 
 * recibimos con el valor de cada nodo, si es menor el valor se buscará insertar
 * a la izquierda y si el valor es mayor se busca por la derecha, hasta cumplir 
 * el caso base, en ese se asgina el valor del nivel que tenga segun haya completado 
 * los casos recursivos
*/
void insertNode (Node*&tree, char value, int id, int lvl) {
    int iValueRoot;

    if (tree == NULL) {
        Node *new_Node = createNode(value, id, lvl);
        tree = new_Node;
    } 
    else {
        iValueRoot = tree->id;
        if (id >= iValueRoot) 
            insertNode(tree->right, value, id, lvl+1);
        else
            insertNode(tree->left, value, id, lvl+1);
    }    
}

/**
 * Recibimos el nodo raiz.
 * Creamos un par de arreglos con los valores con los que vamos a rellenar el arbol
 * el primero con identificadores que dibujen el arbol como el solicitado y en otro 
 * los valores de las letras en codigo ascii e inicializamos el nivel en 1 que es para 
 * la raiz por definicion, hacemos 9 llamadas a insertar Nodo para hacer el llenado del arbol.
*/
void createTree(Node*&tree) {
    int identifiers[9] = {65,60,66,59,62,67,61,64,63};
    char iAscii[9] = {65,66,67,68,69,73,70,71,72};
    int level = 1;

    for (int i = 0; i < 9; ++i) 
        insertNode (tree, iAscii[i], identifiers[i], level);
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
 * La funcion recibe a la cola por referencia 
 * Inicializamos los puntero de la cola con [NULL]
 */ 
void initQueue(Queue&q) {
    q.back = NULL;
    q.front = NULL;
}

/**
 * La funcion recibe la cola y al arbol
 * Se crea un nodo de tipo cola y almacenamos el nodo arbol y puntero 
 * siguiente apunta a [NULL], luego en la cola si el siguiente es [NULL]
 * colocamos el nodo de tipo cola en la cola y sino lo colocamos en la 
 * posicion anterior y repetimos el valor pero en le puntero atras
*/
void push (Queue&q, Node *tree) {
    NodeQ *p = new NodeQ();
    p->root = tree;
    p->next = NULL;

    if (q.front == NULL) 
        q.front = p;
    else 
        q.back->next = p;
    q.back = p;       
}

/**
 * Retornamos un nodo de tipo arbol, y recibimos la cola
 * Creamos un nodo de tipo cola en el almacenamos almacenamos el nodo de frente de la cola
 * Creamos un nodo arbol y le damos el valor de la raiz que se almaceno en la cola
 * y luego movemos la segunda posicion a la primera en la cola, borramos nodo de tipo puntero
 * y retornamos el nodo de arbol
*/
Node *pop (Queue&q) {
    NodeQ *p;
    p = q.front;
    Node *tree = p->root;
    q.front = q.front->next;
    delete(p);
    return tree;
}

/**
 * Realizamos el recorrido por anchura, recibimos el arbol
 * Creamos una estructura cola, la inicializamos, comparamos que el arbol no este vacio 
 * Si el arbol es diferente de [NULL] entonces encolamos el nodo raiz, luego en el while 
 * comprobamos que la cola no este vacia, vamos a estar desencolando de izquierda a derecha 
 * los hermanos en cada nivel, luego se imprimen los guiones, dependiendo del nivel donde se 
 * encuentran se imprime la cantidad de guiones cortos, luego imprime el valor, si tenemos 
 * valores por la izquierda y por la derecha comenamos a enconlar por nivel 
*/
void widthTravel (Node *tree) {
    Queue q;
    initQueue(q);

    if (tree != NULL) {
        push(q, tree);

        while (q.front != NULL) {
            tree = pop(q);
            for (int i = 0; i < tree->lvl; i++)
                cout<<"-";
            cout<<tree->data;

            if (tree->left != NULL)
                push(q, tree->left);
            if (tree->right != NULL) 
                push(q, tree->right);
        } 
    }
}
