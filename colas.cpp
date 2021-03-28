/*
Simular la estructura COLA SIMPLE en un arreglo unidimensional.
La capacidad máxima de la COLA es de 8 elementos
Mostrar el estado de la estructura después de cada operación (insertar/eliminar)
Mostrar el estado de FRENTE y FINAL después de realizar inserciones y eliminaciones
Contemplar los casos de Cola llena, cola vacía, desbordamiento, subdesbordamiento.
Documentar el funcionamiento de la estructura en el código
Enviar un solo archivo por equipo
Enviar el archivo .cpp
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define MAX 8
bool fullQueue(int &final) {
    if(final == MAX) {
        return true;
    } else {
        return false;
    }
}
void printQueue(int queue[], int &front, int &final) {
    for (int i = front; i < final; i++) {
        cout << " | " << queue[i] << " | ";
    }
}

void pushQueue(int queue[], int data, int &front, int &final) {
    bool flag;

    flag = fullQueue(final);

    if (flag) {
        cout << "Overflow - Cola llena" << endl << endl;
    } else {
        queue[final] =  data;
        final++;

        //Print Queue
        printQueue(queue, front, final);

        cout << endl << endl;
    }
}

int main() {
    int queue[MAX];
    int option, front = 0, final = 0, data;
    do {
        cout << "Estatus de la cola: " << /*PONER FUNCION ESTATUS*/<< endl;
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
        default:
            cout<<"Opcion no disponible"<<endl;
            break;
        }
    }while(option != 3);
    return 0;
}