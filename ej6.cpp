#include <iostream>

using namespace std;

long long resolverHanoi(int n, int origen, int auxiliar, int destino,
                        long long movimientosPorTorre[]) {
    if (n == 1) {
        movimientosPorTorre[origen]++;
        return 1;
    }

    long long movimientos =
        resolverHanoi(n - 1, origen, destino, auxiliar, movimientosPorTorre);
    movimientosPorTorre[origen]++;
    movimientos++;
    movimientos +=
        resolverHanoi(n - 1, auxiliar, origen, destino, movimientosPorTorre);

    return movimientos;
}

int main() {
    int n;
    long long movimientosPorTorre[3] = {0, 0, 0};

    cout << "=== TORRES DE HANOI ===\n";
    cout << "Entrada: ingrese la cantidad de discos: ";
    cin >> n;

    if (n < 1) {
        cout << "La cantidad de discos debe ser mayor que 0.\n";
        return 1;
    }

    long long movimientos = resolverHanoi(n, 0, 1, 2, movimientosPorTorre);

    cout << "\nCantidad de movimientos: " << movimientos << "\n";
    cout << "Movimientos desde la torre A: " << movimientosPorTorre[0] << "\n";
    cout << "Movimientos desde la torre B: " << movimientosPorTorre[1] << "\n";
    cout << "Movimientos desde la torre C: " << movimientosPorTorre[2] << "\n";
    cout << "Resultado final: los " << n
         << " discos quedaron en la torre C.\n";

    return 0;
}
