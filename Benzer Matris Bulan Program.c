#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void diziOlustur (int **dizi, int n){
	int j,i;
	for (j=0;j<n;j++){
	for (i=0;i<n;i++){
		dizi[j][i]= rand () % 2 ;
		printf ("%2d ",dizi[j][i]);
	}
	printf ("\n");}
	printf ("\n");
}

void benzer_matris_yazdir (int **dizi, int x, int y){
	int i,j;
	printf ("\nBenzeyen Matris : ");
	for (i=y;i<y+3;i++){
		printf ("\n");
		for (j=x;j<x+3;j++)
			printf ("%2d ",dizi[i][j] );
	}
}

void benzer_matris_bul (int **dizi1, int **dizi2){
	int benzerlik,max=0,i,j,n,k,x,y,t,p;
	for (i=0;i<8;i++){
		for (j=0;j<8;j++){
			t=0;p=0;benzerlik = 0;
			for (n=i;n<i+3;n++){
				for (k=j;k<j+3;k++){
					if (dizi1[n][k]==dizi2[t][p])
						benzerlik++;
					p++;
				}
				p = 0;
				t++;
			}
			if (benzerlik>max){
				max=benzerlik;
				y = n-3;
				x = k-3;
			}
		}
	}
	printf ("Benzerlik Miktari = %d\n\nBenzer Matrisin Sol Ust Kosesinin Kordinati: x = %d y = %d (x yatay, y dikey)\n",max,x+1,y+1);
	benzer_matris_yazdir (dizi1,x,y);
}

int main (){
	srand(time(NULL));
	int **dizi1,**dizi2,i;
	dizi1 = calloc (100, sizeof(int));
	dizi2 = calloc (27, sizeof(int));
	for (i=0;i<10;i++){
		dizi1[i]=calloc (10, sizeof(int));
		if (i<4)
			dizi2[i]=calloc (3, sizeof(int));
	}
	diziOlustur (dizi2,3);
	diziOlustur (dizi1,10);
	benzer_matris_bul(dizi1,dizi2);
	free (dizi1);
	free (dizi2);
	return 0;
}