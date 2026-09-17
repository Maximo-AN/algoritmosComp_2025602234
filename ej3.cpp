#include <stdio.h>

int main() {
	int anio;
	printf("Digita el anio: ");
	scanf("%d", &anio);

	if (anio <= 0) {
		printf("Anio invalido. Debe ser mayor que cero.\n");
		return 1;
	}
	
	int resto19 = anio % 19;
	int resto4 = anio % 4;
	int resto7 = anio % 7;
	int resto30 = (19 * resto19 + 24) % 30;
	int restoPascua = (2 * resto4 + 4 * resto7 + 6 * resto30 + 5) % 7;

	int dia = 22 + resto30 + restoPascua;
	if (dia <= 31) {
		printf("%d de marzo\n", dia);
	} else {
		printf("%d de abril\n", dia - 31);
	}

	return 0;
}
