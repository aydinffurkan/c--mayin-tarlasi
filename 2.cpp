
/*
..Uygulama ile �lgili Genel A��klamalar..

AD SOYAD: FURKAN AYDIN
��RENC� NO: 180757046
B�L�M: B�LG�SAYAR M�HEND�SL���
DERS�N ADI: NESNEYE Y�NEL�K PROGRAMLAMA
AKADEM�K D�NEM: 4
PROJE NO:1
��RET�M �YES� ADI: G�L�AH
*/

#include<iostream>
#include<cstdlib> 
#include<ctime> 

using namespace std;

string secim;//secim de�i�kenimi global olarak tan�mlad�m.

//  fonksiyonlar�n protitiplerini olu�turdum.
void mayinyerlestirme(char d[6][5]);
void matrisibasma(char d[6][5]);
void tekrarsorusu();

int main()
{	
	srand(time(NULL));//Rastgele gelen de�eri her seferinde farkl� bir de�er almas�n� sa�lamas� i�in tan�mlad�m.
	int satir;//kullan�c�n�n girdi�i satir de�erini tuttu�um de�i�ken
	char oyunMat[6][5]; //6 satir 5 s�t�nluk matrisi olu�turdum
	
	tekrar:// Kullan�c� soruya evet dedi�inde goto fonksiyonu ile tekrardan program� ba�tan ba�latt�m.
		
	mayinyerlestirme(oyunMat);// Matrisi ve i�ine rastgele mayinlar� koydu�um fonksiyonu program�n ba��nda �a��rd�m.


	//kullan�c�dan alaca��m 6 adet sat�r bilgisi ve verdi�i sat�r bilgilerinin may�nla(X)'le kesisip kesi�medi�ini kontrol ettirdi�im bloktur. X le kesiti�inde
	//Patlayan indise "P" yazd�rd�m.
	for(int i=1;i<7;i++)
	{
	tekrar2:		
	cout<<"1-5 Arasi Deger Giriniz: ";//Kullan�c�dan 6 adet sat�r indisi girmesini istedim.
	cin>>satir;//satir bilgisini satir adl� de�i�kende tuttum.
	cout<<endl;
	if(satir>5)
	{
		cout<<"5'ten buyuk bir deger girdiniz..."<<endl;
		goto tekrar2;
	}
	
		//OyunMat matrisimin ilk k��eli parantezi sat�r� 2. k��eli parantezi ise s�t�nu temsil etti�inden kullan�c�dan ald���m satir de�i�keni ile
		//o andaki indiste may�n olup olmad���n� kontrol ettirdim.
		if(oyunMat[i-1][satir-1]=='X')
		{			
		oyunMat[i-1][satir-1]='P';// satir de�i�keni may�nla kesi�ti�i i�in o indise P yazd�rd�m.
		cout<<"Mayin Patladi. Uzgunum Maalesef Kaybettiniz!"<<endl;// May�na bas�ld��� i�in ekrana bilgi mesaj� verdim.
		cout<<endl;
		matrisibasma(oyunMat);//oyunun sonunda kullan�c�n�n yolunu ve patlayan may�n� matris halinde ekrana bast�rd�m.
		cout<<endl;
		tekrarsorusu();//kullan�c�ya tekrar oynay�p oynamak istemedi�i sorusunu soran fonksiyonu �a��rd�m.
		
			if(secim=="E"|| secim=="e")//Evet e bast��� taktirde goto fonksiyonu ile program� tekrardan ba�latt�m.
			{		
					
				goto tekrar;
								
			}
			else if(secim=="H"|| secim=="h")//Hay�r se�ene�ini se�ti�i taktirde program� sonland�rd�m.
			{	
					
   				exit(0);	
		   	
			}
		}
		
	oyunMat[i-1][satir-1]='O';//May�na basmad���ysa o andaki indise kullan�c�n�n yolu olan 'O' harfini yazd�m.
	
			if(i<6)
			{
	cout<<i+1<<". Satira Gectiniz"<<endl;//ka��nc� sat�rda oldu�unu i sayac� yard�m�yla kullan�c�ya verdim.	
	
			}
	
	cout<<endl;
	
	}
	
	//Bu blo�umda kazanma durumunu olu�turdum. Son sat�r�m�n t�m sutunlar�nda patlayan may�n yoksa kazand���n� belirttim.
	if(oyunMat[5][0]!= 'P' && oyunMat[5][1]!= 'P' && oyunMat[5][2]!= 'P' && oyunMat[5][3]!= 'P' && oyunMat[5][4]!= 'P')	
	{
		cout<<"Tebrikler Kazandiniz!"<<endl;
		cout<<endl;
		matrisibasma(oyunMat);//Matrisi bast�ran fonksiyonumu �a��rd�m.
		cout<<endl;
		tekrarsorusu();//Tekrar oynay�p oynamayaca��n� sorgulad�m.
		if(secim=="E"|| secim=="e")//Evet e bast��� taktirde goto fonksiyonu ile program� tekrardan ba�latt�m.
			{		
					
				goto tekrar;
								
			}
			else if(secim=="H"|| secim=="h")//Hay�r se�ene�ini se�ti�i taktirde program� sonland�rd�m.
			{	
					
   				exit(0);	
		   	
			}
	}
	   	
}
//Bu fonksiyona oyunMat isimli 2 boyutlu dizimin parametrelerini g�nderdim. Yeni dizime d ismini verdim.
void matrisibasma(char d[6][5]) // Matrisi bast�rd���m fonksiyon.
{
	
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<5;j++)
		{
		cout<<d[i][j]<<"  ";
		}
		cout<<endl;
	}	
}

//Bu fonksiyona oyunMat isimli 2 boyutlu dizimin parametrelerini g�nderdim. Yeni dizime d ismini verdim.
void mayinyerlestirme(char d[6][5])//Mayinlar� rastgele yerle�tirdi�im fonksiyon.
{	
	for(int i=0;i<6;i++)//6 sat�r�m oldu�undan 6 uzunlu�unda for d�ng�m� olu�turdum.
	{
		int rst=rand()%5;//rastgele de�erimi olu�turdum. 0-la 5 aras�. Bu sayede rastgele s�tunlara may�n yerle�tirebildim.
		
		for(int j=0;j<5;j++)//S�tunlar�ma ula�mam i�in i� i�e d�ng� ile 5 zunlupundaki s�tunlar�ma ula�t�m.
		{
			d[i][j]='T';//�ndislerime T harfini yazd�rd�m.
		}
		d[i][rst]='X';//rastgele de�eri tuttu�um rst de�i�kenini 2. k��eli parantezimin parametresi yaparak rastgele s�tunlara may�nlar�n terle�mesini sa�lad�m.
		//Bu sayede her sat�r�mda 1 adet may�n�n rastgele bir indise yerle�mesini sa�lad�m.
	}
		
}

void tekrarsorusu()//Kullan�c�ya tekrardan oynamak istedi�ini sordu�um fonksiyon.
{
		cout<<"YENIDEN OYNAMAK ISTER MISINIZ? (Evet icin e/E, Hayir icin h/H giriniz)"<<endl;//Oyunun sonuna geld�imde kullan�c�ya soru sordurdum.
		cin>>secim;	// secim de�i�keni ile goto fonksiyonunu if else ile kontrol ettirdim.		
}

