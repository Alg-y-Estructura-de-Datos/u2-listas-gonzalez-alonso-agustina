/*Utiliza la clase ListaDoble para gestionar una lista de estudiantes, donde cada estudiante
tiene un nombre (cadena de caracteres) y una edad (entero). Implementa las siguientes
funcionalidades:
1. Agregar Estudiantes:
○ Usa los métodos de ListaDoble para agregar varios estudiantes a la lista.
Debes insertar al menos cinco estudiantes con nombres y edades diferentes.
2. Mostrar Estudiantes:
○ Implementa una función que recorra la lista y muestre todos los estudiantes en
orden. Utiliza el método imprimir() de ListaDoble.
3. Buscar un Estudiante por Nombre:
○ Implementa una función que busque un estudiante por su nombre. Utiliza el
método getDato(int pos) para acceder a los datos de los nodos y busca al
estudiante en la lista.
4. Eliminar un Estudiante por Nombre:
○ Implementa una función que elimine un estudiante por su nombre. Utiliza los
métodos getDato(int pos) y remover(int pos) para encontrar y
eliminar al estudiante de la lista.
5. Contar Estudiantes:
○ Usa el método getTamanio() para contar el número de estudiantes en la lista
y muestra el resultado.
*/
#include <iostream>
#include "Lista/ListaDoble.h"
using namespace std;

class Estudiantes {
public:
    string nombre;
    int edad;

    Estudiantes(): nombre(), edad(){}
    Estudiantes(const string &n,const int &e): nombre(n), edad(e){}

    friend ostream& operator<<(ostream &os, const Estudiantes &c) {
        os << "Nombre: " << c.nombre << ", Telefono: " << c.edad;
        return os;
    }

    bool operator==(const Estudiantes& other) const {
        return nombre == other.nombre;
    }

};
int main (){
    cout << "Ejercicio N 7 " << endl;


    return 0;
}