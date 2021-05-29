//Created by: Roque Ramos Miguel Enrique and Molina Garcia Juan Gerardo
#include<iostream>
#include<conio.h>
#define MAX 8

void push(int [], int&, int);
void pop(int[], int&, int);
void printStack(int [], int&); 
void showStatus(int&);
bool fullStack(int);
bool emptyStack(int);

int main() {
    int stack[MAX], option, fact, top = -1;

    do{
        cout << ">>>>  PILAS   <<<<" << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Cerrar Programa (3)" << endl <<endl;
        cout << "> Seleccionar: "; cin >> option;

        switch(option) {
            case 1:
                cout << "\nQue dato desea insertar?"; cin >> fact;
                push(stack, top, fact);
                break;
            case 2:
        		pop(stack, top, fact);
                break;
            case 3: break;
            default: cout<<"Opcion no disponible"<<endl;
        }
    } while (option != 3);

    getch();
    return 0;
}
//Funcion de ususario

//INSERT
void push(int stack[], int &top, int fact) {
    bool flag;

    flag = fullStack(top);

    if (flag) cout<<"\nDesbordamiento - Pila llena\n"<<endl<<endl;
    else {
        top++;
        stack[top] = fact;
        //Stack
        printStack(stack, top);
        cout << endl << endl;
    }
}

//POP
void pop(int stack[], int&top, int data) {
	bool flag;

	flag = emptyStack(top);

	if (flag) cout<<"\nsubdesbordamiento - Pila vacia\n"<<endl;
	else {
		data = stack[top];
        cout<<"Elemento eliminado: "<<data<<"\nPosicion:"<<(top+1)<<endl;
		top--;
        printStack(stack, top);
	}
}

//FULL STACK
bool fullStack(int top) {
	if (top == (MAX - 1)) return true;
	else return false;
}

//EMPTY STACK
bool emptyStack(int top) {
	if (top == -1) return true;
	else return false;
}

//PRINTSTACK
void printStack(int stack[], int &top) {
    for (int i = 0; i <= top; i++){
        cout << " | " << stack[i] << " | ";
    }

    cout << "\n\nEstado de la pila: ";
    showStatus(top);
    cout << endl << endl;
}
//SHOW STATUS

void showStatus(int &top) {
    if (top == -1) {
        cout << "Pila vacia";
    } else if (top > -1 && top < (MAX - 1)) {
        cout << "Pila neutra";
    } else {
        cout << "Pila llena";
    }
}
