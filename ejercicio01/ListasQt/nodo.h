#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(T d) : dato(d), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        while (cabeza) {
            eliminarCabeza();
        }
    }

    void agregar(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void eliminarCabeza() {
        if (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void imprimir() const {
        Nodo<T>* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }
};

#endif // NODO_H
