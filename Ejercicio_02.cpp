//Created by: Roque Ramos Miguel Enrique and Molina Garcia Juan Gerardo

#include<iostream>
#include<conio.h>
#define MAX 8
//Funcion de ususario
// Show Status
void showStatus(int &top) {
    //Empty stack
    if (top == -1) {
        cout << "Pila vacia";
    } else if (top > -1 && top < (MAX - 1)) {
        cout << "Pila neutra";
    } else {
        cout << "Pila llena";
    }

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

//FULL STACK
bool fullStack(int top) {
	if (top == (MAX - 1)) {
        return true;
    } else {
        return false;
    }  
}

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

//EMPTY STACK
bool emptyStack(int top) {
	if (top == -1) return true;
	else return false;
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

//REMOVE DUPLICATED
void removeDuplicate(int stack[], int &top) {
    bool flag;

    flag = emptyStack(top);

    if(flag) {
        cout << "\nPila Vacia - No se puede hacer esta operacion" << endl << endl;
    } else {
        if(stack[top] == stack[top-1]) {
        top = top -2;
        }else {
            top--;
        }
        printStack(stack, top);
        cout << endl << endl; 
    }
}

int main() {

    int option, stack[MAX], top = -1, fact;

    do{
        cout << ">>>>  PILAS   <<<<" << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Remover elementos repetidos (3)" << endl;
        cout << "> Cerrar Programa (4)" << endl <<endl;
        cout << "> Seleccionar: "; cin >> option;

        switch (option) {
            case 1:
                cout << "\nQue dato desea insertar? "; cin >> fact;
            	push(stack, top,fact);
                break;
            case 2:
        		pop(stack, top, fact);
                break;
            case 3:
            	removeDuplicate (stack, top);
                break;
            case 4: break;
            default: cout<<"Opcion no disponible"<<endl;
        }

    } while (option != 4);

    getch();
    return 0;
}

