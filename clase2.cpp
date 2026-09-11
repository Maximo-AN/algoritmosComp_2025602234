#include <stdio.h>
#include <math.h>
#define EUR 1.16;
#define USD 0.86;

int main(){
    float usd, usdEuro, eur, eurUsd;
    int opc = 0;
    printf("Digite la opc a ejecutar\n1. USD a EUR\n2. EUR a USD\n3. Salir.\n");
    scanf("%d",&opc);
    switch(opc){
        case 1:
            printf("Digite los dolares: ");
            scanf("%f",& usd);
            usdEuro = usd * EUR;
            printf("Tus dolares valen %.2f en euros",usdEuro);
        break;
        
        case 2:
            printf("Digite los euros: ");
            scanf("%f",& eur);
            eurUsd = eur * USD;
            printf("Tus dolares valen %.2f en dolares",eurUsd); 
        break;

        case 3:
            return 0;
        break;

    }
}