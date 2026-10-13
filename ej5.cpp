#include <stdio.h>

int main(){
    int n, res = 1;
    printf("Ingrese el numero para obtener factorial: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("Error\nNO se permiten numeros negativos.");
    }
    else if (n == 0) {
        printf("El factorial de 0 es: 1");
    }
    else {
        for (int i = 1; i <= n; i++) {
            res = res * i;
        }
        printf("El factorial de %d es: %d", n, res);
    }
    return 0;
}