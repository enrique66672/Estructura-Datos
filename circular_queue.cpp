#include <iostream>
#include <conio.h>
#define MAX 8

bool isEmpty( int& );
bool isFull( int&, int& );
void printQueue( char[], int&, int& );
void pushQueue( char[], char&, int&, int&, int& );
void popQueue( char[], int&, int&, int& );
void statusQueue( int&, int&, int& );

int main() {
    char queue[ MAX ], data;
    int option, front = 0, final = 0, n = 0;

    cout << "Estatus de la cola: ";
    statusQueue( final, front, n );
    cout << "\nPosicion de frente: " << front + 1 << endl;
    cout << "Posicion de final: " << final + 1<< endl;
    cout << endl;
    
    do {
        cout << endl; 
        cout << "======MENU=====" << endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Salir (3)" << endl << endl;
        cout << "> Seleccionar: ";
        cin >> option;

        switch ( option ) {
        case 1:
            cout << "\nQue dato desea insertar? "; cin >> data;
            pushQueue( queue, data, front, final, n );
            break;
        case 2:
            popQueue( queue, front, final, n );
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

bool isEmpty( int&n ) {
    if ( n == 0 ) {
        return true;
    } else {
        return false;
    } 
}

bool isFull( int&n ) {
    if ( n == MAX ) {
        return true;
    } else {
        return false;
    }
}

void printQueue( char queue[], int&front, int&final, int&n ) {
    if ( !isEmpty( n ) ) {
        if ( ( front > 0 ) && ( final > front ) ) {
            for ( int i = 0; i < front; i++ ) {
                cout << " | " << " " << " | ";
            }  
        }
        if ( ( front > 0 ) && ( final == front ) ) {
            for ( int i = 0; i < front; i++ ) {
                cout << " | " << " " << " | ";
            }
        }        
        if ( front <= final ) {
            for ( int i = front; i <= final; ++i ) {
                cout << " | " << queue[i] << " | ";
            }
        } else if ( final < front ) {
            for ( int i = 0; i < MAX; i++ ) {
                if ( i <= final ) {
                    cout << " | " << queue[i] << " | ";
                }
                if ( ( i > final ) && ( i < front ) ) {
                    cout << " | " << " " << " | ";
                }
                if ( ( i >= front ) && ( front < MAX ) ) {
                    cout << " | " << queue[i] << " | ";
                }    
            }
        } 
        
    } else {
        cout << "Nada que mostrar" << endl;
    }
    
}

void pushQueue( char queue[], char&data, int&front, int&final, int&n ) {

    if ( isFull( n ) ) {
        cout << "Desbordamiento" << endl;
    } else {
        final = ( front + n ) % MAX;
        queue[ final ] = data;
        n++;
    }
    cout << endl;
    cout << "Estatus de la cola: ";
    statusQueue( final, front, n );
    cout << endl;
    //Mostrar información del dato ingresado y posición de frente y final
    cout << "Dato ingresado: " << data << endl;
    cout << "Posicion de frente: " << front + 1 << endl;
    cout << "Posicion de final: " << final + 1 << endl;
    printQueue( queue, front, final, n );
    cout << endl;
    
}

void popQueue( char queue[], int&front, int&final, int&n ) {
    cout << "\nEstatus de la cola: ";
    statusQueue( final, front, n );

    //mostrar dato de salida
    front = ( front + 1 ) % MAX;
    n--;
    
    cout << endl;
    cout << "Estatus de la cola: ";
    statusQueue( final, front, n );
    cout << endl;
    //Mostrar información del dato ingresado y posición de frente y final
    cout << "Dato eliminado: " << queue[front] << endl;
    cout << "Posicion de frente: " << front + 1 << endl;
    cout << "Posicion de final: " << final + 1 << endl;
    printQueue( queue, front, final, n ); 
    cout << endl;       
}

void statusQueue( int&front, int&final, int&n ) {
    if ( n == 0 ) {
        cout << "Vacia" << endl;
    } else if ( ( n > 0 ) && ( n < MAX ) ) {
        cout << "Neutra" << endl;
    } else {
        cout << "Llena" << endl;
    }    
}