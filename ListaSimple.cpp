// by Juan Gerardo Molina Garcia and Miguel Enrique Roque Ramos
#include <iostream>
#include <conio.h>

struct Nodo {
    int data;
    Nodo *next;
};

void inputO(Nodo *&, int);
void inputD(Nodo *&, int);
void showList(Nodo *);

int main() {
    Nodo *list = NULL;
    int data;
    char resp;

	do {
		cout << "Digite un numero:";
		cin >> data;
		inputO(list, data);

		cout << "\nDesea agregar un nuevo dato en lista (s/n)" << endl;
		cin >> resp;
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

void inputO(Nodo *&list, int data) {
    Nodo *new_nodo = new Nodo();
    new_nodo->data = data;

    Nodo *aux1 = list;
    Nodo *aux2;

    while ((aux1 != NULL) && (aux1->data < data)) {
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if (list == aux1) {
        list = new_nodo;
    } else {
        aux2->next = new_nodo;
    }

    new_nodo->next = aux1;
    cout << "\n Elemento " << data << " insertado correctamente" << endl << endl;

    showList(list);
}

void showList(Nodo *list) {
    while( !(list == NULL)) {
        cout << list->data << "->";
        list = list->next;
    }
}