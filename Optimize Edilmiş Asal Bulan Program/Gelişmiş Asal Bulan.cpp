/* Normal asal say� bulma algoritmalar�na g�re �ok daha h�zl� �al��an ve bilgisayar� �ok daha az yoran
asal say� bulma algoritmas�. Algoritma i�in �e�itli matematiksel form�lller ve mant�ksal i�lemler uygulad�m. 
En iyisi de�il fakat �o�undan iyi.*/
#include <iostream>
#include <cmath>

	using namespace std;
	int main() {
    long long int carpan = 1,i, j; // B�y�k basamakl� say�lar ile �al��abilmek i�in long long integer kulland�m.
    int hata,sayi=0;
    cout << "Girilen basamak sayisindaki asal sayilari bulan program: " ; // Basamak say�s�na g�re asal bulunuyor.
	cin >> sayi;
	
    if (sayi<=0){ // Kullan�c� basamak say�s�na 0 dan k���k girerse hata veriyor
    	cout <<"Hatali giris yaptiniz." << endl;
    	return 0;
	}
	
    for (i = 1; i <= sayi - 1; i++)  // Girilen x basamakl� say� hesaplan�yor
        carpan = carpan * 10;
    
    for (i=(carpan*10)-1;i>=carpan+1;i-=2){// e�er basamak olarak 5 girildi ise 99999 dan 10001 e kadar tarama yap�l�yor. 
        hata = 0;						   // 2 Hari� Hi�bir �ift say� asal say� olamayaca�� i�in i de�eri sadece tek say�lar �zerinde geziniyor.
        for (j = 3; j <= sqrt(i); j += 2) {// bir say�n�n karek�k�nden daha b�y�k bir b�leni olamayaca�� i�in b�len sadece karek�ke kadar
        								   // ilerliyor. bu sayede gereksiz kontrol ad�mlar� atlanm�� oluyor.
            if (i % j == 0) {			   // e�er say� asal de�ilse d�ng� direk bitiyor ve yeni say�ya ge�iliyor.
                hata = 1;					// e�er say� asal ise ekrana yazd�r�l�yor.
                break;
            }
        }
        if (hata == 0 && i != 1) 
            cout << i << endl;
    }
    
    if (sayi == 1)
        cout << "2" << endl;
    
    return 0;
}
