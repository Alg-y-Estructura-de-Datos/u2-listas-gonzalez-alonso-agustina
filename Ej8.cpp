#include <iostream>
#include <string>

// Nodo de la lista circular simplemente enlazada
struct Nodo {
    std::string frase;
    Nodo* siguiente;
};

// Clase para gestionar la lista circular
class ListaCircular {
private:
    Nodo* ultimo;

public:
    ListaCircular() : ultimo(nullptr) {}

    // Agregar una nueva frase a la lista
    void agregarFrase(const std::string& frase) {
        Nodo* nuevo = new Nodo();
        nuevo->frase = frase;
        if (ultimo == nullptr) {
            nuevo->siguiente = nuevo;
            ultimo = nuevo;
        } else {
            nuevo->siguiente = ultimo->siguiente;
            ultimo->siguiente = nuevo;
            ultimo = nuevo;
        }
    }

    // Eliminar una frase específica de la lista
    void eliminarFrase(const std::string& frase) {
        if (ultimo == nullptr) return;

        Nodo* actual = ultimo->siguiente;
        Nodo* anterior = ultimo;

        do {
            if (actual->frase == frase) {
                if (actual == ultimo) {
                    if (actual == ultimo->siguiente) {
                        delete actual;
                        ultimo = nullptr;
                    } else {
                        anterior->siguiente = actual->siguiente;
                        delete actual;
                        ultimo = anterior;
                    }
                } else {
                    anterior->siguiente = actual->siguiente;
                    delete actual;
                }
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != ultimo->siguiente);
    }

    // Mostrar las frases de manera circular
    void mostrarFrases() const {
        if (ultimo == nullptr) return;

        Nodo* actual = ultimo->siguiente;
        do {
            std::cout << actual->frase << std::endl;
            actual = actual->siguiente;
        } while (actual != ultimo->siguiente);
    }
};

int main() {
    ListaCircular monitor;

    // Agregar frases al monitor
    monitor.agregarFrase("Anuncio 1: ¡Oferta especial!");
    monitor.agregarFrase("Anuncio 2: ¡Descuentos del 50%!");
    monitor.agregarFrase("Anuncio 3: ¡Nuevos productos disponibles!");

    // Mostrar las frases circularmente
    std::cout << "Mostrando frases del monitor publicitario:" << std::endl;
    monitor.mostrarFrases();

    // Eliminar una frase
    monitor.eliminarFrase("Anuncio 2: ¡Descuentos del 50%!");

    // Mostrar las frases nuevamente
    std::cout << "\nDespués de eliminar una frase:" << std::endl;
    monitor.mostrarFrases();

    return 0;
}
