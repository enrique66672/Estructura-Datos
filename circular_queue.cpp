#include <iostream>
#include <conio.h>
#define MAX 8

bool isEmpty(int&front, int&final) {
    if (final == -1) {
        return true;
    }else {
        return false;
    }
}

int getElements(char queue[], int&front, int&final) {
    if (isEmpty(front, final)) {
        return 0;
    }
    if (front < final) {
        return (final - front + 1);
    }else {
        return ((MAX - front) + (final + 1));
    }
}

bool isFull(char queue[], int&front, int&final) {
    if (getElements(queue, front, final) == MAX) {
        return true;
    }else {
        return false;
    }
}

void printQueue(char queue[], int&front, int&final) {
    if (!isEmpty(front, final)) {
        if (front <= final) {
            for (int i = front; i <= final; ++i) {
                cout << " | " << queue[i] << " | ";
            }
        }else {
            for ( int i = 0; i < MAX; i++ ) {
                if ( i <= final ) {
                    cout << " | " << queue[i] << " | ";
                }
                if ( (i > final) && (i < front) ) {
                    cout << " | " << " " << " | ";
                }
                if (i >= front ) {
                    cout << " | " << queue[i] << " | ";
                }
            }
        }
    }
}

void pushQueue(char queue[], char& data, int&front, int&final) {
    if (!isFull(queue, front, final)) {
        if (isEmpty(front, final)) {
            front++;
        }

        if (final == (MAX - 1) || final == -1) {
            final = 0;
        }else {
            final++;            
        }
        queue[final] = data;
        /* Mostrar mensajes de datos*/
    }else {
        cout<<"Desbordamiento en la cola"<<endl;
    }
    printQueue(queue, front, final);
}

void popQueue(char queue[], int&front, int&final) {
    if (isEmpty(front, final)) {
        cout<<"Subdesbordamiento en la cola"<<endl;
    }else{
        // Mostrar elemento borrado
        if (front == final) {
            cout<<"elementos: "<<getElements(queue, front, final)<<endl;
            front = -1;
            final = -1;
        }else if (front == MAX) {
            front = 0;
        } else {
            front++;
        }
    }
    printQueue(queue, front, final);
}

void statusQueue(char queue[], int&front, int&final) {
    if (isEmpty(front, final)) {
        cout<<"Vacia"<<endl;
    }else if (isFull(queue, front, final)) {
        cout<<"Llena"<<endl;
    }else{
        cout<<"Neutra"<<endl;
    }
}

int main() {
    char queue[MAX], data;
    int option, front = -1, final = -1;

    do {
        cout << "Estatus de la cola: " << endl;
        statusQueue( queue, final, front );
        cout << "======MENU=====" << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Salir (3)" << endl <<endl;
        cout << "> Seleccionar: ";
        cin>>option;

        switch ( option ) {
        case 1:
            cout << "\nQue dato desea insertar? "; cin >> data;
            pushQueue( queue, data, front, final );
            break;
        case 2:
            popQueue( queue, front, final );
            break;
        case 3: break;
        default:
            cout << "\nOpcion no disponible" << endl;
            break;
        }
    } while ( option != 3 );
    getch();
    return 0;
}