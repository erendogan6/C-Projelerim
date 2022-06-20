#include <stdio.h>
// verilen labirentin çözümünü bulur.
main (){
/*
Örnek Labirentler:

10*10 		
	
0 0 0 0 0 0 0 1 0 0
0 0 0 1 0 0 0 1 0 0
0 1 1 1 1 1 0 1 0 0
0 1 0 0 0 1 1 1 1 0
0 1 0 0 0 0 0 1 0 0
0 1 1 1 1 0 1 1 0 0
0 0 1 0 1 0 0 1 1 0
0 0 1 0 1 0 0 0 1 0
0 1 1 0 1 0 1 1 1 0
0 0 0 0 1 0 0 0 0 0
	
12 * 12

0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 1 1 1 0
0 0 0 1 0 0 0 0 1 0 0 0
0 1 0 1 1 1 1 0 1 1 1 0
0 1 0 1 0 0 0 0 0 0 1 0
0 1 0 1 1 1 0 1 1 0 1 1
0 1 0 0 0 1 0 1 0 0 0 0
0 1 1 1 1 1 0 1 1 1 1 0
0 0 1 0 1 0 0 1 0 0 1 0
0 0 1 0 1 1 1 1 0 0 1 0
1 1 1 0 0 1 0 1 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0

	
	*/
	
	int satir,sutun,n;
	printf ("Satir ve sutun uzunlugunu giriniz: ");
	scanf ("%d %d",&satir,&sutun);
	int i,j,dizi[satir][sutun];
	
	printf ("Labirenti giriniz: \n");
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			scanf("%d",&dizi[i][j]);

	for (n=1;n<satir*sutun;n++)	
		for (i=1;i<satir-1;i++)
			for (j=1;j<sutun-1;j++){
				if ((dizi[i][j-1]+dizi[i][j+1]+dizi[i-1][j]+dizi[i+1][j]+dizi[i][j])>2)
					continue;
				else
					dizi[i][j]=0;
			}

		for (i=1;i<satir-1;i++)
			for (j=1;j<sutun-1;j++){
					if (dizi[i][j]==1)
					if ((dizi[i][j-1]+dizi[i][j+1]+dizi[i-1][j]+dizi[i+1][j])>2){
						dizi[i][j]=3;
				}	
			}
		for (j=0;j<satir;j++){
				if (dizi[0][j]==1)
					dizi[0][j]=2;
		}
		for (j=0;j<satir;j++){
				if (dizi[satir-1][j]==1)
					dizi[satir-1][j]=2;
		}
		for (i=0;i<sutun;i++){
				if (dizi[i][0]==1)
					dizi[i][0]=2;
		}
		for (i=0;i<sutun;i++){
				if (dizi[i][sutun-1]==1)
					dizi[i][sutun-1]=2;
		}
	
		for (i=0;i<satir;i++){
			for (j=0;j<sutun;j++){
				if (dizi[i][j]==1){
					if (dizi[i-1][j]==2 || dizi[i-1][j]==3 ){
						dizi[i][j]=2;
						continue;
					}
					if (dizi[i+1][j]==2 || dizi[i+1][j]==3){
						dizi[i][j]=2;
						continue;
					}
					if (dizi[i][j+1]==2 || dizi[i][j+1]==3){
						dizi[i][j]=2;
						continue;
					}
					if (dizi[i][j-1]==2 || dizi[i][j-1]==3){
						dizi[i][j]=2;
						continue;
					}
				}
			}
		}
	
	for (i=0;i<satir;i++){
		printf ("\n");
		for (j=0;j<sutun;j++){
				printf("%d ", dizi[i][j]);
		}
	}
	
	
	
	return 0;
}
