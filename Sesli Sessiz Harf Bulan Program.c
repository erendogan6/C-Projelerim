#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 20
#define eln 3

int i,j,k;

struct test {
	char kelime[size];
	int sesli;
	int sessiz;
	int rakamlar;
};

void atama (struct test *ptr){
	
	for (i=0;i<eln;i++){
	
	printf ("Kelime Giriniz: ");
	scanf ("%s",ptr[i].kelime);
	}
}

void kontrol (struct test *ptr){
	int sesli[] = {65, 69, 73, 79, 85};
	int sessiz[] = {66,67,68,70,71,72,74,75,76,77,78,80,81,82,83,84,86,87,88,89,90};
	for (k=0;k<eln;k++){
	
	ptr[k].sesli=0; ptr[k].sessiz=0; ptr[k].rakamlar=0;
	int carpan = 1;
	
	for (j=0;j<strlen(ptr[k].kelime);j++){
		for (i=0;i<5;i++){
			if (ptr[k].kelime[j]<= 90 && ptr[k].kelime[j]>= 65){
				if (ptr[k].kelime[j]==sesli[i])
					ptr[k].sesli++;
				}
			else if (ptr[k].kelime[j]>= 97 && ptr[k].kelime[j] <= 122)
				if ((ptr[k].kelime[j])-32==sesli[i])
					ptr[k].sesli++;
		}
		
		for (i=0;i<21;i++){
			if (ptr[k].kelime[j]<= 90 && ptr[k].kelime[j]>= 65){
				if (ptr[k].kelime[j]==sessiz[i])
					ptr[k].sessiz++;
				}
			else if (ptr[k].kelime[j]>= 97 && ptr[k].kelime[j] <= 122)
				if ((ptr[k].kelime[j])-32==sessiz[i])
					ptr[k].sessiz++;
		}
	}
	
	for (j=j-1;j>=0;j--){
		for (i=48;i<=57;i++){
			if (ptr -> kelime[j] == i){
				ptr[k].rakamlar += (ptr[k].kelime[j]-48) * carpan;
				carpan *=10;
			}
		}
	}
	}
}

void yazdir (struct test *ptr){
	for (k=0;k<eln;k++)
		printf ("\n%d. Kelimenin \nSesli harf sayisi: %d\nSessiz harf sayisi: %d\nRakamlar: %d",k+1,ptr[k].sesli,ptr[k].sessiz,ptr[k].rakamlar);
}

int main (){
	struct test ornek[eln];
	atama (ornek);
	kontrol (ornek);
	yazdir (ornek);
	
	return 0;
}
