#include <iostream>

int buscarCaracter(const char arreglo[10], char valor) {
    for (int i = 0; i < 10; ++i) {
        if (arreglo[i] == valor) {
            return i+1;
        }
    }

    return -1;
}

int main() {
    char arreglo[10];
    char valor;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Caracter " << (i+1) << ": ";
        std::cin >> arreglo[i];
    }

    std::cout << "Caracter a buscar: ";
    std::cin >> valor;
    std::cout << "Se encuentra en la posicion: " << buscarCaracter(arreglo, valor) << '\n';

    return 0;
}