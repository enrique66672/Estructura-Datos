#include<iostream>
#include<conio.h>
#define MAX 8

void push(int [], int&, int, int);
void pop(int[], int&, int);
bool fullStack(int[], int, int);
bool emptyStack(int[], int);

int main() {

    int option, stack[MAX], top = -1;
    char fact;

    do{
        cout << ">>>>  PILAS   <<<<" << endl << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Cerrar Programa (3)" << endl;
        cout << "> Seleccionar: ";

        cin >> option;
        switch(option) {
            case 1:
                cout << "Que dato desea eliminar?"; cin >> fact;
                push(stack, top, MAX, fact);
            break;

            case 2:
        			pop(stack, top, fact);
            break;
        }

    } while (option != 3);


    getch();
    return 0;
}

//Funcion de ususario

//INSERT
void push(int stack[], int &top, int max , int fact) {
    bool flag;

    flag = fullStack(stack, top, max);

    if (flag){
        cout << "Overflow (Desbordamiento de la pila)";
    } else {
        top++;
        stack[top] = fact;
    }
}

//POP
void pop(int stack[], int&top, int data) {
	bool flag;
	
	flag = emptyStack(stack, top);

	if (flag == true) cout<<"subdesbordamiento - Pila vacia"<<endl;
	else {
		data = stack[top];
		top--;
	}
}

bool fullStack(int stack[], int top, int max) {
	if (top == max) return true;
	else return false;
}

bool emptyStack(int stack[], int top) {
	if (top == -1) return true;
	else return false;
}

//STATUS
