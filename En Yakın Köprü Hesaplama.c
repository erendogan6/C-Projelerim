// Birbirlerine yatay, dikey ve çapraz olarak temas etmeyen iki blok arasýndaki
// en kýsa mesafenin kaç birim olduðunu bulur ve bu mesafeyi iþaretler.
// (köprü yapma uygulamasý)
#include <stdio.h>

#define satir 17
#define sutun 17

/*

0 0 0 1 1 1 1 1 0 0 0 0 0 0 0
0 0 0 1 1 1 1 1 0 0 0 0 0 0 0
0 0 0 1 1 0 0 1 1 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0 0 1 0 0 0
0 0 0 1 1 0 0 0 0 0 0 1 0 0 0
0 0 0 1 1 1 0 0 0 0 0 1 0 1 0
0 0 0 1 0 0 0 0 1 0 0 1 0 1 1
0 0 1 1 0 0 0 0 1 0 0 1 1 1 0
0 0 1 0 0 0 0 0 1 0 0 1 1 0 0
0 1 1 0 0 0 0 0 1 1 1 1 1 1 1
0 1 0 0 0 0 1 1 1 0 0 1 1 1 1
1 1 1 0 0 0 0 1 0 0 0 0 0 0 0
1 0 0 0 0 1 1 1 1 1 0 0 0 0 0
1 1 0 0 0 0 1 1 1 1 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0 0 0 0 0 0


0 0 0 0 1 1 1 1 1 1 1 1 0 0 0
0 0 0 0 1 0 0 0 0 0 0 1 0 0 0
1 0 0 0 1 0 0 0 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0 0 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 1 0 0 0 1 0 0 1 0 0 1
1 0 0 0 0 0 0 0 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 1 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1


0 0 1 0 0 0 0 0 1 1 1 1 1 1 1
0 0 1 0 0 0 0 0 0 1 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0 1 1 1 1 1
1 1 1 1 0 0 0 0 0 0 0 1 1 1 1
1 1 1 1 1 1 0 0 0 0 0 0 1 1 1
1 1 1 1 1 1 0 0 0 0 0 0 0 1 1
1 1 1 1 1 1 0 0 0 0 0 0 1 1 1
1 1 1 1 1 1 0 0 0 0 0 1 1 1 1
1 1 0 0 0 0 0 0 0 0 1 1 1 1 1
1 1 0 0 0 0 0 0 0 1 1 1 1 1 1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1
0 0 0 0 0 0 1 1 1 1 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1 1 1 1 1 1
0 0 0 0 1 1 1 1 1 1 1 1 1 1 1
0 0 0 1 1 1 1 1 1 1 1 1 1 1 1


0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1 0 0 0 1
0 0 0 0 0 0 0 0 0 0 1 1 0 1 1
0 0 0 0 0 0 0 0 0 0 1 1 0 1 1
0 0 0 0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 1 0 0 0 0 0 0 0
0 1 1 1 0 0 0 1 1 1 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1 0 0 0 0 0
0 0 1 1 1 1 1 1 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 0 0 0 0


0 0 0 0 0 0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
1 1 0 0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 0 0 0 0 0 0 1 1 0 0 0 0
0 0 1 1 0 0 0 0 0 0 1 1 1 1 0
0 0 0 1 1 0 0 0 0 0 0 1 1 0 0
0 0 0 0 1 0 0 0 0 0 0 0 1 1 0
0 0 1 1 1 1 0 0 0 0 0 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 1 1 0 1 0 0
0 0 0 0 0 0 0 0 1 1 0 0 1 0 0
0 0 0 0 0 1 1 1 1 0 0 0 0 0 0

*/

main () { 
	printf ("Matrisi giriniz (Kod satirlarinda ornek matris mevcuttur.): ");
	int dizi[satir][sutun]={0},i,j,depo,n,test,hedef,sonuc,sayac=2,len=100,x,y,yon;
	
	// diziyi okudum
	for (i=1;i<satir-1;i++){
		
		for (j=1;j<sutun-1;j++){
			scanf ("%d",&dizi[i][j]);
			
		}
	}
 	// sekili tespit ettim
 	sonuc =0;
	for (i=0;i<satir && sonuc !=1;i++){
		
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==1){
				dizi[i][j]=2;
				sonuc=1;
				break;
				
			}			
		}
	}

	for (n=0;n<=500;n++)
	for (i=0;i<satir;i++){
		
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==2){
				if (dizi[i+1][j]==1){
					dizi[i+1][j]=2;
				}
				if (dizi[i-1][j]==1){
					dizi[i-1][j]=2;
				}
				if (dizi[i][j+1]==1){
					dizi[i][j+1]=2;
				}
				if (dizi[i][j-1]==1){
					dizi[i][j-1]=2;
				}
				
			}			
		}
	}


	sonuc=0;
	for (i=0;i<satir && sonuc !=1;i++){
		
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==2){
				for (n=j;n<sutun-1;n++) // saða gider
					if (dizi[i][n]==1){
						if (n-j<len){
							len=n-j;
							x=j;
							y=i;
							yon=1;
						}
					}
				for (n=j;n>0;n--) // sola gider
					if (dizi[i][n]==1){
						if (j-n<len){
							len=j-n;
							x=j;
							y=i;
							yon=2;
						}
					}
				for (n=i;n<satir-1;n++) // asagi gider
					if (dizi[n][j]==1){
						if (n-i<len){
							len=n-i;
							x=j;
							y=i;
							yon=3;
						}
					}
				for (n=i;n>0;n--) // yukari gider
					if (dizi[n][j]==1){
						if (i-n<len){
							len=i-n;
							x=j;
							y=i;
							yon=4;
						}
					}	
			}			
		}
	}
	sayac=1;
	if (yon==1){ // saga yazar
		for (i=x+1;i<x+len;i++){
		dizi[y][i]=254;
	}
	}
	
	if (yon==2){ // sola yazar
		for (i=x-1;i>x-len;i--){
		dizi[y][i]=254;
	}
	}
		if (yon==3){ // asagi yazar
		for (i=y+1;1;i++){
		if (sayac==len)
			break;
		dizi[i][x]=254;
		sayac++;
	}
	}
	if (yon==4){ // yukari yazar
		for (i=y-1;1;i--){
		if (sayac==len)
			break;
		dizi[i][x]=254;
		sayac++;
	}
	}
		for (i=1;i<satir-1;i++){
		printf ("\n");
		for (j=1;j<sutun-1;j++){
			if (dizi[i][j]==254)
			printf ("%c ",254);
			else if (dizi[i][j]!=0)
				printf ("1 ");
			else
				printf ("0 ");
		}
	}
	if (len >90){
		printf ("Komsu degil.");
	}
	else
	printf ("\n\nEn kisa uzunluk = %d \nKordinatlar : x= %d , y=%d",len-1,x+1,y+1);

return 0;
}
