/*Escribir un programa que pida al usuario una palabra o frase y la almacene en una Lista
separando letra por letra, luego pedirá al usuario una vocal que desee contar y, por último, se
debe imprimir por pantalla la lista y el número de veces que aparece la vocal en la palabra o
frase. Validar que la Lista no esté vacía y que la letra a contar que introduzca el usuario sea
una vocal.*/

#include <iostream>
#include "Lista/Lista.h"
using namespace std;


bool esvocal (char c){
    c= tolower(c);
    return c =='a'||c == 'e'|| c == 'i'|| c == 'o'|| c =='u';
}


int contarVocal (Lista<char> lista, char vocal){
    int cont = 0;

    for (int i = 0; i < lista.getTamanio(); ++i) {
        if (lista.getDato(i) == vocal ){
            cont ++;
        }
    }
    return cont;
}

int main() {

    cout << "Ejercicio N° 4" << endl;

    Lista<char> lista;
    string palabra;
    char vocal;

    cout << "Ingrese una palabra o frase" << endl;
    getline(cin,palabra);

    for (int i = 0; i < palabra.length(); ++i) {
        char c=palabra[i];
        lista.insertarUltimo(c);
    }

    if (lista.esVacia()){
        cout << "Lista vacia" << endl;
    }

    cout << "Ingrese una vocal " << endl;
    cin >> vocal;

    if (!esvocal(vocal)){
        cout << "El caracter no es una vocal " << endl;
    }

    lista.print();

    int cant= contarVocal(lista, vocal);
    cout << "Cantidad de vocales en la palabra: " << cant << endl;
    return 0;
}
