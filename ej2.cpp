#include <stdio.h>

int main() {
    int saldo = 1000;
    int nip = 1234;
    int opcionPrincipal;

    do {
        printf("******* MENU ********\n");
        printf("1. Ingresar NIP.\n");
        printf("2. Olvidaste NIP\n");
        printf("3. Salir.\n");
        printf("Selecciona una opcion: ");
        scanf("%d", &opcionPrincipal);

        switch (opcionPrincipal) {
            case 1: {
                int nipIngresado;

                printf("Digite su NIP: ");
                scanf("%d", &nipIngresado);

                if (nipIngresado != nip) {
                    printf("NIP invalida.\n");
                    break;
                }

                int opcionCuenta;
                do {
                    printf("\nBienvenido Max\n");
                    printf("Digita la opcion que desees ejecutar:\n");
                    printf("1. Consulta de saldo.\n");
                    printf("2. Ingresar saldo.\n");
                    printf("3. Retiro de saldo.\n");
                    printf("4. Cancelar/Salir.\n");
                    printf("Selecciona una opcion: ");
                    scanf("%d", &opcionCuenta);

                    switch (opcionCuenta) {
                        case 1:
                            printf("Saldo actual: %d\n", saldo);
                            break;

                        case 2: {
                            int deposito;

                            printf("Digita el saldo a ingresar: ");
                            scanf("%d", &deposito);

                            if (deposito <= 0) {
                                printf("Digite una cantidad valida.\n");
                            } else {
                                saldo += deposito;
                                printf("Saldo agregado con exito.\n");
                            }
                            break;
                        }

                        case 3: {
                            int retiro;
                            int restante;
                            int b500 = 0;
                            int b200 = 0;
                            int b100 = 0;
                            int b50 = 0;

                            printf("Digita el saldo a retirar: ");
                            scanf("%d", &retiro);

                            if (retiro <= 0 || retiro > saldo) {
                                printf("No tiene fondos suficientes para retirar.\n");
                                break;
                            }

                            restante = retiro;

                            while (restante >= 500) {
                                b500++;
                                restante -= 500;
                            }

                            while (restante >= 200) {
                                b200++;
                                restante -= 200;
                            }

                            while (restante >= 100) {
                                b100++;
                                restante -= 100;
                            }

                            while (restante >= 50) {
                                b50++;
                                restante -= 50;
                            }

                            printf("Se entregaran:\n");
                            printf("%d billetes de 500\n", b500);
                            printf("%d billetes de 200\n", b200);
                            printf("%d billetes de 100\n", b100);
                            printf("%d billetes de 50\n", b50);

                            saldo -= retiro - restante;

                            if (restante > 0) {
                                printf("Saldo no entregado: %d\n", restante);
                                printf("No es posible retirar el saldo restante.\n");
                            } else {
                                printf("Sin saldo restante.\n");
                            }
                            break;
                        }

                        case 4:
                            printf("Saliendo de la cuenta.\n");
                            break;

                        default:
                            printf("Opcion invalida.\n");
                    }
                } while (opcionCuenta != 4);
                break;
            }

            case 2:
                printf("Digite el nuevo NIP: ");
                scanf("%d", &nip);
                printf("NIP actualizado.\n");
                break;

            case 3:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida.\n");
        }
    } while (opcionPrincipal != 3);

    return 0;
}