/*Crea un programa que gestione una lista circular de contactos. Cada contacto contiene un
nombre (cadena de caracteres) y un número de teléfono (cadena de caracteres).
Tareas
1. Agregar Contactos:
○ Usa los métodos de CircList para agregar varios contactos a la lista. Deberás
insertar al menos cinco contactos con nombres y números de teléfono distintos.
2. Mostrar Contactos:
○ Implementa una función que recorra la lista circular y muestre todos los
contactos en orden. Usa el método imprimir() de CircList.
3. Buscar un Contacto por Nombre:
○ Implementa una función que busque un contacto por su nombre. Usa el método
getDato(int pos) para acceder a los datos de los nodos y busca el
contacto en la lista.
4. Eliminar un Contacto por Nombre:
○ Implementa una función que elimine un contacto por su nombre. Deberás usar
los métodos getDato(int pos) y eliminarPorValor(T valor) (supón
que eliminarPorValor está implementado, aunque no esté explícito en el
código proporcionado).
5. Contar Contactos:
○ Usa el método getTamanio() para contar el número de contactos en la lista y
muestra el resultado.*/

#include <iostream>
#include "Lista/CircList.h"
using namespace std;

class Contacto{
public:
    string nombre;
    string tel;

    Contacto(): nombre(), tel(){}
    Contacto(const string &n,const string &t): nombre(n), tel(t){}

    friend ostream& operator<<(ostream &os, const Contacto &c) {
        os << "Nombre: " << c.nombre << ", Telefono: " << c.tel;
        return os;
    }

    bool operator==(const Contacto& other) const {
        return nombre == other.nombre;
    }
};

void mostrarContactos( CircList<Contacto> &lista) {
    if (lista.esVacia()) {
        cout << "La lista de contactos está vacía." << endl;
        return;
    }
    lista.imprimir();
}

void buscarContacto (CircList<Contacto> &lista, string &nombre){

    for (int i = 0; i < lista.getTamanio(); ++i) {
        Contacto n=lista.getDato(i);
        if (n.nombre == nombre){
            cout << "Contacto encontrado: " << n << endl;
        }
        else {
            cout << "Contacto no encontrado" << endl;
        }
    }
}

void eliminarContacto (CircList<Contacto> &lista, string& nombre){
    for (int i = 0; i < lista.getTamanio(); ++i) {
        Contacto n=lista.getDato(i);
        if (n.nombre == nombre){
            lista.eliminarPorValor(n);
        }
        else {
            cout << "Contacto no encontrado" << endl;
        }
    }
}

int main () {
    cout << "Ejercicio N 6" << endl;

    CircList <Contacto> lista;
    int opcion;
    string nombre;

    lista.insertarUltimo(Contacto("Agus", "46031879"));
    lista.insertarUltimo(Contacto("Bettina", "24614486"));
    lista.insertarUltimo(Contacto("Magdalena", "2305757"));
    lista.insertarUltimo(Contacto("Francisco", "123456"));
    lista.insertarUltimo(Contacto("Ignacio", "789012"));

    do{
        cout << "\nMenú :" << endl;
        cout << "1. Mostrar contactos" << endl;
        cout << "2. Buscar contacto" << endl;
        cout << "3. Eliminar contacto" << endl;
        cout << "4. Cantidad de contactos" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarContactos(lista);
                break;
            case 2:
                cout << "Ingrese el contacto a buscar" << endl;
                buscarContacto(lista,nombre);
                break;
            case 3:
                cout << "Ingrese el nombre del contacto a eliminar" << endl;
                cin >> nombre;
                eliminarContacto(lista, nombre);
                break;
            case 4:
                cout << lista.getTamanio() << endl;
                break;
        }
    }while(opcion != 4);
    return 0;
}
