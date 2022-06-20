#include <stdio.h>
#define adet 3
struct sayi{
	int sayi;
	int basamak[6];
	int n;
};

int main (){
	int j,i,temp,b;
	struct sayi basamak[adet];
	
	for (i=0;i<adet;i++){
		printf ("Maksimum 6 basamakli %d.Sayiyi Giriniz: ",i+1);
		scanf ("%d",&basamak[i].sayi);
	}
	
	for (i=0;i<adet;i++){
		temp = basamak[i].sayi;
		basamak[i].n=0;
		for (j=5;j>=0;j--){
			basamak[i].basamak[j] = temp % 10;
			temp = temp / 10;
		}	
		temp = basamak[i].sayi;
		while (temp>0){
			temp = temp / 10;
			basamak[i].n++;
		}
	}
	for (i=0;i<adet;i++){
		printf("\n");
		for (j=0;j<6;j++){
			if (basamak[i].basamak[j]==1 && j==5 || (basamak[i].basamak[j]==1 &&basamak[i].n>4 && j==2)) printf ("bir ");
			if (basamak[i].basamak[j]==2 && (j!=1 && j!=4) ) printf ("iki ");
			if (basamak[i].basamak[j]==3 && (j!=1 && j!=4) ) printf ("uc ");
			if (basamak[i].basamak[j]==4 && (j!=1 && j!=4) ) printf ("dort ");
			if (basamak[i].basamak[j]==5 && (j!=1 && j!=4) ) printf ("bes ");
			if (basamak[i].basamak[j]==6 && (j!=1 && j!=4) ) printf ("alti ");
			if (basamak[i].basamak[j]==7 && (j!=1 && j!=4) ) printf ("yedi ");
			if (basamak[i].basamak[j]==8 && (j!=1 && j!=4) ) printf ("sekiz ");
			if (basamak[i].basamak[j]==9 && (j!=1 && j!=4) ) printf ("dokuz ");
		
			if ((basamak[i].basamak[0]>0 && j==0)||(basamak[i].basamak[3]>0 && j==3)) printf ("yuz ");	
			
			if ((basamak[i].basamak[1]>0 && j==1)||(basamak[i].basamak[4]>0 && j==4)){
				if (basamak[i].basamak[j]==1)	printf ("on ");
				if (basamak[i].basamak[j]==2)	printf ("yirmi ");
				if (basamak[i].basamak[j]==3)	printf ("otuz ");
				if (basamak[i].basamak[j]==4)	printf ("kirk ");
				if (basamak[i].basamak[j]==5)	printf ("elli ");
				if (basamak[i].basamak[j]==6)	printf ("altmis ");
				if (basamak[i].basamak[j]==7)	printf ("yetmis ");
				if (basamak[i].basamak[j]==8)	printf ("seksen ");
				if (basamak[i].basamak[j]==9)	printf ("doksan ");								
			}
			if (basamak[i].basamak[2]>0  && j==2) printf ("bin ");
		}
	}	
}
