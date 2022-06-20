#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct hisse {
	char adi[50];
	int gunlukDegeri[30];
	int alim;
	int satim;
	int maxfark;};

main (){
	srand(time(NULL));
	int i,j;
	struct hisse aselsan;
	strcpy(aselsan.adi,"Aselsan");
	struct hisse tupras;
	strcpy(tupras.adi,"Tupras");
	struct hisse sabanci;
	strcpy(sabanci.adi,"Sabanci");
	for (i=0;i<30;i++){
		aselsan.gunlukDegeri[i] = rand () % 95 + 5;
		tupras.gunlukDegeri[i] = rand () % 95 + 5;
		sabanci.gunlukDegeri[i] = rand () % 95 + 5; }
		
	printf ("\n-----------HISSE DEGERLERI----------\n");
	for (i=0;i<30;i++){
		printf ("\n%d mayisda %s hisse degeri: %d",i+1,aselsan.adi,aselsan.gunlukDegeri[i]);
		printf ("\n%d mayisda %s hisse degeri: %d",i+1,tupras.adi,tupras.gunlukDegeri[i]);
		printf ("\n%d mayisda %s hisse degeri: %d",i+1,sabanci.adi,sabanci.gunlukDegeri[i]); }
	
	for (i=0;i<30;i++){
		for (j=i;j<30;j++){
			if (aselsan.gunlukDegeri[j]>aselsan.gunlukDegeri[i] && aselsan.gunlukDegeri[j] -  aselsan.gunlukDegeri[i] > aselsan.maxfark){ 
				aselsan.maxfark = aselsan.gunlukDegeri[j] - aselsan.gunlukDegeri[i];
				aselsan.alim = i;
				aselsan.satim = j; }
			if (tupras.gunlukDegeri[j]>tupras.gunlukDegeri[i] && tupras.gunlukDegeri[j] -  tupras.gunlukDegeri[i] > tupras.maxfark){ 
				tupras.maxfark = tupras.gunlukDegeri[j] - tupras.gunlukDegeri[i];
				tupras.alim = i;
				tupras.satim = j; }
			if (sabanci.gunlukDegeri[j]>sabanci.gunlukDegeri[i] && sabanci.gunlukDegeri[j] -  sabanci.gunlukDegeri[i] > sabanci.maxfark){ 
				sabanci.maxfark = sabanci.gunlukDegeri[j] - sabanci.gunlukDegeri[i];
				sabanci.alim = i;
				sabanci.satim = j;}
		}
	}
	
	printf ("\n\n-----------AYLIK DONEM----------\n");
	
	printf ("\nAselsan hisselerinden aylik donemde max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
	aselsan.alim+1,aselsan.gunlukDegeri[aselsan.alim], aselsan.satim+1,aselsan.gunlukDegeri[aselsan.satim],((10000 / aselsan.gunlukDegeri[aselsan.alim] ) * aselsan.gunlukDegeri[aselsan.satim])-10000); 
	
	printf ("\nTupras hisselerinden aylik donemde max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
	tupras.alim+1,tupras.gunlukDegeri[tupras.alim], tupras.satim+1,tupras.gunlukDegeri[tupras.satim],((10000 / tupras.gunlukDegeri[tupras.alim] ) * tupras.gunlukDegeri[tupras.satim])-10000); 
	
	printf ("\nSabanci hisselerinden aylik donemde max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
	sabanci.alim+1,sabanci.gunlukDegeri[sabanci.alim], sabanci.satim+1,sabanci.gunlukDegeri[sabanci.satim],((10000 / sabanci.gunlukDegeri[sabanci.alim] ) * sabanci.gunlukDegeri[sabanci.satim])-10000); 
		
	printf ("\n\n-----------HAFTALIK DONEM----------\n");
	int t=7,h=1;;
	aselsan.maxfark=0; sabanci.maxfark=0; tupras.maxfark=0;
	for (i=0;i<30;i++){
		if (i%7==0 && i!=0){
			printf ("\n\nAselsan hisselerinden %d. haftada max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
			h,aselsan.alim+1,aselsan.gunlukDegeri[aselsan.alim], aselsan.satim+1,aselsan.gunlukDegeri[aselsan.satim],((10000 / aselsan.gunlukDegeri[aselsan.alim] ) * aselsan.gunlukDegeri[aselsan.satim])-10000); 
	
			printf ("\nTupras hisselerinden %d. haftada max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
			h,tupras.alim+1,tupras.gunlukDegeri[tupras.alim], tupras.satim+1,tupras.gunlukDegeri[tupras.satim],((10000 / tupras.gunlukDegeri[tupras.alim] ) * tupras.gunlukDegeri[tupras.satim])-10000); 
		
			printf ("\nSabanci hisselerinden %d. haftada max kar elde edebilmek icin 10.000 TL ile %d mayista %d TL degerinden hisse alip %d mayista %d TL degerinden satsaydiniz %d TL kar elde edecektiniz",
			h,sabanci.alim+1,sabanci.gunlukDegeri[sabanci.alim], sabanci.satim+1,sabanci.gunlukDegeri[sabanci.satim],((10000 / sabanci.gunlukDegeri[sabanci.alim] ) * sabanci.gunlukDegeri[sabanci.satim])-10000);
		
			aselsan.maxfark=0;sabanci.maxfark=0;tupras.maxfark=0;
			t+=7; h++; 	}
		
		for (j=i;j<t;j++){
			if (aselsan.gunlukDegeri[j]>aselsan.gunlukDegeri[i] && aselsan.gunlukDegeri[j] -  aselsan.gunlukDegeri[i] > aselsan.maxfark){ 
				aselsan.maxfark = aselsan.gunlukDegeri[j] - aselsan.gunlukDegeri[i];
				aselsan.alim = i;
				aselsan.satim = j; }
			if (tupras.gunlukDegeri[j]>tupras.gunlukDegeri[i] && tupras.gunlukDegeri[j] -  tupras.gunlukDegeri[i] > tupras.maxfark){ 
				tupras.maxfark = tupras.gunlukDegeri[j] - tupras.gunlukDegeri[i];
				tupras.alim = i;
				tupras.satim = j; }
			if (sabanci.gunlukDegeri[j]>sabanci.gunlukDegeri[i] && sabanci.gunlukDegeri[j] -  sabanci.gunlukDegeri[i] > sabanci.maxfark){ 
				sabanci.maxfark = sabanci.gunlukDegeri[j] - sabanci.gunlukDegeri[i];
				sabanci.alim = i;
				sabanci.satim = j;}
		}	
	}
	
	
return 0;	
}
