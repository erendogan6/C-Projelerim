#include <stdio.h>
// Kare mi / Dikdörtgen mi?
/*
Örnek matrisler:
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0


*/

main (){
	int ust=0,yan=0,i,j,n,depo,satir=10,sutun=10;
	//printf ("satir ve sutun sayisi giriniz: ");
	//scanf ("%d %d",&satir,&sutun);
	satir =satir+2; sutun = sutun +2;
	printf ("Matris giriniz: \n");
	int matris[satir][sutun];
	
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			matris[i][j]=0;
		
	for (i=1;i<satir-1;i++){
		for (j=1;j<sutun-1;j++){
			scanf ("%d",&matris[i][j]);
		}
	}
	

	for (i=1;i<satir-1;i++){
		for (j=1;j<sutun-1;j++){
			if (matris[i][j]==1)
				if (matris[i-1][j]==0)
					ust++;
			if (matris[i][j]==1)
				if (matris[i][j+1]==0)
					yan++;
		}
	}
	
	
	if (ust==yan)
		printf ("Kare");
		
	else
		printf ("Dikdortgen");
	
	
	
	
	
	return 0;
}
