#include <QCoreApplication>
#include <iostream>
#include <string>
#include "Nodo.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Lista de edades
    ListaEnlazada<int> listaEdades;
    listaEdades.agregar(25);
    listaEdades.agregar(30);
    listaEdades.agregar(22);
    std::cout << "Edades: ";
    listaEdades.imprimir();

    // Lista de palabras
    ListaEnlazada<std::string> listaPalabras;
    listaPalabras.agregar("Hola");
    listaPalabras.agregar("Mundo");
    listaPalabras.agregar("Qt");
    std::cout << "Palabras: ";
    listaPalabras.imprimir();

    // Salir de la aplicación
    return a.exec();
}
