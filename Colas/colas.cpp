// by Juan Gerardo Molina Garcia and Miguel Enrique Roque Ramos
#include <iostream>
#include <conio.h>
#define MAX 8

/*
Realiza la validación para comprobar si se a alacanzado el número máximo
de elementos establecidos para la estrcuturas 
*/
bool fullQueue(int &final) {
    if(final == MAX) {
        return true;
    } else {
        return false;
    }
}

/*
Realiza la validación para comprobar si se sobrepasa el frente al final
ya que en dado caso ocurre un subdesbordamiento en la estructura
*/
bool emptyQueue(int& front, int& final) {
    if(front < final) {
        return false; 
    } else {
        return true;
    }
}

/*
Muestra un mensaje con el estado de la estructura después de cada operación
en base a los valores que tengan [front] y [final]
*/
void statusQueue(int& final, int& front) {
    if(final == 0 || final == front) {
        cout<<"Cola Vacio"<<endl<<endl;
    } else if(final < MAX) {
        cout<<"Cola Neutro"<<endl<<endl;
    } else if(final == MAX) {
        cout<<"Cola Llena"<<endl<<endl;
    }
}


//Impresión de la estructura
void printQueue(int queue[], int &front, int &final) {
    for (int i = front; i < final; i++) {
        cout << " | " << queue[i] << " | ";
    }
}

/*
Insetar los datos, primero recibe la validación de [fullQueue] y evalua
sí la cola está llena no se insertará y notificará al usuario
sí la cola no está llena entonces coloca el dato ingresado en la estructura
muestra la información de que valor y en que posición fue colocado
e imprime la cola
*/
void pushQueue(int queue[], int data, int &front, int &final) {
    bool flag;

    flag = fullQueue(final);

    if (flag) {
        cout << "\nDesbordamiento en cola, imposible insertar dato" << endl << endl;
    } else {
        queue[final] =  data;
        final++;
        cout<<"Elemento insertado: "<<data<<"\nPosicion de final:"<<final<<endl<<endl;
    }
    printQueue(queue, front, final);
    cout << endl << endl;
}

/*
Elimina un dato de la estructura, recibe la validación de [emptyQueue] 
sí está vacia no se elimina nada y se notifica al usuario un subdesbordamiento
sí no está vacia elimina el elemento, muestra el dato y la posición de [front]
e imprime la cola
*/
void popQueue(int queue[], int& front, int& final, int data) {
    bool flag;

    flag = emptyQueue(front, final);

    if(flag) {
        cout<<"\nSubdesbordamiento en cola, imposible eliminar dato"<<endl;
    } else {
        data = queue[front];
        cout<<"Elemento eliminado: "<<data<<"\nPosicion de frente: "<<(front + 1)<<endl;
        front++;
    }
    printQueue(queue, front, final);
    cout << endl << endl;
}

/*
Método principal, creamos todas las variables usadas en el programa
Antes de mostrar el menú, mostramos el estado de la cola
Según se seleccione el caso podemos insertar o eliminar datos, con
sus respectivas restricciones, lo podremos acceder a las operaciones 
indefinidamente hasta que se desee salir del programa.
*/
int main() {
    int queue[MAX];
    int option, data, front = 0, final = 0;

    do {
        cout << "Estatus de la cola: " << endl;
        statusQueue(final, front);
        cout<<"===MENU==="<<endl;
        cout << "> Insertar Datos (1)" << endl;
        cout << "> Eliminar Datos (2)" << endl;
        cout << "> Salir (3)" << endl <<endl;
        cout << "> Seleccionar: ";
        cin>>option;

        switch (option) {
        case 1:
            cout << "\nQue dato desea insertar? "; cin >> data;
            pushQueue(queue, data, front, final);
            break;
        case 2:
            popQueue(queue, front, final, data);
            break;
        case 3: break;
        default:
            cout<<"\nOpcion no disponible"<<endl;
            break;
        }
    }while(option != 3);
    getch();
    return 0;
}