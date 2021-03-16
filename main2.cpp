#include<iostream>
#include<conio.h>
#define MAX 8

//Funcion de ususario

//PRINTSTACK
void printStack(int stack[], int &top) {

    for (int i = 0; i <= top; i++) {
        cout << " | " << stack[i] << " | ";
    }
}

//FULL STACK
bool fullStack(int stack[], int top, int max) {
	if (top == max - 1){
        return true;
    } else{
        return false;
    } 
}

//INSERT
void push(int stack[], int &top, int max , int fact) {
    bool flag;

    flag = fullStack(stack, top, max);

    if (flag) {
        cout << "Desbordamiento - Pila llena" << endl;
    } else {
        top++;
        stack[top] = fact;

        //Stack
        printStack(stack, top);
        cout << endl << endl;
    }
}

//EMPTY STACK
bool emptyStack(int stack[], int top) {
	if (top == -1) return true;
	else return false;
}

//POP
void pop(int stack[], int&top, int data) {
	bool flag;

	flag = emptyStack(stack, top);

	if (flag == true) {
        cout << "Subdesbordamiento - Pila vacia" << endl;
    } else {
		data = stack[top];
		top--;
        printStack(stack, top);
        cout << endl << endl;
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

//REMOVE DUPLICATED
void removeDuplicate(int stack[], int &top) {
    bool flag;

    flag = emptyStack(stack, top);

    if(flag) {
        cout << "Subdesbordamiento - Pila Vacia" << endl;
    } else {
        //Comprobar si hay elementos repetidos
        int i = 0;
        bool flagTwo = false;
        do{
            if(stack[i] == stack[i + 1]) {
                flagTwo = true; //Porque si hay elementos repetidos 
            } 
            i++;

        } while(i != top);

        if(flagTwo == false) {
            //Significa que no encontro elementos iguales
            cout << "No hay elementos repetidos" << endl;
        } 
            int stackTwo[MAX];
            int aux = -1;

            for (int i = top; i >= 0; i--) {
                if (stack[i] != stack[i-1]) {
                    stackTwo[aux + 1] = stack[i];
                    aux ++;
                }
            }

            top = 0;
            //int stackThree[MAX];
            while(top <= aux) {
                stack[top] = stackTwo[aux - top];
                top++;
            }
            top--;

            printStack(stack, top);

            cout << endl << endl; 
    }
}

int main() {

    int option, stack[MAX], top = -1, fact;

    do{
        cout << ">>>>  PILAS   <<<<" << endl << endl << endl;
        cout << "Estado de la pila: "; showStatus(top, MAX);

        cout << endl << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Eliminar Datos Repetidos (3)" << endl;
        cout << "> Cerrar Programa (4)" << endl <<endl;
        cout << "> Seleccionar: "; cin >> option;

        switch (option) {
            case 1:
                cout << "\nQue dato desea insertar? "; cin >> fact;
                push(stack, top, MAX, fact);
            break;

            case 2:
        		pop(stack, top, fact);
            break;

            case 3:
        		removeDuplicate (stack, top);        
            break;
        }

    } while (option != 4);

    getch();
    return 0;
}

