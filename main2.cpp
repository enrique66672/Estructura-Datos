#include<iostream>
#include<conio.h>
#define MAX 8

void push(int [], int&, int, int);
void pop(int[], int&, int);
void printStack(int [], int&); 
void showStatus(int&, int);
bool fullStack(int[], int, int);
bool emptyStack(int[], int);

int main() {

    int option, stack[MAX], top = -1, fact;

    do{
        cout << ">>>>  PILAS   <<<<" << endl << endl << endl;
        cout << "Estado de la pila: "; showStatus(top, MAX);
        
        cout << endl << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Eliminar Datos Repetidos (3)"
        cout << "> Cerrar Programa (4)" << endl <<endl;
        cout << "> Seleccionar: "; cin >> option;

        

        
        switch(option) {
            case 1:
                cout << "\nQue dato desea insertar?"; cin >> fact;
                push(stack, top, MAX, fact);
            break;

            case 2:
        			pop(stack, top, fact);
            break;

            case 3:
        			//INSERTAR FUNCION
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
        cout << "Desbordamiento - Pila llena" << endl;
    } else {
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

	flag = emptyStack(stack, top);

	if (flag == true) cout<<"subdesbordamiento - Pila vacia"<<endl;
	else {
		data = stack[top];
		top--;
        printStack(stack, top);
	}
}

//FULL STACK
bool fullStack(int stack[], int top, int max) {
	if (top == max - 1) return true;
	else return false;
}

//EMPTY STACK
bool emptyStack(int stack[], int top) {
	if (top == -1) return true;
	else return false;
}

//PRINTSTACK
void printStack(int stack[], int &top) {

    for (int i = 0; i <= top; i++){
        cout << " | " << stack[i] << " | ";
    }
}

//SHOW STATUS

void showStatus(int &top, int max) {
    //Empty stack
    if (top == -1) {
        cout << "Pila vacia";
    } else if (top > -1 && top < max - 1) {
        cout << "Pila neutra";
    } else {
        cout << "Pila llena";
    }

}
