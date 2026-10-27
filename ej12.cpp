#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void burbujaRecursiva(std::vector<int>& arreglo, int cantidad, int& ciclos) {
    // Si el arreglo está vacio, se termina el programa.
    if (cantidad <= 1) {
        return;
    }

    ciclos++;

    // Variable booleana que ayudará a ejecutar varias veces si hubo intercambio o no.
    bool huboIntercambio = false;
    // Ciclo for para hacer los intercambios.
    for (int i = 0; i < cantidad - 1; i++) {
        if (arreglo[i] > arreglo[i + 1]) {
            int reemplazo = arreglo[i];
            arreglo[i] = arreglo[i + 1];
            arreglo[i + 1] = reemplazo;
            huboIntercambio = true;
        }
    }
    // Si en el ciclo se presentó algun intercambio, se vuelve a repetir hasta que el
    // arreglo esté ordenado.
    if (huboIntercambio) {
        burbujaRecursiva(arreglo, cantidad - 1, ciclos);
    }
}

void shakerSort(std::vector<int>& arreglo, int& ciclos) {
    int inicio = 0;
    int fin = static_cast<int>(arreglo.size()) - 1;
    bool huboIntercambio = true;

    while (huboIntercambio && inicio < fin) {
        huboIntercambio = false;

        for (int i = inicio; i < fin; i++) {
            if (arreglo[i] > arreglo[i + 1]) {
                std::swap(arreglo[i], arreglo[i + 1]);
                huboIntercambio = true;
            }
        }
        fin--;

        for (int i = fin; i > inicio; i--) {
            if (arreglo[i - 1] > arreglo[i]) {
                std::swap(arreglo[i - 1], arreglo[i]);
                huboIntercambio = true;
            }
        }

        if (huboIntercambio) {
            ciclos += 2;
        }
        inicio++;
    }
}

void mostrarMenu() {
    std::cout << "\n===== METODOS DIRECTOS O CUADRATICOS =====\n";
    std::cout << "1. Intercambio directo (Burbuja)\n";
    std::cout << "2. Sacudida (Shaker Sort)\n";
    std::cout << "3. Seleccion directa\n";
    std::cout << "4. Insercion directa\n";
    std::cout << "5. Insercion binaria\n";
    std::cout << "6. Reordenar arreglo\n";
    std::cout << "7. Salir\n";
    std::cout << "Selecciona una opcion: ";
}

int main() {
    int opcion;
    int tamanio;

    do {
        std::cout << "Ingresa el tamano del arreglo: ";
        if (!(std::cin >> tamanio)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida. Ingresa un numero entero positivo.\n";
            tamanio = 0;
        } else if (tamanio <= 0) {
            std::cout << "El tamano debe ser mayor que cero.\n";
        }
    } while (tamanio <= 0);

    std::vector<int> a(tamanio);
    std::cout << "Ingresa los " << tamanio << " elementos del arreglo:\n";
    for (int i = 0; i < tamanio; i++) {
        std::cout << "a[" << i << "]: ";
        while (!(std::cin >> a[i])) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida. Ingresa un numero para a[" << i << "]: ";
        }
    }

    std::random_device semilla;
    std::mt19937 generador(semilla());

    do {
        mostrarMenu();

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Entrada invalida. Ingresa un numero.\n";
            continue;
        }

        switch (opcion) {
            case 1: {
                std::cout << "Seleccionaste Intercambio directo (Burbuja).\n";
                int ciclos = 0;
                burbujaRecursiva(a, tamanio, ciclos);

                for (int j = 0; j < tamanio; j++) {
                    std::cout << " " << a[j] << '\t';
                }
                std::cout << '\n';
                for (int h = 0; h < tamanio; h++) {
                    std::cout << "a[" << h << "]" << '\t';
                }
                std::cout << '\n';
                std::cout << "Ciclos de intercambio: " << ciclos << '\n';
                break;
            }
            case 2: {
                std::cout << "Seleccionaste Sacudida (Shaker Sort).\n";
                int ciclos = 0;
                shakerSort(a, ciclos);

                for (int j = 0; j < tamanio; j++) {
                    std::cout << " " << a[j] << '\t';
                }
                std::cout << '\n';
                for (int h = 0; h < tamanio; h++) {
                    std::cout << "a[" << h << "]" << '\t';
                }
                std::cout << '\n';
                std::cout << "Ciclos de sacudida: " << ciclos << '\n';
                break;
            }
            case 3:
                std::cout << "Seleccionaste Seleccion directa.\n";
                break;
            case 4:
                std::cout << "Seleccionaste Insercion directa.\n";
                break;
            case 5:
                std::cout << "Seleccionaste Insercion binaria.\n";
                break;
            case 6:
                std::shuffle(a.begin(), a.end(), generador);
                std::cout << "El arreglo fue reordenado.\n";
                std::cout << "Nuevo orden: ";
                for (int elemento : a) {
                    std::cout << elemento << ' ';
                }
                std::cout << '\n';
                break;
            case 7:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida. Selecciona una opcion del 1 al 7.\n";
        }
    } while (opcion != 7);

    return 0;
}