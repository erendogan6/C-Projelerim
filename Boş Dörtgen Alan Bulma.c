// En büyük BOÞ dörtgen alan bulma

/*
Örnek girdiler

1 0 0 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0
1 0 0 0 1 0 0 1 0 0
0 0 1 0 0 1 0 0 1 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 1 0 0 0 0 0
0 1 0 0 0 0 0 1 0 0

0 0 0 1 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0
0 1 1 0 1 1 1 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0
0 1 1 1 0 0 1 0 0 0
0 1 0 0 0 0 1 0 0 0
1 1 0 0 1 1 1 0 1 1
1 0 0 0 1 0 0 0 1 1
0 0 0 0 0 0 0 1 0 0

*/
#include <stdio.h>
#define satir 10
#define sutun 10


main (){
	int i,j,n,k,p,r,s,depo,rakam,alan,matris[satir][sutun],max=0;
	printf ("Matrisi Giriniz: ");
	for (i=0;i<satir;i++){
			
		for (j=0;j<sutun;j++){
			scanf ("%d",&matris[i][j]);
		}
	}
	
	for (i=0;i<satir;i++){ // 1.nokta kordinat
		for (j=0;j<sutun;j++){ // 1.nokta kordinat
			 for (n=i;n<satir;n++){ //2.nokta kordinat
			 	for (p=j;p<satir;p++){ //2.nokta kordinat
			 	
					rakam= 0;
								 	
			  		for (k=i;k<=n;k++){ // bölgeyi tarama
			  			for (r=j;r<=p;r++){ // bölgeyi tarama
			  				if (matris[k][r]==1)
			  					rakam=1;
						  }
					  }
			 	alan = (n-i+1) * (p-j+1);
			 	if (rakam == 0 && alan > max)
			 		max=alan;
			 }		 
		}
	}
	
	  
}
printf ("\nEn buyuk bos dortgen alan = %d", max);  

return 0;
}
