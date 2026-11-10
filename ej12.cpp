#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void mostrarArreglo(const std::vector<int>& arreglo);

void burbujaRecursiva(std::vector<int>& arreglo, int cantidad, int& ciclos) {
    if (cantidad <= 1) {
        return;
    }

    ciclos++;
    bool huboIntercambio = false;
    std::cout << "\nPASADA " << ciclos << '\n';

    for (int i = cantidad - 2; i >= 0; i--) {
        std::cout << "a[" << i << "]>a[" << i + 1 << "] ("
                  << arreglo[i] << ">" << arreglo[i + 1] << ") ";

        if (arreglo[i] > arreglo[i + 1]) {
            std::swap(arreglo[i], arreglo[i + 1]);
            std::cout << "si hay intercambio\n";
            huboIntercambio = true;
        } else {
            std::cout << "no hay intercambio\n";
        }
    }

    mostrarArreglo(arreglo);

    if (huboIntercambio) {
        burbujaRecursiva(arreglo, cantidad - 1, ciclos);
    }
}

void shakerSort(std::vector<int>& arreglo, int& ciclos) {
    int inicio = 0;
    int fin = static_cast<int>(arreglo.size()) - 1;
    int pasada = 1;

    while (inicio < fin) {
        bool huboIntercambio = false;
        int ultimaPosicion = inicio;

        std::cout << "\nPRIMERA ETAPA DE LA PASADA " << pasada
                  << " (de derecha a izquierda)\n";
        for (int i = fin - 1; i >= inicio; i--) {
            std::cout << "A[" << i << "]>A[" << i + 1 << "] ("
                      << arreglo[i] << ">" << arreglo[i + 1] << ") ";

            if (arreglo[i] > arreglo[i + 1]) {
                std::swap(arreglo[i], arreglo[i + 1]);
                std::cout << "si hay intercambio\n";
                huboIntercambio = true;
                ultimaPosicion = i;
            } else {
                std::cout << "no hay intercambio\n";
            }
        }
        std::cout << "Ultima posicion de intercambio de derecha a izquierda: "
                  << ultimaPosicion << '\n';

        inicio = ultimaPosicion;
        std::cout << "\nSEGUNDA ETAPA (de izquierda a derecha)\n";
        ultimaPosicion = fin;
        for (int i = inicio; i < fin; i++) {
            std::cout << "A[" << i << "]>A[" << i + 1 << "] ("
                      << arreglo[i] << ">" << arreglo[i + 1] << ") ";

            if (arreglo[i] > arreglo[i + 1]) {
                std::swap(arreglo[i], arreglo[i + 1]);
                std::cout << "si hay intercambio\n";
                huboIntercambio = true;
                ultimaPosicion = i + 1;
            } else {
                std::cout << "no hay intercambio\n";
            }
        }
        std::cout << "Ultima posicion de intercambio de izquierda a derecha: "
                  << ultimaPosicion << '\n';
        mostrarArreglo(arreglo);

        ciclos++;
        if (!huboIntercambio) {
            break;
        }
        fin = ultimaPosicion - 1;
        pasada++;
    }
}

void seleccionDirecta(std::vector<int>& arreglo, int& ciclos) {
    int tamanio = static_cast<int>(arreglo.size());

    for (int i = 0; i < tamanio - 1; i++) {
        std::cout << "\nPASADA " << i + 1 << '\n';
        int posicionMenor = i;
        std::cout << "menor = A[" << i << "] (" << arreglo[i] << ")\n";

        for (int j = i + 1; j < tamanio; j++) {
            std::cout << "A[" << j << "]<menor (" << arreglo[j] << "<"
                      << arreglo[posicionMenor] << ") ";
            if (arreglo[j] < arreglo[posicionMenor]) {
                posicionMenor = j;
                std::cout << "si, nuevo menor = A[" << j << "] ("
                          << arreglo[j] << ")\n";
            } else {
                std::cout << "no se cumple\n";
            }
        }

        if (posicionMenor != i) {
            std::cout << "Se intercambia A[" << posicionMenor << "] ("
                      << arreglo[posicionMenor] << ") con A[" << i << "] ("
                      << arreglo[i] << ")\n";
            std::swap(arreglo[i], arreglo[posicionMenor]);
        } else {
            std::cout << "No hay intercambio en esta pasada\n";
        }

        mostrarArreglo(arreglo);
        ciclos++;
    }
}

void mostrarArreglo(const std::vector<int>& arreglo) {
    std::cout << "A: ";
    for (int elemento : arreglo) {
        std::cout << elemento << ' ';
    }
    std::cout << '\n';
}

void insercionDirecta(std::vector<int>& arreglo, int& ciclos) {
    int tamanio = static_cast<int>(arreglo.size());

    for (int i = 1; i < tamanio; i++) {
        std::cout << "\nPASADA " << i << '\n';
        int j = i;

        while (j > 0) {
            std::cout << "A[" << j << "] < A[" << j - 1 << "] ("
                      << arreglo[j] << " < " << arreglo[j - 1] << ") ";

            if (arreglo[j] < arreglo[j - 1]) {
                int reemplazo = arreglo[j];
                arreglo[j] = arreglo[j - 1];
                arreglo[j - 1] = reemplazo;
                std::cout << "si hay intercambio\n";
                j--;
            } else {
                std::cout << "no hay intercambio\n";
                break;
            }
        }

        mostrarArreglo(arreglo);
        ciclos++;
    }
}

void shellSort(std::vector<int>& arreglo, int& ciclos) {
    int tamanio = static_cast<int>(arreglo.size());
    int numeroPasada = 1;

    for (int brecha = tamanio / 2; brecha > 0; brecha /= 2) {
        std::cout << "\nPASADA " << numeroPasada++ << " (brecha " << brecha << ")\n";
        std::cout << "Se dividen los elementos en " << brecha << " grupo";
        if (brecha != 1) {
            std::cout << "s";
        }
        std::cout << ".\n";

        for (int i = brecha; i < tamanio; i++) {
            int j = i;

            while (j >= brecha && arreglo[j] < arreglo[j - brecha]) {
                std::cout << "A[" << j << "] < A[" << j - brecha << "] ("
                          << arreglo[j] << " < " << arreglo[j - brecha]
                          << ") si hay intercambio\n";

                int reemplazo = arreglo[j];
                arreglo[j] = arreglo[j - brecha];
                arreglo[j - brecha] = reemplazo;
                j -= brecha;
                ciclos++;
            }
        }

        mostrarArreglo(arreglo);
    }
}

void insercionBinaria(std::vector<int>& arreglo, int& ciclos) {
    int tamanio = static_cast<int>(arreglo.size());

    for (int i = 1; i < tamanio; i++) {
        std::cout << "\nPASADA " << i << '\n';
        int valor = arreglo[i];
        int izquierda = 0;
        int derecha = i - 1;

        while (izquierda <= derecha) {
            int medio = izquierda + (derecha - izquierda) / 2;
            std::cout << "A[" << i << "] < A[" << medio << "] ("
                      << valor << " < " << arreglo[medio] << ") ";

            if (valor < arreglo[medio]) {
                std::cout << "si, se busca a la izquierda\n";
                derecha = medio - 1;
            } else {
                std::cout << "no, se busca a la derecha\n";
                izquierda = medio + 1;
            }
        }

        for (int j = i; j > izquierda; j--) {
            std::cout << "Intercambio: A[" << j << "] = A[" << j - 1
                      << "] (" << arreglo[j] << " <- " << arreglo[j - 1]
                      << ")\n";
            arreglo[j] = arreglo[j - 1];
            ciclos++;
        }

        arreglo[izquierda] = valor;
        mostrarArreglo(arreglo);
    }
}

int particionarQuickSort(std::vector<int>& arreglo, int izquierda, int derecha,
                         int& pasada, int& intercambios,
                         std::mt19937& generador) {
    int inicio = izquierda;
    int fin = derecha;
    std::uniform_int_distribution<int> distribucion(izquierda, derecha);
    int posicionAleatoria = distribucion(generador);
    std::swap(arreglo[izquierda], arreglo[posicionAleatoria]);
    int pivote = arreglo[izquierda];

    std::cout << "\nPASADA " << pasada++ << " (conjunto " << izquierda << "-"
              << derecha << ")\n";
    std::cout << "Numero aleatorio seleccionado: A[" << posicionAleatoria
              << "] = " << pivote << '\n';
    std::cout << "Pivote X = A[" << izquierda << "] = " << pivote << '\n';

    while (izquierda < derecha) {
        while (izquierda < derecha) {
            std::cout << "Recorrido de derecha a izquierda: A[" << derecha
                      << "] >= X (" << arreglo[derecha] << " >= " << pivote
                      << ") ";

            if (arreglo[derecha] >= pivote) {
                std::cout << "no hay intercambio\n";
                derecha--;
            } else {
                std::cout << "si hay intercambio\n";
                arreglo[izquierda] = arreglo[derecha];
                arreglo[derecha] = pivote;
                intercambios++;
                mostrarArreglo(arreglo);
                break;
            }
        }

        while (izquierda < derecha) {
            std::cout << "Recorrido de izquierda a derecha: A[" << izquierda
                      << "] <= X (" << arreglo[izquierda] << " <= " << pivote
                      << ") ";

            if (arreglo[izquierda] <= pivote) {
                std::cout << "no hay intercambio\n";
                izquierda++;
            } else {
                std::cout << "si hay intercambio\n";
                arreglo[derecha] = arreglo[izquierda];
                arreglo[izquierda] = pivote;
                intercambios++;
                mostrarArreglo(arreglo);
                break;
            }
        }
    }

    arreglo[izquierda] = pivote;
    std::cout << "Pivote colocado en A[" << izquierda << "]\n";
    mostrarArreglo(arreglo);
    std::cout << "Conjunto procesado: A[" << inicio << ".." << fin << "]\n";
    return izquierda;
}

void quickSort(std::vector<int>& arreglo, int izquierda, int derecha,
               int& pasada, int& intercambios, std::mt19937& generador) {
    if (izquierda >= derecha) {
        return;
    }

    int posicionPivote = particionarQuickSort(
        arreglo, izquierda, derecha, pasada, intercambios, generador);
    quickSort(arreglo, izquierda, posicionPivote - 1, pasada, intercambios,
              generador);
    quickSort(arreglo, posicionPivote + 1, derecha, pasada, intercambios,
              generador);
}

void mostrarMenu() {
    std::cout << "\n===== METODOS DIRECTOS O CUADRATICOS =====\n";
    std::cout << "1. Intercambio directo (Burbuja)\n";
    std::cout << "2. Sacudida (Shaker Sort)\n";
    std::cout << "3. Seleccion directa\n";
    std::cout << "4. Insercion directa\n";
    std::cout << "5. Insercion Binaria\n";
    std::cout << "6. Metodo Shell\n";
    std::cout << "7. Metodo QuickSort\n";
    std::cout << "8. Reordenar arreglo\n";
    std::cout << "9. Salir\n";
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
                std::cout << "Ordenacion final:\n";
                mostrarArreglo(a);
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
                std::cout << "Ordenacion final:\n";
                mostrarArreglo(a);
                break;
            }
            case 3: {
                std::cout << "Seleccionaste Seleccion directa.\n";
                int ciclos = 0;
                seleccionDirecta(a, ciclos);

                for (int j = 0; j < tamanio; j++) {
                    std::cout << " " << a[j] << '\t';
                }
                std::cout << '\n';
                for (int h = 0; h < tamanio; h++) {
                    std::cout << "a[" << h << "]" << '\t';
                }
                std::cout << '\n';
                std::cout << "Ciclos de seleccion: " << ciclos << '\n';
                std::cout << "Ordenacion final:\n";
                mostrarArreglo(a);
                break;
            }
            case 4: {
                std::cout << "Seleccionaste Insercion directa.\n";
                int ciclos = 0;
                insercionDirecta(a, ciclos);
                std::cout << "\nArreglo ordenado:\n";
                mostrarArreglo(a);
                std::cout << "Ciclos de insercion: " << ciclos << '\n';
                break;
            }
            case 5: {
                std::cout << "Seleccionaste Insercion binaria.\n";
                int ciclos = 0;
                insercionBinaria(a, ciclos);
                std::cout << "\nOrdenacion final:\n";
                mostrarArreglo(a);
                std::cout << "Intercambios de insercion binaria: " << ciclos << '\n';
                break;
            }
            case 6: {
                std::cout << "Seleccionaste Metodo Shell.\n";
                int ciclos = 0;
                shellSort(a, ciclos);
                std::cout << "\nOrdenacion final:\n";
                mostrarArreglo(a);
                std::cout << "Intercambios de Shell: " << ciclos << '\n';
                break;
            }
            case 7: {
                std::cout << "Seleccionaste metodo QuickSort.\n";
                int pasadas = 1;
                int intercambios = 0;
                quickSort(a, 0, tamanio - 1, pasadas, intercambios, generador);
                std::cout << "\nOrdenacion final:\n";
                mostrarArreglo(a);
                std::cout << "Pasadas de QuickSort: " << pasadas - 1 << '\n';
                std::cout << "Intercambios de QuickSort: " << intercambios << '\n';
                break;
            }

            case 8:
                std::shuffle(a.begin(), a.end(), generador);
                std::cout << "El arreglo fue reordenado.\n";
                std::cout << "Nuevo orden: ";
                for (int elemento : a) {
                    std::cout << elemento << ' ';
                }
                std::cout << '\n';
                break;
            case 9:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida. Selecciona una opcion del 1 al 9.\n";
        }
    } while (opcion != 9);

    return 0;
}