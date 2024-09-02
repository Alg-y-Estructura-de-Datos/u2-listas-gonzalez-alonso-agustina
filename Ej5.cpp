/*Crear un programa que pida al usuario dar elementos a una Lista de números enteros. Luego
cree una función que reciba una lista int L1 y devuelva otra lista int L2 conteniendo los
elementos repetidos de L1. Por ejemplo, si L1 almacena los valores 5->2->7-> 2->5->5->1, debe
construirse una lista L2 con los valores 5->2. Si en L1 no hay elementos repetidos se debe
indicar al usuario que no hay elementos repetidos en L1, de lo contrario imprimir ambas listas.*/
#include <iostream>
#include "Lista/Lista.h"
using namespace std;

Lista<int> funcion(Lista<int> &l1) {
    Lista<int> l2;
    Lista<int> rep;
    Lista<int> cont;

    // Contar las ocurrencias de cada elemento
    for (int i = 0; i < l1.getTamanio(); ++i) {
        int pos = l1.getDato(i);
        bool numR = false;
        for (int j = 0; j < rep.getTamanio(); ++j) {
            if (pos == rep.getDato(j)) {
                int count = cont.getDato(j);
                cont.remover(j);
                cont.insertar(count + 1, j);
                numR = true;
                break;
            }
        }
        if (!numR) {
            rep.insertarUltimo(pos);
            cont.insertarUltimo(1);
        }
    }

    // Insertar solo los elementos repetidos en l2
    for (int i = 0; i < rep.getTamanio(); ++i) {
        if (cont.getDato(i) > 1) {
            l2.insertarUltimo(rep.getDato(i));
        }
    }

    return l2;
}

int main() {
    cout << "Ejercicio N 5" << endl;

    Lista<int> l1;
    int n, m;

    cout << "Ingrese el tamanio de la lista" << endl;
    cin >> n;

    cout << "Ingrese los elementos en la lista" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        l1.insertarUltimo(m);
    }

    Lista<int> l2 = funcion(l1);
    if (l2.esVacia()) {
        cout << "No hay elementos repetidos en la lista." << endl;
    } else {
        cout << "Lista original: ";
        l1.print();
        cout << "Lista con numeros repetidos: ";
        l2.print();
    }

    return 0;
}
