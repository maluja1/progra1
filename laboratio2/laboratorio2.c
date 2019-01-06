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
int **matriz;
int **leermatriz(){
  FILE* fp=fopen("calles.txt","r");
   char linea[MAX_LIN], *p;
   int val;
   int **matriz= (int **) calloc(1000, sizeof(int *)) ;
   m=-1;
   while (fgets(linea, MAX_LIN, fp)!=NULL) {
     m=m+1;
     //printf("La linea es : %s\n", linea);
     matriz[m] = (int *) calloc(MAX_LIN, sizeof(int));
     p = strtok(strtok(linea,"calle")," ");
     //printf("el matriz[%i] = %s\n",m,p);
     n=-1;
     while(p != NULL) {
       n=n+1;
       sscanf(p,"%d",&val);
       //printf("%d\n",val);
       matriz[m][n] = val;
       p=strtok(NULL," ");
     }

   }
   return matriz;
}
int largo = 0 , ancho = 0;
int **Calle(int **matriz,int **city,int iedificios,int calleActual,int ifilas){
	int i2 = 3;
	/*
	printf("iedificios = %i \n",iedificios);
	printf("calleActual = %i \n",calleActual);
	printf("ifilas = %i \n",ifilas);
	*/
		while(iedificios < 15){
			//printf("ciudad[%i][%i](%i) = matriz[%i][%i](%i) \n",calleActual,iedificios,city[calleActual][iedificios],ifilas,i2,matriz[ifilas][i2]);
			if(matriz[ifilas][i2]>city[calleActual][iedificios]){
				city[calleActual][iedificios] = matriz[ifilas][i2];
			}else{
				city[calleActual][iedificios] = city[calleActual][iedificios];
			}
			i2++;
			iedificios++;
		}
}
int recursion();
int recursion(int **matriz,int **city, int filas,int NumeroEd){
	int iedificios,cedif,calleActual;
	printf("NumeroEd=%i\n",NumeroEd);
	if(NumeroEd == 0){
		filas++;
	}else{
		iedificios = matriz[filas][0]-1;
		cedif = matriz[filas][1] + NumeroEd;
		printf("iedificios=%i\n",iedificios);
		if(matriz[filas][NumeroEd+3]>city[iedificios][cedif]){
			city[iedificios][cedif] = matriz[filas][NumeroEd+3];
		}else{
			city[iedificios][cedif] = city[iedificios][cedif];
		}
		recursion(matriz,city,filas,NumeroEd-1);
	}
}
int recursivo(int **matriz){
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
	int ifilas = 0; 
	int iedificios,cedif,calleActual;
	int fotos = 0;
	for (int i = 0; i <= m; ++i)
	{
		fotos++;
		for (int j = 0; j < matriz[i][2] + 3; ++j)
		{
			printf("%i ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("fotos = %i\n",fotos );
	int fil = 0;
	recursion(matriz,city,fil,matriz[fil][2]);
	for (int l = 0; l < ancho; ++l)
	{
		for (int k = 0; k < largo-1; ++k)
		{
			printf("%i ",city[l][k]);
		}
		printf("\n");
	}


	/*****************



	terminar el iterativo.....


	****************/









}
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
	int **city;
	city = (int **)malloc(sizeof(int *)*ancho);
	for (int i = 0; i <= ancho; ++i)
		city[i] = (int *)malloc(sizeof(int)*largo);
	for (int l = 0; l <= ancho; ++l){
		for (int k = 0; k <= largo; ++k)
			city[l][k] = 0;
	}
	// rellenar matriz ciudad con los datos del archivo txt
	int ifilas = 0; 
	int iedificios,cedif,calleActual;
	int fotos = 0;
	for (int i = 0; i <= m; ++i)
	{
		fotos++;
		for (int j = 0; j < matriz[i][2] + 3; ++j)
		{
			printf("%i ",matriz[i][j]);
		}
		printf("\n");
	}
	printf("fotos = %i\n",fotos );
	printf("\n");
	
	while(ifilas < fotos){
		iedificios = matriz[ifilas][1]-1;
		cedif = matriz[ifilas][2];
		calleActual = matriz[ifilas][0]-1;
		Calle(matriz,city,iedificios,calleActual,ifilas);
		ifilas++;
	}
	for (int l = 0; l < ancho; ++l)
	{
		for (int k = 0; k < largo-1; ++k)
		{
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
int menu(){
	int opcion;
	printf("opciones\n");
	printf("opcion 1 iterativo\n");
	printf("opcion 2 recursivo\n");
	printf("opcion 3 Divicion y conquista\n");
	scanf("%i",&opcion);
	return opcion;
}
int main()
{
	int **matriz = leermatriz();
	int opcion = 2;//menu();
	switch(opcion){
		case 1:
			iterativo(matriz);
		break;
		case 2:
			recursivo(matriz);
		break;
		case 3:
		break;
		default:
			printf("opcion invalida\n");
		break;
	}

	 
	
	return 0;
}