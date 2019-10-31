#include <stdio.h>
#include <stdlib.h>

#include "matroid.h"

typedef char* string;

int main(){

	int opcion_menu = 0;
	int funcion = 0;
	int pez1;
	void* pez2;
	void* pez3;
	void* pez4;
	void* pez5;
	do
	{
		printf("\n|-------------------------------------|");
		printf("\n|           ° CASO 10 °               |");
		printf("\n|-------------------------------------|");
		printf("\n| 1. Generar 3 matroids               |");
		printf("\n| 1. Generar 5 matroids               |");
		printf("\n| 3. Salir                            |");
		printf("\n|-------------------------------------|");
		scanf("%d",opcion_menu) ;
		switch(opcion_menu){
		case 1:
            printf("\n|-------------------------------------|");
						printf("\n|    ° EVALUANDO 3 MATROIDS           |");
            printf("\n|          FUNCIONES a REALIZAR °     |");
            printf("\n|-------------------------------------|");
            printf("\n| 1. Pares                            |");
            printf("\n| 2. Impares                          |");
            printf("\n| 3. Letras Mayusculas                |");
            printf("\n|-------------------------------------|");

			scanf("%d",pez1);
			scanf("%d",pez2);
			scanf("%d",pez3);

			//matroid(int) *MS1;
			//matroid(int) *MS2;
			//matroid(string) *MS3;

			break;
		case 2:
			printf("\n\n Generar 5 //matroids \n\n");
            printf("\n|-------------------------------------|");
            printf("\n|           ° FUNCIONES °             |");
            printf("\n|-------------------------------------|");
            printf("\n| 1. Pares                            |");
            printf("\n| 2. Impares                          |");
            printf("\n| 3. Letras Mayusculas                |");
            printf("\n|-------------------------------------|");
            printf("\n\n Escoja una Funcion: ");
            scanf("%d",funcion);

			scanf("%d",pez1);
			scanf("%d",pez2);
			scanf("%d",pez3);
			scanf("%d",pez4);
			scanf("%d",pez5);

			//matroid(int) *MS1;
			//matroid(int) *MS2;
			//matroid(int) *MS3;
			//matroid(int) *MS4;
			//matroid(int) *MS5;

			break;
		case 3:
			printf("\n\n Programa finalizado...") ;
			break;
		default:
			printf("\n\n Opcion No Valida \n\n");
		}
	} while (opcion_menu != 3);

	return 0;
}

