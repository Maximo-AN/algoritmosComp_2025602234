#include <algorithm>
#include <iostream>

const int SALAS = 7;
const int PELICULAS = 15;

struct MayorAsistencia {
    int asistentes;
    int sala;
    int pelicula;
};

MayorAsistencia buscarMayor(const int asistencias[][PELICULAS],
                            int sala, int pelicula) {
    if (sala == SALAS) {
        return { -1, -1, -1 };
    }

    MayorAsistencia siguiente;
    if (pelicula == PELICULAS - 1) {
        siguiente = buscarMayor(asistencias, sala + 1, 0);
    } else {
        siguiente = buscarMayor(asistencias, sala, pelicula + 1);
    }

    if (asistencias[sala][pelicula] >= siguiente.asistentes) {
        return { asistencias[sala][pelicula], sala, pelicula };
    }

    return siguiente;
}

void sumarPeliculas(const int asistencias[][PELICULAS],
                    int totales[], int sala, int pelicula) {
    if (sala == SALAS) {
        return;
    }

    totales[pelicula] += asistencias[sala][pelicula];

    if (pelicula == PELICULAS - 1) {
        sumarPeliculas(asistencias, totales, sala + 1, 0);
    } else {
        sumarPeliculas(asistencias, totales, sala, pelicula + 1);
    }
}

int buscarBinaria(const int arreglo[], int inicio, int fin, int valor) {
    if (inicio > fin) {
        return -1;
    }

    int medio = inicio + (fin - inicio) / 2;

    if (arreglo[medio] == valor) {
        return medio;
    }

    if (valor < arreglo[medio]) {
        return buscarBinaria(arreglo, inicio, medio - 1, valor);
    }

    return buscarBinaria(arreglo, medio + 1, fin, valor);
}

int main() {
    int asistencias[SALAS][PELICULAS];
    int totales[PELICULAS] = {};

    std::cout << "Ingrese los asistentes de cada sala y pelicula:\n";
    for (int sala = 0; sala < SALAS; ++sala) {
        for (int pelicula = 0; pelicula < PELICULAS; ++pelicula) {
            std::cout << "Sala " << sala + 1
                      << ", pelicula " << pelicula + 1 << ": ";
            std::cin >> asistencias[sala][pelicula];
        }
    }

    MayorAsistencia mayor = buscarMayor(asistencias, 0, 0);
    sumarPeliculas(asistencias, totales, 0, 0);

    int totalesOrdenados[PELICULAS];
    for (int pelicula = 0; pelicula < PELICULAS; ++pelicula) {
        totalesOrdenados[pelicula] = totales[pelicula];
    }
    std::sort(totalesOrdenados, totalesOrdenados + PELICULAS);

    int mayorTotal = totalesOrdenados[PELICULAS - 1];
    int posicionMayor = buscarBinaria(
        totalesOrdenados, 0, PELICULAS - 1, mayorTotal);

    int peliculaMasVista = -1;
    for (int pelicula = 0; pelicula < PELICULAS; ++pelicula) {
        if (totales[pelicula] == totalesOrdenados[posicionMayor]) {
            peliculaMasVista = pelicula;
            break;
        }
    }

    std::cout << "\nCombinacion sala-pelicula mas vista:\n";
    std::cout << "Sala: " << mayor.sala + 1
              << ", pelicula: " << mayor.pelicula + 1
              << ", asistentes: " << mayor.asistentes << '\n';
    std::cout << "Pelicula mas vista: Pelicula " << peliculaMasVista + 1;

    return 0;
}