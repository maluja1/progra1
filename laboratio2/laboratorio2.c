#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIN 1000


/*
funcion leermatriz
lo que hace esta funcion es leer el archivo de entrada .txt para comenzar a manípularlo dentro del programa
entrada:
salida: un puntero doble , con todo lo del archivo almacenado
*/
int m = 0 , n = 0;
int **leermatriz(){
  FILE* fp=fopen("calles.txt","r");
   char linea[MAX_LIN], *p;
   int val;
   int **matriz= (int **) calloc(1000, sizeof(int *)) ;
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL) {
     m=m+1;
     printf("La linea es : %s\n", linea);
     matriz[m] = (int *) calloc(MAX_LIN, sizeof(int));
     p = strtok(strtok(linea,"calle")," ");
     //printf("el matriz[%i] = %s\n",m,p);
     n=-1;
     while(p != NULL) {
       n=n+1;
       sscanf(p,"%d",&val);
       printf("%d\n",val);
       matriz[m][n] = val;
       p=strtok(NULL," ");
     }

   }
   return matriz;
}
int largo = 0 , ancho = 0;
/*

int Calle(int NumeroCalle , int posicion , int ){
	int y = 2;
	for (int i = x ; i <= largo ; ++i)
	{
		printf("ciudad[0][%i](%i) = matriz[0][%i + 1](%i)\n",i,ciudad[0][i],i,matriz[0][x]);

		ciudad[0][i] = matriz[0][y];
		y++;
	}
}
*/
int iterativo(int **matriz){
	int cantidadEdificios,Ncalle,posicion;
	for (int i = 0; i <= m; ++i)
	{
		if(matriz[i][0]>ancho){
			ancho = matriz[i][0];
		}
		if(matriz[i][1]+matriz[i][2] > largo){
			largo = matriz[i][1]+matriz[i][2];
		}
	}
	printf("el ancho es %i\n",ancho);
	printf("el largo es %i\n",largo);
	int ciudad[ancho][largo];
	int **city;
	city = (int **)malloc(sizeof(int *)*ancho);
	for (int i = 0; i <= largo; ++i)
	{
		city[i] = (int *)malloc(sizeof(int)*largo);
	}
	for (int l = 0; l <= ancho; ++l)
	{
		for (int k = 0; k < largo; ++k)
		{
			ciudad[l][k] = 0;
			//printf("%i ",ciudad[l][k]);
		}
		//printf("\n");
		for (int k = 0; k <= largo; ++k)
		{
			city[l][k] = 0;
			//printf("%i ",city[l][k]);
		}
		//printf("\n");
	}
	printf("el numero es :%i\n",matriz[0][2]);
	// rellenar matriz ciudad con los datos del archivo txt
	int ifilas = 0; 
	int iedificios,cedif,calleActual;
	for (int i = 0; i <= m; ++i)
	{
		for (int j = 0; j < matriz[i][2] + 3; ++j)
		{
			printf("%i ",matriz[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	for (int l = 0; l <= ancho; ++l)
	{
		for (int k = 0; k < largo-1; ++k)
		{
			//Calle(ciudad[l][k],matriz[0][2]);
			printf("%i ",ciudad[l][k]);
		}
		printf("\n");
	}
	printf("\n");
	while(ifilas < 32){
		iedificios = matriz[ifilas][1]-1;
		cedif = matriz[ifilas][2];
		calleActual = matriz[ifilas][0]-1;
		int i2 = 3;
		while(iedificios < 15){
			//printf("ciudad[%i][%i](%i) = matriz[%i][%i](%i) \n",calleActual,iedificios,ciudad[calleActual][iedificios]);
			if(matriz[ifilas][i2]>city[calleActual][iedificios]){
				city[calleActual][iedificios] = matriz[ifilas][i2];
			}else{
				city[calleActual][iedificios] = city[calleActual][iedificios];
			}
			i2++;
			iedificios++;
		}
		ifilas++;
	}
	for (int l = 0; l < ancho; ++l)
	{
		for (int k = 0; k < largo-1; ++k)
		{
			//Calle(ciudad[l][k],matriz[0][2]);
			printf("%i ",city[l][k]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i=0; i<10; i++) {
    	free(matriz[i]);
	}
	free(matriz);
}
int main()
{
	int **matriz = leermatriz(); 
	iterativo(matriz);
	return 0;
}