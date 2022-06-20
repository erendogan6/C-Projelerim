// Eren Doðan - Havalý Görünümlü, Ses Çýkaran, Enter Ýstemeyen, Yormayan, Okunaklý, Ýþlevsel Menü
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

typedef struct{
  int id;
  char metin[7];
}yapi;

void yazdir(char * );

int konsolbuyutucu(){
static CONSOLE_FONT_INFOEX  fontex;
     fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
     HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
     GetCurrentConsoleFontEx(hOut, 0, &fontex);
     fontex.FontWeight = 5000;
     fontex.dwFontSize.X = 22;
     fontex.dwFontSize.Y = 22;
     SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}



void dosyaYaz(){
  FILE *fptr;
  fptr = fopen("dosya1.txt","w");
  char sesli[] = {"aeiou"};
  char sessiz[] = {"qwrtypsdfghjklzcvbnm"};
  char *yeni = (char*)malloc(sizeof(char)*6);
  int id=0;
  int k,i;
  for(k=0;k<15;k++){
      for(i=0;i<6;i+=2){
          yeni[i] = sesli[rand()%5];
          yeni[i+1] = sessiz[rand()%20];
      }
      id = rand()%80+20;
      fprintf(fptr, "%d %s\n", id, yeni);
  }
  fclose(fptr);
  printf("ID ve Metin rastgele uretilmis.\n");
  yazdir("dosya1.txt");
}

void dosyaIDSirala(yapi *yptr){
  FILE *fptr;
  int gecicind=0, gecicid=0;
  yapi geciciYapi;
  int i,k;
  for(i=0;i<15;i++){
      gecicid = yptr[i].id;
      gecicind = i;
      for(k=i+1;k<15;k++)
          if(gecicid > yptr[k].id){
              gecicind = k;
              gecicid = yptr[k].id;
          }
      geciciYapi = yptr[i];
      yptr[i] = yptr[gecicind];
      yptr[gecicind] = geciciYapi;
  }
  fptr = fopen("dosya2.txt", "w");
  for(i=0;i<15;i++)
      fprintf(fptr, "%d %s\n", yptr[i].id, yptr[i].metin);
  fclose(fptr);
  printf("ID numarasina gore siralanmis.\n");
  yazdir("dosya2.txt");
}

void dosyaStrSirala(yapi *yptr){
  FILE *fptr;
  yapi geciciYapi;
  int i,k;
  for(i=0;i<15;i++){
      for(k=i+1;k<15;k++){
          if(i!=k){
              if( strcmp(yptr[i].metin, yptr[k].metin) > 0 ){
                  geciciYapi = yptr[i];
                  yptr[i] = yptr[k];
                  yptr[k] = geciciYapi;
              }
          }
      }
  }
  fptr = fopen("dosya3.txt", "w");
  for( i=0;i<15;i++)
      fprintf(fptr, "%d %s\n", yptr[i].id, yptr[i].metin);
  fclose(fptr);
  printf("Metine gore siralanmis.\n");
  yazdir("dosya3.txt");
}

void yazdir(char *dosyaYolu){
  FILE *fptr;
  fptr = fopen(dosyaYolu, "r");
  yapi gecici;
  printf("ID Metin\n");
  while( fscanf(fptr, "%d %s", &gecici.id, gecici.metin) != EOF )
    {
  printf("%d %s\n", gecici.id, gecici.metin);}
  fclose(fptr);
}

int main(){
	int i=0;
	 konsolbuyutucu();
	system("color a0");
	system("cls");
	int secim;
	
		for (i=0;i<100;i++){
		printf ("SISTEM ACILIYOR. LUTFEN SAKIN OLUN VE EKRANA TIKLAYIP DURMAYIN!");
		printf ("\nYukleniyor iste : %%%d ",i);
			
			if (i<20){
				printf ("\nNerede bu dosyalar ya");
			}
			else if (i<40){
				printf ("\nTamam Buldum");
			}
			else if (i<60){
				printf ("\nAz Kaldi");
			}
			else if (i<80){
				printf ("\nBitti Sayilir");
			}
			else if (i<100){
				printf ("\nBasliyor Yine Bizim Mesai");
			}
			usleep(1000);
			system("cls");
		}
	do{
	printf ("Ana Menuye Hosgeldiniz. \nSecim yapmak icin numaralari kullaniniz \n(1-Rastgele Degerleri Dosyaya Yazdir)\n(2-ID'ye Gore Sirala)\n(3-Metine Gore Sirala)\n(4-Cikis)");
	secim = getch () - 48;
	system("\a");
	system("cls");
	if (secim==4){
		return 0;
	}
	srand(time(NULL));
	if (secim==1){
		dosyaYaz();
	}
  FILE *fptr;
  fptr = fopen("dosya1.txt", "r");
  yapi yapiDizi[15];
  i=0;
  while( fscanf(fptr, "%d%s", &yapiDizi[i].id, yapiDizi[i].metin) != EOF ) i++;
  fclose(fptr);
	if (secim==2){
		dosyaIDSirala(yapiDizi);
		
	}
	if (secim==3){
	 dosyaStrSirala(yapiDizi);
	}

}while (secim!=4);
  
}
