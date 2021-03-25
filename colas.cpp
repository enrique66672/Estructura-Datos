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
#include <conio.h>
#define MAX 8

int main() {
    int queue[MAX];
    int option;
    do {
        cout<<"===MENU==="<<endl;
        cin>>option;

        switch (option) {
        case 1:
            break;
        default: 
            cout<<"Opcion no disponible"<<endl; 
            break;
        }
    }while(option != 5);
    return 0;
}