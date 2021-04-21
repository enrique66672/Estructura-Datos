// by Juan Gerardo Molina Garcia and Miguel Enrique Roque Ramos
#include <iostream>
#include <conio.h>
#define MAX 8

bool isEmpty( int& );
bool isFull( int&, int& );
void printQueue( char[], int&, int& );
void pushQueue( char[], char&, int&, int&, int& );
void popQueue( char[], int&, int&, int& );
void statusQueue( int& );

/**
 * Metodo principal, creamos todas las variables usadas en el programa
 * Antes de mostrar el menu, mostramos el estado de la cola
 * Segun se seleccione el caso podemos insertar o eliminar datos, con
 * sus respectivas restricciones, lo podremos acceder a las operaciones 
 * indefinidamente hasta que se desee salir del programa.
*/
int main() {
    char queue[ MAX ], data;
    int option, front = 0, final = 0, n = 0; // n Son los elementos en la estructura

    cout << "Estado de la cola: ";
    statusQueue( n );
    cout << "\nPosicion de frente: " << front << endl;
    cout << "Posicion de final: " << final << endl;
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

/**
 * Realiza la validacion para comprobar que si [n] = 0 entonces esta
 * vacia ya que en dado caso ocurre un subdesbordamiento en la estructura
*/
bool isEmpty( int&n ) {
    if ( n == 0 ) {
        return true;
    } else {
        return false;
    } 
}

/**
 * Realiza la validacion para comprobar si se a alacanzado el numero maximo
 * de elementos establecidos para la estructura 
*/
bool isFull( int&n ) {
    if ( n == MAX ) {
        return true;
    } else {
        return false;
    }
}

/**
 * Impresion de la estructura
 * Primero comprueba que haya elementos que mostrar
 * Hay mas validaciones para los casos donde el [final] este en la ultima posicion y el [front] > 0 
 * para que imprima los espacios y no perdamos la nocion de donde no hay elementos, o en el caso 
 * donde ambos valores se encuentren juntos para poder imprimir los espacios de atras para que no 
 * parezca que la estructura esta comenzando.
 * Tambien tenemos el caso de que el [front] sea menor o igual que el [final] para lo cual se imprimen 
 * los valores normales, desde [front] hasta [final], sino imprimira desde la primera posicion hasta 
 * donde se encuentre [front], y entre [front] y [final] imprimira espacios en blanco, desde [final] 
 * hasta la ultima posicion de la estructura se imprimiran los valores 
 */
void printQueue( char queue[], int&front, int&final, int&n ) {
    if ( !isEmpty( n ) ) {
        if ( (( front > 0 ) && ( final > front )) || (( front > 0 ) && ( final == front )) ) {
            for ( int i = 0; i < front; i++ ) {
                cout << " |" << " " << "| ";
            }  
        }        
        if ( front <= final ) {
            for ( int i = front; i <= final; ++i ) {
                cout << " |" << queue[i] << "| ";
            }
        } else if ( final < front ) {
            for ( int i = 0; i < MAX; i++ ) {
                if ( i <= final ) {
                    cout << " |" << queue[i] << "| ";
                }
                if ( ( i > final ) && ( i < front ) ) {
                    cout << " |" << " " << "| ";
                }
                if ( ( i >= front ) && ( front < MAX ) ) {
                    cout << " |" << queue[i] << "| ";
                }    
            }
        }   
    } else {
        cout << "\nNada que mostrar" << endl;
    } 
}

/**
 * Comienza comprobando que la cola no este llena, ya que si esta llena mostrara que hay un desbordamiento
 * en el caso de que no este llena se actualiza el valor de la posicion [final] tomando el [front] sumando el numero 
 * de elementos y despues el modulo de la suma con lo que tenemos el valor del [final] en esa posicion asignamos 
 * el dato y sumamos uno al numero de elementos.
 * Despues mostramos la informacion de la estructura y se imprime.
 * 
*/
void pushQueue( char queue[], char&data, int&front, int&final, int&n ) {
    if ( isFull( n ) ) {
        cout << "\nDesbordamiento - Imposible insertar dato" << endl;
        cout << "Estado de la cola: ";
        statusQueue( n );
        cout << endl;
    } else {
        final = ( front + n ) % MAX;
        queue[ final ] = data;
        n++;
        cout << endl;
        cout << "Estado de la cola: ";
        statusQueue( n );
        cout << endl; //Información del dato ingresado y posición de frente y final
        cout << "Dato ingresado: " << data << endl;
        cout << "Posicion de frente: " << (front + 1) << endl;
        cout << "Posicion de final: " << (final + 1) << endl << endl;
    }
    
    printQueue( queue, front, final, n );
    cout << endl; 
}

/**
 * Comienza tomando el valor de [front] suma uno y despues saca el modulo y el resultado lo almacena en [front], 
 * avanzando una posicion y reduce la cantidad de elementos en la estructura, si el numero de elementos es 0
 * actualizamos los valores de [front] y [final] a 0, ya que la estructura esta vacia.
 * Despues muestra la informacion de la estructura y la imprime.
*/
void popQueue( char queue[], int&front, int&final, int&n ) {
    if ( isEmpty(n) ) {
        cout << "\nSubdesbordamiento - Imposible borrar elementos" << endl;
        cout << "Estado de la cola: ";
        statusQueue( n );
        cout << endl;
    } else {
        front = ( front + 1 ) % MAX;
        n--;
        
        cout << endl;
        cout << "Estatus de la cola: ";
        statusQueue( n );
        cout << endl; //Información del dato ingresado y posición de frente y final
        cout << "Dato eliminado: " << queue[front] << endl;
        if ( n == 0 ) {
            front = final = 0;
            cout << "Posicion de frente: " << front << endl;
            cout << "Posicion de final: " << final << endl << endl;
        } else {
            cout << "Posicion de frente: " << (front + 1) << endl;
            cout << "Posicion de final: " << (final + 1) << endl << endl;
        }
    }    
    printQueue( queue, front, final, n ); 
    cout << endl;      
}

/**
 * En base al numero de elementos se evalua el estado de la estructura segun
 * la cantidad de elementos.
*/
void statusQueue( int&n ) {
    if ( n == 0 ) {
        cout << "Vacia" << endl;
    } else if ( ( n > 0 ) && ( n < MAX ) ) {
        cout << "Neutra" << endl;
    } else {
        cout << "Llena" << endl;
    }    
}