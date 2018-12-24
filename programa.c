#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LIN 1000



int numero;
int n,m;
int mf,nf;
void filas(int **PistasFilas,int numero,int **matriz){
	int contador = 0 , contadorAnterior = 0 , o = 1;
	for(int i = 0 ; i < numero ; i++){
		for (int j = 0; j < numero; ++j)
		{
			if(matriz[i][j] == '#'){
				contador++;
				if(j==numero-1){
					if(matriz[i][numero-1] == '#'){
						j++;
					}
					j++;
				}
			}
			//preguntamos si en la siguiente posicion hay un # , si lo hay el cotador se mantiene iguak
			if(matriz[i][j+1] == '#' && j<numero){
				contador = contador ;	
			}
			else if(contador != 0){
					//condicion para ir cambiando el NmaxF
					/*if(nf>NmaxF){
						NmaxF = nf;
					}
					else{
						NmaxF = NmaxF;
					}*/
					//pregunta si el contador es distinto a 0 , lo guarda en pistasFilas 
					PistasFilas[mf][nf] = contador;
					contadorAnterior = contador;
					contador = 0;	
					nf++;
			}
			else if(contador == 0 && j==numero-1 && contadorAnterior == 0){
					//si el contador es 0 , lo guarda en las PistasFilas
					PistasFilas[mf][nf] = 0;
					contador = 0;
					nf=0;
			}
		}
		nf=0;
		mf++;
	}
}
int **matriz;
int matrizz(){
	FILE *archivo;
	archivo = fopen("matriz.txt", "r");
	fscanf(archivo , "%i",&numero);
	matriz = (int **)malloc(sizeof(int * ) * numero);
	for(int i = 0; i < (numero); ++i)
	{
		matriz[i] = (int *)malloc(sizeof(int ));
	}
	printf("el numero de la matriz es :%i\n",numero);
	for(int k = 0; k < numero; k++){
		for(int l = 0 ;l < numero; l++){
	        fscanf(archivo, "%i", &matriz[k][l]);
	        printf("%i",matriz[k][l]);
		}
		printf("\n");
	}        	
	fclose(archivo);
}

int main(){
	matrizz();
	int **PistasFilas;
	PistasFilas = (int **)malloc(sizeof(int * ) * numero);
	for(int i = 0; i < (numero); ++i)
	{
		PistasFilas[i] = (int *)malloc(sizeof(int ));
	}
	/* 
	arreglo dinamico doble que almacenara las pistas por columnas
	*/
	int **PistasColumnas;
	PistasColumnas = (int **)malloc(sizeof(int * ) * numero);
	for(int i = 0; i < (numero); ++i)
	{
		PistasColumnas[i] = (int *)malloc(sizeof(int ));
	}
	filas(PistasFilas,numero,matriz);
	for(int k = 0; k < numero; k++){
		for(int l = 0 ;l < numero; l++){
	        printf("%i",pistasFilas[k][l]);
		}
		printf("\n");
	}        	

	return 0;
}