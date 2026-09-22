#include <stdio.h>
int main(){
    int lugares[10] = {0};
    int n, lugar;

    printf("Cuantos lugares desea reservar? ");
    scanf("%d", &n);

    int reservados = 0;
    while(reservados < n){
        printf("Indique el lugar %d (del 1 al 10): ", reservados + 1);
        scanf("%d", &lugar);

        if(lugar >= 1 && lugar <= 10 && lugares[lugar - 1] == 0){
            lugares[lugar - 1] = 1;
            printf("Lugar %d reservado.\n", lugar);
            reservados++;
        }else if(lugar > 10){
            printf("Lugar fuera de rango. Se ignora.\n");
        }else{
            printf("Lugar no disponible o invalido. Se ignora.\n");
        }
    }

    printf("\nLugares aun disponibles: ");
    for(int i = 0; i < 10; i++){
        if(lugares[i] == 0){
            printf("%d ", i + 1);
        }
    }
    printf("\n");

    return 0;
}