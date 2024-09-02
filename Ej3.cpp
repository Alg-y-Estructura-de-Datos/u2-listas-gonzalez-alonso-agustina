/*Ejercicio N°3
Implementar una función que intercambie los elementos entre 2 listas de números enteros que
recibe como parámetros. Si los tamaños de las listas son distintos, igual debe cambiar los datos
y cambiarían los tamaños de cada lista. Ejemplo sea lista1= 15->1->8->35->40->25->12 y lista2=
3->4->912->45->66 al ejecutar la función quedarían lista1= 3->4->912->45->66 y lista2=15->1->8-
>35->40->25->12.*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void intercambiar (Lista <int> &lista1, Lista <int> &lista2){
    Lista <int> aux1, aux2;

    // Copiar elementos de lista1 a aux1
    for (int i = 0; i < lista1.getTamanio(); i++) {
        aux1.insertarUltimo(lista1.getDato(i));
    }

    // Copiar elementos de lista2 a aux2
    for (int i = 0; i < lista2.getTamanio(); i++) {
        aux2.insertarUltimo(lista2.getDato(i));
    }

    // Vaciar las listas originales
    lista1.vaciar();
    lista2.vaciar();

    // Insertar los elementos de aux2 en lista1
    for (int i = 0; i < aux2.getTamanio(); i++) {
        lista1.insertarUltimo(aux2.getDato(i));
    }

    // Insertar los elementos de aux1 en lista2
    for (int i = 0; i < aux1.getTamanio(); i++) {
        lista2.insertarUltimo(aux1.getDato(i));
    }
}

int main() {
    cout << "Ejercicio N° 3" << endl;

    Lista <int> lista1;
    Lista <int> lista2;
    int n1,n2, m1,m2;

    cout << "Ingrese el tamanio de la lista 1" << endl;
    cin >> n1;

    cout << "Ingrese los elementos de la lista 1" << endl;
    for (int i = 0; i < n1; ++i) {
        cin >> m1;
        lista1.insertarUltimo(m1);
    }

    cout << "Ingrese el tamanio de la lista 1" << endl;
    cin >> n2;

    cout << "Ingrese los elementos de la lista 1" << endl;
    for (int i = 0; i < n1; ++i) {
        cin >> m2;
        lista2.insertarUltimo(m2);
    }

    intercambiar(lista1,lista2);
    cout << "Lista 1: ";
    lista1.print();
    cout << "Lista 2: ";
    lista2.print();

    return 0;
}
