/* Normal asal sayý bulma algoritmalarýna göre çok daha hýzlý çalýþan ve bilgisayarý çok daha az yoran
asal sayý bulma algoritmasý. Algoritma için çeþitli matematiksel formülller ve mantýksal iþlemler uyguladým. 
En iyisi deðil fakat çoðundan iyi.*/
#include <iostream>
#include <cmath>

	using namespace std;
	int main() {
    long long int carpan = 1,i, j; // Büyük basamaklý sayýlar ile çalýþabilmek için long long integer kullandým.
    int hata,sayi=0;
    cout << "Girilen basamak sayisindaki asal sayilari bulan program: " ; // Basamak sayýsýna göre asal bulunuyor.
	cin >> sayi;
	
    if (sayi<=0){ // Kullanýcý basamak sayýsýna 0 dan küçük girerse hata veriyor
    	cout <<"Hatali giris yaptiniz." << endl;
    	return 0;
	}
	
    for (i = 1; i <= sayi - 1; i++)  // Girilen x basamaklý sayý hesaplanýyor
        carpan = carpan * 10;
    
    for (i=(carpan*10)-1;i>=carpan+1;i-=2){// eðer basamak olarak 5 girildi ise 99999 dan 10001 e kadar tarama yapýlýyor. 
        hata = 0;						   // 2 Hariç Hiçbir çift sayý asal sayý olamayacaðý için i deðeri sadece tek sayýlar üzerinde geziniyor.
        for (j = 3; j <= sqrt(i); j += 2) {// bir sayýnýn karekökünden daha büyük bir böleni olamayacaðý için bölen sadece kareköke kadar
        								   // ilerliyor. bu sayede gereksiz kontrol adýmlarý atlanmýþ oluyor.
            if (i % j == 0) {			   // eðer sayý asal deðilse döngü direk bitiyor ve yeni sayýya geçiliyor.
                hata = 1;					// eðer sayý asal ise ekrana yazdýrýlýyor.
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
