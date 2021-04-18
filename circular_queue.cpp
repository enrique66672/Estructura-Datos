#include <iostream>
#include <conio.h>
#define MAX 8

bool fullQueue(int &final, int& front) {
    if(((final == MAX) && (front == 0)) || ((final+1) == front)) {
        return true;
    } else {
        return false;
    }
}

bool emptyQueue( int &front, int &final ) {

    /*
    inicio = 1
    final = 0

    0 1 2 3 4 5 
    x b c d e f
    */ 
   if (front == final){
       return true;
   } else {
       return false;
   }
   
}

int countElements( char queue[], int &front, int &final ) {
    int elements = 0;
    if ((front < final)) {
        for ( int i = front; i < final; i++ ) {
            elements++;
        }
    } else {
        for ( int i = 0; i < MAX; i++ ) {
            if ( queue[i] < final ) {
                elements++;
            }
            if (queue[i] >= front ) {
                elements++;
            }
        }
    } 
    return elements;
}

void statusQueue( char queue[], int& final, int& front ) {
    if (  final == front ) {
        cout << "Cola Vacio" << endl << endl;
    } else if ( (countElements(queue, front, final) < MAX) && (countElements(queue, front, final) != 0) ) {
        cout << "Cola Neutro" << endl << endl;
    } else if ( ((final == MAX) && (front == 0)) || ( (final + 1) == front) )  {
        cout << "Cola Llena" << endl << endl;
    }
}

void printQueue( char queue[], int &front, int &final ) {
    if ((front < final)) {
        for ( int i = front; i < final; i++ ) {
            cout << " | " << queue[i] << " | ";
        }
    } else {
        for ( int i = 0; i < MAX; i++ ) {
            if ( queue[i] < final ) {
                cout << " | " << queue[i] << " | ";
            }
            if ( (queue[i] > final) && (queue[i] < front) ) {
                cout << " | " << " " << " | ";
            }
            if (queue[i] >= front ) {
                cout << " | " << queue[i] << " | ";
            }
        }
    }
}

void pushQueue( char queue[], char data, int &front, int &final) {
    if ( fullQueue(final, front) ){
        cout << "Desbordamiento en su cola" << endl;
    } else if ( final == MAX ) {
        final = 0;

        queue[final] = data;
        final++;
    } else {
        queue[final] = data;
        final++;
    }

    printQueue( queue, front, final );
    cout << endl << endl;
}

void popQueue( char queue[], int& front, int& final ) { //AQUI XDXDXD
    if ( emptyQueue(front, final) ) {
        cout << "Subdesbordamiento en su cola" << endl;
    } else {
        front++;
    }
    printQueue(queue, front, final);
}

int main() {
    char queue[MAX], data;
    int option, front = 0, final = 0;

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