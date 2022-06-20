#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define size 3
struct sinav{
	long int numara[10];
	int cevaplar[10][20];
	int sonuc[10][3];
};

int main (){
	FILE *bys;
	bys = fopen ("bys.txt","w+");
	int anahtar[20] = {1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4};
	struct sinav vize;
	int i,j,n,d,y,b;
	
	for (j=0;j<size;j++){
		vize.numara[j]=1000+i;
		vize.sonuc[j][0]=0;vize.sonuc[j][1]=0;vize.sonuc[j][2]=0;
		for (i=0;i<size;i++){
			vize.cevaplar[j][i] = rand () % 5 ;
		}}	
	
	for (j=0;j<size;j++){
		d=0;y=0;b=0;
		for (i=0;i<size;i++){
			if (vize.cevaplar[j][i]==anahtar[i])
				d++;
			else if (vize.cevaplar[j][i]==0)
				b++;
			else
				y++;
		}
		vize.sonuc[j][0]=d; vize.sonuc[j][1]=y;	vize.sonuc[j][2]=b;
	}
	printf ("Cevap Anahtari:");
	for (j=0;j<size;j++)
		printf ("\n%d. %d",j+1,anahtar[j]);
	
	for (j=0;j<size;j++){
	printf ("\n%d.ogrencinin cevaplari:",j+1);
		for (i=0;i<size;i++){
			printf ("\n%d. soru = %d",i+1,vize.cevaplar[j][i]);
		}
	
	printf ("\nDogru sayisi = %d Yanlis Sayisi = %d Bos Sayisi = %d",vize.sonuc[j][0],vize.sonuc[j][1],vize.sonuc[j][2]);
	}
	
	fprintf (bys, "Cevap Anahtari:");
	for (j=0;j<size;j++)
		fprintf (bys , "\n%d. %d",j+1,anahtar[j]);
	
	for (j=0;j<size;j++){
	fprintf (bys,"\n%d.ogrencinin cevaplari:",j+1);
		for (i=0;i<size;i++){
			fprintf (bys,"\n%d. soru = %d",i+1,vize.cevaplar[j][i]);
		}
	
	fprintf (bys,"\nDogru sayisi = %d Yanlis Sayisi = %d Bos Sayisi = %d",vize.sonuc[j][0],vize.sonuc[j][1],vize.sonuc[j][2]);
	}
	
	
}
