#include <stdio.h>
/*
Birincisi büyük ikincisi küçük ve basamak sayýlarý (maks. 50) ayný olmak þartýyla girilen iki pozitif tam sayý
arasýndaki farký bulur.

Örnek Ekran Çýktýsý
1. sayiyi giriniz: 12345678901234567890123456789012345
2. sayiyi giriniz: 12345678901234567890123456789012344
Sonuc = 1

Örnek Ekran Çýktýsý 
1. sayiyi giriniz: 7891214000012200000001
2. sayiyi giriniz: 3548999919009999199999
Sonuc = 4342214081002200800002

*/
main (){
	char sayi1[50],sayi2[50],sonuc[50]={0},test;
	int i,j,depo,n,k,hedef,len,aldigimyer,basladigimyer,hata=0,bastimmi=0;
	printf ("1. sayiyi giriniz: ");
	
	for (i=0;;i++){
		scanf ("%c",&test);
		if (test=='\r' || test==13 || test==10 )
			break;
		sayi1[i]=test-48;
		
	}
	printf ("2. sayiyi giriniz: ");
	for (i=0;;i++){
		scanf ("%c",&test);
		if (test=='\r' || test==13 || test==10 )
			break;
		sayi2[i]=test-48;
		
	}
	len=i;
	n=0;
	for (i=len-1;i>=0 && hata != 1;i--){
		if (sayi1[i]-sayi2[i]<0){
			basladigimyer=i;
			for (j=i-1;hata!=1;j--){
				if (sayi1[j]>0){
					sayi1[j]--;
					aldigimyer=j;
					break;
				}
				else if (j<0){
					hata=1;
					break;
				}
			}
			for (j=aldigimyer+1;hata!=1 || j<=len;j++){
				if (hata==1)
					break;
				if (j==basladigimyer){
					sayi1[j]=sayi1[j]+10;
					break;
						}
				else
					sayi1[j]=9;
				
			}
			i++;
		}
		
		else{
			sonuc[i]=sayi1[i]-sayi2[i];
			n++;
		}
	
	}
	bastimmi=0;
	printf ("\n Sonuc = ");
	for (i=0;i<n;i++){
		if (sonuc[i]>0 ){
			bastimmi=1;
		}
		
		if (bastimmi==1)
		printf ("%d",sonuc[i]);
	}
	
	return 0;
}
