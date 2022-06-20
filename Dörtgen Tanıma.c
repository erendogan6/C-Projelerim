#include <stdio.h>
// Düzgün þekilleri (dörtgenleri - kare ve dikdörtgen) sayar.

/*

0 1 1 0 0 1 1 0 0 1
0 1 1 0 0 0 0 0 0 1
0 1 1 0 1 1 1 0 0 1
1 0 0 0 1 1 1 0 0 1
1 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 0
0 1 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 1 0 0 0 1

*/
main (){
	int satir=10,sutun=10;
	//printf ("Genel seklin satir ve sutun uzunlugunu giriniz: ");
	//scanf ("%d %d",&satir,&sutun);
	satir=satir+1; sutun=sutun+1;
	int i,j,n,adet=0;
	int dizi[satir][sutun];
	printf ("Ornek matrisi giriniz(kod satirlarinin icinde mevcuttur): ");
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			dizi[i][j]=0;
	
	for (i=1;i<satir;i++)
		for (j=1;j<sutun;j++)
			scanf ("%d",&dizi[i][j]);
	
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			if (dizi[i][j]==1)	
				if (dizi[i][j-1]==0 && dizi[i-1][j]==0)
					adet++;
	
	printf ("%d Adet dortgen var",adet);
	
	return 0;
}
