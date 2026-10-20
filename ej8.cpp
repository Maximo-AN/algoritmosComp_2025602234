#include <iostream>

int buscarEntero(const int arreglo[10], int valor) {
    for (int i = 0; i < 10; ++i) {
        if (arreglo[i] == valor) {
            return i+1;
        }
    }

    return -1;
}

int main() {
    int arreglo[10];
    int valor;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Valor " << (i+1) << ": ";
        std::cin >> arreglo[i];
    }

    std:: cout << "Valor a buscar: ";
    std::cin >> valor;
    std::cout << "Se encuentra en la posicion: " << buscarEntero(arreglo, valor) << '\n';

    return 0;
}