#include <iostream>

// El arreglo debe estar ordenado de menor a mayor.
int buscarBinario(const int arreglo[], int inicio, int fin, int valor) {
    if (inicio > fin) {
        return -1;
    }

    int medio = inicio + (fin - inicio) / 2;

    if (arreglo[medio] == valor) {
        return medio + 1;
    }

    if (valor < arreglo[medio]) {
        return buscarBinario(arreglo, inicio, medio - 1, valor);
    }

    return buscarBinario(arreglo, medio + 1, fin, valor);
}

int main() {
    const int TAMANO = 12;
    int arreglo[TAMANO];
    int valor;

    std::cout << "Ingrese 12 numeros ordenados de menor a mayor:\n";
    int i = 0;
    do {
        std::cout << "Numero " << (i + 1) << ": ";
        std::cin >> arreglo[i];
        ++i;
    } while (i < TAMANO);

    std::cout << "Numero a buscar: ";
    std::cin >> valor;

    int posicion = buscarBinario(arreglo, 0, TAMANO - 1, valor);
    std::cout << "Se encuentra en la posicion: " << posicion << '\n';

    return 0;
}