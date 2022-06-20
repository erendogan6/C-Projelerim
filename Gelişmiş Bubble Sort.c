// Bubble sort, dinamik bellek, pointer, iki katlý dizi.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 10
int bubble (int **dizi){
	int n,i,j,t;
	for (n=0;n<size;n++){
	for (i=0;i<size-1;i++){
		for (j=i;j<size;j++){
			if (*(*(dizi+i)+n)>*(*(dizi+j)+n)){
				t = *(*(dizi+i)+n);
				*(*(dizi+i)+n) = *(*(dizi+j)+n);
				*(*(dizi+j)+n) = t;	}}}}}
int main (){
	srand (time(NULL));
	int **dizi = (int**) calloc (size , sizeof(int*));
	int j,i;
	for (i=0;i<size;i++)
		*(dizi+i) = (int*) calloc (size,sizeof(int));
	printf ("\nOrjinal Diziler: \n");	
	for (i=0;i<size;i++){
		printf ("\n");
		for (j=0;j<size;j++){
			*(*(dizi+j)+i) = rand () % 99 + 1;
			printf ("%d ",*(*(dizi+j)+i));
		}
	}
	bubble (dizi);
	printf ("\n\nSiralanmis Diziler: \n");
	for (i=0;i<size;i++){
		printf ("\n");
		for (j=0;j<size;j++){
			printf ("%d ",*(*(dizi+j)+i));
		}
	}
	free (dizi);
	return 0; }

