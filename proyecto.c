#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LIN 1000



int numero;
int n,m;
int mf,nf;
void filas(int **PistasFilas,int numero,int **matriz){
	int contador = 0 , contadorAnterior = 0 , o = 1;
	int i,j;
	for(i = 0 ; i < numero ; i++){
		for (j = 0; j < numero; ++j)
		{
			if(matriz[i][j] > 0){
				contador++;
				if(j==numero-1){
					if(matriz[i][numero-1] > 0){
						j++;
					}
					j++;
				}
			}
			if(matriz[i][j+1] > 0 && j<numero){
				contador = contador ;	
			}
			else if(contador != 0){
					PistasFilas[mf][0] = contador;
					contador = 0;
			}
		}
		mf++;
	}
	nf = 1;
	mf = 0;
	int x,y;
	for( x = 0 ; x < numero ; x++){
		for (y = 0; y < numero; ++y)
		{
			printf("matriz[%i][%i] == %i\n",x,y,matriz[x][y]);
			/*if(matriz[x][y] == 0){
				y++;
			}*/
			if(matriz[x][y] > 0){
				PistasFilas[mf][nf] = matriz[x][y];
				nf++;
			}
		}
		nf=1;
		mf++;
	}
}
int nc,mc;
void columnas(int **PistasColumnas,int numero,int **matriz){
	int contador = 0 , contadorAnterior = 0 , o = 1;
	int i,j;
	for(i = 0 ; i < numero ; i++){
		for (j = 0; j < numero; ++j)
		{
			if(matriz[j][i] == 0){
				contador = 0;
				j++;
			}
			if(matriz[j][i] > 0){
				contador++;
			}
			if(matriz[j+1][i] > 0 && j<numero){
				contador = contador ;	
			}
			else if(contador != 0){
				PistasColumnas[mc][0] = contador;
				contador = 0;
			}else if(contador == 0){
				PistasColumnas[mc][0] = 0;
			}
		}
		mc++;
	}/*
	nc = 1;
	mc = 0;
	int x,y;
	for( x = 0 ; x < numero ; x++){
		for (y = 0; y < numero; ++y)
		{
			printf("matriz[%i][%i] == %i\n",y,x,matriz[y][x]);
			if(matriz[y][x] > 0){
				PistasColumnas[mc][nc] = matriz[y][x];
				nc++;
			}
		}
		nc=1;
		mc++;
	}
	*/
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
	printf("hola mundo ql");
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
		for (int i = 0; i <= PistasFilas[k][0]; ++i)
		{
			printf("%i ",PistasFilas[k][i]);
		}
		printf("\n");
	}
	//columnas(PistasColumnas,numero,matriz);
	/*for(int k = 0; k < numero; k++){
		for (int i = 0; i <= PistasColumnas[k][0]; ++i)
		{
			printf("%i ",PistasColumnas[k][i]);
		}
		printf("\n");
	} */    	     	
	return 0;
}