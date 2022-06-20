#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define satir 3
#define sutun 4
main (){
	srand(time(NULL));
	int t,n,rast,i,j,depo,test,hedef,sayac,max=0,min=100,sonuc=1,matris[satir][sutun]={0};
	printf ("Cozum, isleme bagli olarak uzun surebilmektedir.")
	
	for (t=0;t<=100;t++){
	
	for (i=0;i<satir;i++)
		for (j=0;j<sutun;j++)
			matris[i][j]=0;
	

	matris[1][2]=2;
	sonuc = 1;
	for (n=1;n<=1000000;n++){
		rast = rand () % 8;
	for (i=0;i<satir;i++){
		for (j=0;j<sutun;j++){
			if (matris[i][j]==2){
				if (rast==0 && i+1<satir && j-2>=0 && matris[i+1][j-2]==0 ){ // sol sol alt
					matris[i][j]=1;
					matris[i+1][j-2]=2;
					sonuc++;
					continue;
				}
				
				if (rast==1 && i+2<satir && j-1>=0 && matris[i+2][j-1]==0 ){ // alt alt sol
					matris[i][j]=1;
					matris[i+2][j-1]=2;
					sonuc++;
					continue;
				}
				
				if (rast==2 && i-2 >=0 && j-1>=0 && matris[i-2][j-1]==0 ){ // üst üst sol
					matris[i][j]=1;
					matris[i-2][j-1]=2;
					sonuc++;
					continue;
				}
				if (rast==3 && i-1 >=0 && j-2>=0 && matris[i-1][j-2]==0 ){ // sol sol üst
					matris[i][j]=1;
					matris[i-1][j-2]=2;
					sonuc++;
					continue;
				}
				if (rast==4 && i+2 <satir && j+1<sutun && matris[i+2][j+1]==0){ // alt alt sað 
					matris[i][j]=1;
					matris[i+2][j+1]=2;
					sonuc++;
					continue;
				}
				if (rast==5 && i+1 <satir && j+2<sutun && matris[i+1][j+2]!=1){ // sað sað alt 
					matris[i][j]=1;
					matris[i+1][j+2]=2;
					sonuc++;
					continue;
				}
				if (rast==6 && i-2 >=0 && j+1<sutun && matris[i-2][j+1]==0 ){ // üst üst sað
					matris[i][j]=1;
					matris[i-2][j+1]=2;
					sonuc++;
					continue;
				
				}
				if (rast==7 && i-1 >=0 && j+2<sutun && matris[i-1][j+2]==0 ){ // sað sað üst
					matris[i][j]=1;
					matris[i-1][j+2]=2;
					sonuc++;
					continue;
				
				}
					
			}			
			
		}
		
	  }
	  	if (sonuc > max)
			max = sonuc;
		
	  	if (sonuc < min && sonuc > 3)
	  		min = sonuc;
	  	
	}
	
	}
	
	printf (" Max = %d , min = %d",max,min);



	return 0;
}
