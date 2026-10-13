#include <iostream>
#include <iomanip>

using namespace std;

double sumarCalificaciones(int cantidad) {
    if (cantidad == 0) {
        return 0;
    }

    double calificacion;
    cout << "Ingrese la calificacion " << cantidad << ": ";
    cin >> calificacion;

    return calificacion + sumarCalificaciones(cantidad - 1);
}

int main() {
    int cantidad;

    cout << "=== PROMEDIO UNIVERSITARIO ===\n";
    cout << "Ingrese la cantidad de calificaciones: ";
    cin >> cantidad;

    if (cantidad <= 0) {
        cout << "La cantidad debe ser mayor que 0.\n";
        return 1;
    }

    double suma = sumarCalificaciones(cantidad);
    double promedio = suma / cantidad;

    cout << fixed << setprecision(2);
    cout << "\nPromedio final: " << promedio << "\n";

    if (promedio >= 6 && promedio <= 10) {
        cout << "Resultado: el estudiante aprobo.\n";
    } else {
        cout << "Resultado: el estudiante no aprobo.\n";
    }

    return 0;
}
