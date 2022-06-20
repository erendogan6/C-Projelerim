#include <stdio.h>

#define satir 12
#define sutun 12

// Ýki ucu boþta olan ve kapalý herhangi bir alan oluþturmayan bir çizginin
// tam orta noktasýna karþýlýk gelen hücreye "0" yazar ve çizgiyi iki
// parçaya ayýrýr.

/*

0 1 1 1 1 1 0 0 0 0
0 1 0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0 0 0
0 1 1 1 0 1 1 1 0 0
0 0 0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0


1 0 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 1
1 0 1 0 1 1 1 1 0 1
1 0 1 0 1 0 0 1 0 1
1 0 1 0 1 0 0 1 0 1
1 0 1 0 1 1 0 1 0 1
1 0 1 0 0 0 0 1 0 1
1 0 1 1 1 1 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1


0 0 0 0 0 0 0 1 1 1
1 0 0 1 1 1 0 1 0 1
1 0 0 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1 0 1
1 0 0 1 0 1 0 1 0 1
1 1 1 1 0 1 0 1 0 1
0 0 0 0 0 1 0 1 0 1
0 0 0 0 0 1 1 1 0 1


0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 1 1 0 0
0 0 1 0 0 0 0 1 0 0
0 0 1 0 0 0 0 1 0 0
0 0 1 0 0 0 0 1 0 0
0 0 1 0 0 0 0 1 0 0
0 0 1 1 0 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0


*/

main () { 
	printf ("Matrisi giriniz (Kod satirlarinda ornek matris mevcuttur.): ");
	int i,j,depo,test,n,sonuc,adet=0,len=0,dizi[satir][sutun]={0};
	
	for (i=1;i<satir-1;i++){
		for (j=1;j<sutun-1;j++){
			scanf ("%d",&dizi[i][j]);
		}
	}
		
	for (i=0;i<satir;i++){
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==1)
				len++;
		}
	}	
	
	printf ("Toplam uzunluk == %d",len);
	
	
	sonuc = 0;
	for (i=0;i<satir;i++){
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==1){
				test = dizi[i+1][j] + dizi[i-1][j] + dizi[i][j-1] + dizi[i][j+1];
					if(test < 2){
						dizi[i][j]=2;
						sonuc=1;
						break;
					}
				if (sonuc ==1)
					break;
			}
		}
	}
	
	sonuc=0;
	for (n=0;n<=200 && sonuc!=1;n++)
	for (i=0;i<satir && sonuc !=1 ;i++){
		for (j=0;j<sutun;j++){
			if (dizi[i][j]==2){
				
				if (dizi[i+1][j]==1){
					dizi[i+1][j]=2;
					adet++;
					if (adet==len/2){
					dizi[i+1][j]=0;
					sonuc=1;
					break;
					}
				}
				if (dizi[i-1][j]==1){
					dizi[i-1][j]=2;
					adet++;
					if (adet==len/2){
					dizi[i-1][j]=0;
					sonuc=1;
					break;
					}
				}
				if (dizi[i][j-1]==1){
					dizi[i][j-1]=2;
					adet++;
					if (adet==len/2){
					dizi[i][j-1]=0;
					sonuc=1;
					break;
					}
				}
				if (dizi[i][j+1]==1){
					dizi[i][j+1]=2;
					adet++;
					if (adet==len/2){
					dizi[i][j+1]=0;
					sonuc=1;
					break;
					}
				}
				
			}
			 
			 
			 }
			
		}
		printf ("\n");
		for (i=1;i<satir-1;i++){
		printf ("\n");
		for (j=1;j<sutun-1;j++){
			if (dizi[i][j]==1 || dizi[i][j]==2)
				printf("1 ");
			else
				printf ("0 ");
		}
	}	
	
	
	
	return 0;
}




