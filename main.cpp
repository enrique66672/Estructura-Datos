#include<iostream>
#include<conio.h>
#define MAX 8

void push(int [], int, int&, int);

int main() {

    int option, stack[MAX], top = -1;
    char fact;

    do{
        cout << ">>>>  PILAS   <<<<" << endl << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Cerrar Programa (3)" << endl;
        cout << "> Seleccionar: "

        cin >> option;
        switch(option) {
            case 1:
                cout << "Que dato desea eliminar?"; cin >> fact;
                push(stack, top, MAX, fact);
            break;

            case 2:

            break;
        }

    } while (option != 3);


    getch();
    return 0;
}

//Funcion de ususario

//INSERT
void push(int stack[], int top, int& max , int fact) {
    bool flag;
    if (flag){
        cout << "Overflow (Desbordamiento de la pila)";
    } else {
        top++;
        stack[top] = fact;
    }
}

//STATUS
