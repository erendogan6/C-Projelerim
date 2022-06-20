#include <stdio.h>

// Þekil sayma (Kare + Dikdörtgen + Diðer Tüm Ýhtimaller)

/*

0 0 0 0 0 0 0 0 0 0
1 1 1 0 0 0 1 1 1 0
0 1 0 0 1 0 1 1 1 0
1 1 0 1 1 0 0 0 1 0
0 0 1 1 1 1 1 0 1 0
0 0 0 0 1 1 0 0 1 0
0 0 0 0 1 0 0 0 1 0
0 1 1 0 1 0 0 0 1 0
0 1 1 1 1 1 0 0 1 0
0 1 1 1 1 1 0 0 1 0

*/

main (){
	int sayac=2,n,satir=10,sutun=10,tutsakmi=1;
	//printf ("Genel seklin satir ve sutun uzunlugunu giriniz: ");
	//scanf ("%d %d",&satir,&sutun);
	int dizi[satir][sutun],i,j,a,b;
	printf ("Matrisi Giriniz(kod satirlarinda ornek matris vardir): \n")
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			scanf ("%d",&dizi[i][j]);
	
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++){	
			if (dizi[i][j]==1){
				dizi[i][j]=sayac;
			for (n=1;n<1000;n++)	
				for (a=0;a<satir;a++){
					for (b=0;b<sutun;b++)
						if (dizi[a][b]==1){
							if (b>0)
							if (dizi[a][b-1]==sayac)
							dizi[a][b]=sayac;
							if (b<sutun-1)
							if (dizi[a][b+1]==sayac)
							dizi[a][b]=sayac;
							if (dizi[a-1][b]==sayac)
							dizi[a][b]=sayac;
							if (dizi[a+1][b]==sayac)
							dizi[a][b]=sayac;
						}
				}
			sayac++;	
			}				
		}
	
	printf ("sekil sayisi: %d",sayac-2);
	
	return 0;
}
