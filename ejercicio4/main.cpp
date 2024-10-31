#include <iostream>
#include <QCoreApplication>
using namespace std;

template <typename T>
class Nodo {
public:
    T data;
    Nodo<T>* izquierda;
    Nodo<T>* derecha;

    Nodo(T valor) : data(valor), izquierda(nullptr), derecha(nullptr) {}
};

template <typename T>
class Arbol {
public:
    Nodo<T>* raiz;

    Arbol() : raiz(nullptr) {}

    void insertar(T valor) {
        raiz = insertarRecursivo(raiz, valor);
    }

    void enOrden() {
        enOrdenRecursivo(raiz);
    }

private:
    Nodo<T>* insertarRecursivo(Nodo<T>* nodo, T valor) {
        if (nodo == nullptr) {
            return new Nodo<T>(valor);
        }
        if (valor < nodo->data) {
            nodo->izquierda = insertarRecursivo(nodo->izquierda, valor);
        } else {
            nodo->derecha = insertarRecursivo(nodo->derecha, valor);
        }
        return nodo;
    }

    void enOrdenRecursivo(Nodo<T>* nodo) {
        if (nodo != nullptr) {
            enOrdenRecursivo(nodo->izquierda);
            cout << nodo->data << " ";
            enOrdenRecursivo(nodo->derecha);
        }
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Arbol<int> arbolInt;
    arbolInt.insertar(10);
    arbolInt.insertar(5);
    arbolInt.insertar(15);

    cout << "Recorrido en orden (int): ";
    arbolInt.enOrden();
    cout << endl;

    Arbol<double> arbolDouble;
    arbolDouble.insertar(10.5);
    arbolDouble.insertar(5.2);
    arbolDouble.insertar(15.8);

    cout << "Recorrido en orden (double): ";
    arbolDouble.enOrden();
    cout << endl;

    Arbol<char> arbolChar;
    arbolChar.insertar('M');
    arbolChar.insertar('B');
    arbolChar.insertar('Z');

    cout << "Recorrido en orden (char): ";
    arbolChar.enOrden();
    cout << endl;

    return app.exec();
}
