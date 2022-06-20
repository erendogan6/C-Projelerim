// çarpým tablosunu rekursif olarak yazdýrma
#include <stdio.h>

int rec (int n){
	int i;
	if (n < 10){
		for (i=1;i<11;i++){
			printf ("%d ",n*i);
		}
	printf ("\n");
	return rec (n+1);
	}
	else
		return 1;
	
}

int main (){
	rec (1);
}
