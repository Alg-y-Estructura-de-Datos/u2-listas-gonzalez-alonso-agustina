/*Ejercicio N°2
Implementar una función que recibe una lista de números enteros y un número entero “n” y
que modifique la lista borrando todos los elementos de la lista que tengan el número “n”.
Imprimir la lista antes de hacer el llamado a la función y luego del llamado a la función para
mostrar que la lista original cambió. ej: lista: 1->2->3->4->5->3->7->8->3->10 con n=3 debe pasar
con la función a 1->2->4->5->7->8->10*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;

void funcion (Lista<int> &lista, int n, int& m){

    for (int i=0 ; i<m; i++){
        if (lista.getDato(i) == n){
            lista.remover(i);
            m--;
        }
    }
}

int main() {
    cout << "Ejercicio N° 2" << endl;

    Lista <int> lista;
    int m,d,n;

    cout << "Ingrese la cantidad de numeros en la lista" << endl;
    cin >> m;

    for (int i=0 ; i<m ; i++){
        cout << "Ingrese los elementos" << endl;
        cin >> d;

        lista.insertarUltimo(d);
    }

    cout << "Ingrese el numero que quiere eliminar" << endl;
    cin >> n;

    lista.print();
    funcion(lista,n,m);
    lista.print();

    return 0;
}
