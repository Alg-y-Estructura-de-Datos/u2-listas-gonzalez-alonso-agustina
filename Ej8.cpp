/*Desarrolla un programa para gestionar un monitor publicitario que debe mostrar frases de
anuncios de manera circular. Para lograr esto, implementarás una solución utilizando una lista
circular simplemente enlazada.
Requisitos:
1. Frases de Anuncios:
○ Cada frase de anuncio será un texto simple que el monitor debe mostrar por
vez.
2. Mostrar Circularmente:
○ Las frases deben mostrarse en un formato circular, es decir, una vez que se ha
mostrado la última frase, el monitor debe volver a mostrar la primera y así
infinitamente.
3. Implementación:
○ Utiliza una lista circular simplemente enlazada para gestionar el almacenamiento
y la visualización de las frases. La lista circular debe permitir el recorrido
continuo de los elementos.
4. Operaciones Básicas:
○ Agregar Frases: Capacidad para añadir nuevas frases a la lista circular.
○ Eliminar Frases: Capacidad para eliminar frases específicas de la lista.
○ Mostrar Frases: Implementa una función para mostrar las frases en el monitor
de manera continua, recorriendo circularmente la lista e infinitamente.*/

#include <iostream>
#include "Lista/CircList.h"
#include <chrono>
#include <thread>
using namespace std;

template <typename t>
void mostrarFrases(CircList<t> lista){
    if (lista.esVacia()){
        cout << "No hay frases ingresadas" << endl;
    }
    int pos = 0;

    while (true){
        cout << lista.getDato(pos) << endl;
        pos = (pos + 1) % lista.getTamanio();

        this_thread::sleep_for(chrono::seconds(1)); // Retraso de 3 segundo
    }
}

int main () {
    cout << "Ejercicio N 8" << endl;

    CircList<string> lista;

    lista.insertarUltimo("hola");
    lista.insertarUltimo("chau");
    lista.insertarUltimo("anuncio");

    cout << "Mostrando frases de anuncios" << endl;

    mostrarFrases(lista);

    return 0;
}