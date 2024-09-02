/*Ejercicio N°9: APLICACIÓN DE DOBLE ENLAZADA.
Gestión de Historial de Navegación en un Navegador
Desarrolla un programa que simule el historial de páginas web visitadas en un navegador
utilizando una lista doblemente enlazada. El programa debe permitir al usuario retroceder y
avanzar entre las páginas visitadas, mostrando sus direcciones en pantalla.
Requisitos:
1. Estructura de Datos:
○ Usa el concepto de una lista doblemente enlazada para mantener el historial de
páginas web visitadas.
○ Cada nodo de la lista debe almacenar la URL de la página web visitada.
2. Funciones del Programa:
○ Añadir Página: Permite agregar una nueva URL al final del historial de
navegación.
○ Mostrar Histórico: Muestra todas las URLs del historial desde la más antigua a la
más reciente.
○ Retroceder: Permite al usuario retroceder a la página web visitada
anteriormente, mostrando la URL en pantalla.
○ Avanzar: Permite al usuario avanzar a la siguiente página web en el historial,
mostrando la URL en pantalla.
3. Interfaz del Usuario:
○ La interfaz debe ser de línea de comandos y debe permitir al usuario ingresar
URLs y navegar a través del historial usando comandos simples.
○ Implementa un menú para que el usuario pueda elegir entre las opciones
disponibles: añadir una página, mostrar el historial, retroceder, avanzar, y salir
del programa*/

#include <iostream>
#include "Lista/ListaDoble.h"
using namespace std;

void avanzarPag (ListaDoble<string> &lista, int posicion){

    if ( posicion >= 0 && posicion < lista.getTamanio()-1){
        posicion++;
        cout << lista.getDato(posicion);
    }
    else {
        cout << "No hay paginas para avanzar" << endl;
    }
}

void retroceder (ListaDoble<string> &lista, int posicion){
    if( posicion > 0){
        posicion--;
        cout << lista.getDato(posicion);
    }
    else{
        cout << "No hay paginas anteriores en el historial " << endl;
    }
}

void mostrar (ListaDoble<string> &lista){
    lista.imprimir();
}

void aniadirPag (ListaDoble<string> &lista, int posicion){
    string url;
    cout << "Ingrese el url de la pagina " << endl;
    getline(cin,url);

    lista.insertarUltimo(url);

    if (lista.getTamanio() == 1) {
        posicion = 0;
    } else {
        // Actualiza la posición actual a la última página añadida
        if( posicion != (lista.getTamanio() - 2)){
            return;
        }else{
             lista.getTamanio() - 1;
        }
    }
}

int main (){
    cout << "Ejercicio N 9" << endl;

    ListaDoble<string> lista;
    int opcion=1;
    int posicion = -1;

    do {
        cout << "Menu:" << endl;
        cout << "1. Anadir pagina" << endl;
        cout << "2. Mostrar historial" << endl;
        cout << "3. Retroceder" << endl;
        cout << "4. Avanzar" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                aniadirPag(lista, posicion);
                break;
            case 2:
                mostrar(lista);
                break;
            case 3:
                retroceder(lista, posicion);
                break;
            case 4:
                avanzarPag(lista, posicion);
                break;
            case 5:
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
                break;
        }

    }while (opcion!=5);

    return 0;
}