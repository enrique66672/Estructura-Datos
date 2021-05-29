// by Juan Gerardo Molina Garcia and Miguel Enrique Roque Ramos
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
    int data;
    Nodo *next;
};

void inputD(Nodo *&, int);
void showList(Nodo *);
void deleteElement(Nodo *&, int);

int main() {
    Nodo *list = NULL;
    int data;
    char resp;

	do {
		cout << "Digite un numero:";
		cin >> data;
		inputD(list, data);

		cout << "\nDesea agregar un nuevo dato en lista (s/n)" << endl;
		cin >> resp;
	} while(resp == 's' || resp == 'S');

    do {
        if (list == NULL) {
            cout << "Imposible realizar esta accion - Lista vacia";
            cout << endl;
            system("pause");
            exit(-1);
        } else {
            cout << "Digite un numero a eliminar:";
            cin >> data;
            deleteElement(list, data);

            cout << "\nDesea eliminar un nuevo dato en lista? (s/n)" << endl;
            cin >> resp;
        }

	} while(resp == 's' || resp == 'S');

    getch();
    return 0;
}

void inputD(Nodo *&list, int data) {
    Nodo *new_nodo = new Nodo();
    Nodo *aux;

    new_nodo->data = data;
    new_nodo->next = NULL;

    if (list == NULL) {
        list = new_nodo;
    } else {
        aux = list;

        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_nodo;
    }
    cout << "\n Elemento " << data << " insertado correctamente" << endl << endl;

    showList(list);
}

void showList(Nodo *list) {
    while( !(list == NULL)) {
        cout << list->data << "->";
        list = list->next;
    }
}

void deleteElement(Nodo *&list, int data2) {
    Nodo* aEliminar;
    Nodo* aux = list;


    while(aux != NULL) {
        if (list->data == data2) {
            aEliminar = list;
            list = list->next;
            aux = aux->next;
            delete aEliminar;
        } else {
            if(aux->next != NULL && aux->next->data == data2) {
                aEliminar = aux->next;
                aux->next = aux->next->next;
                delete aEliminar;
            } else {
                aux = aux->next;
            }
        }
    }

     showList(list);
}