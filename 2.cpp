
/*
..Uygulama ile Ýlgili Genel Açýklamalar..

AD SOYAD: FURKAN AYDIN
ÖÐRENCÝ NO: 180757046
BÖLÜM: BÝLGÝSAYAR MÜHENDÝSLÝÐÝ
DERSÝN ADI: NESNEYE YÖNELÝK PROGRAMLAMA
AKADEMÝK DÖNEM: 4
PROJE NO:1
ÖÐRETÝM ÜYESÝ ADI: GÜLÞAH
*/

#include<iostream>
#include<cstdlib> 
#include<ctime> 

using namespace std;

string secim;//secim deðiþkenimi global olarak tanýmladým.

//  fonksiyonlarýn protitiplerini oluþturdum.
void mayinyerlestirme(char d[6][5]);
void matrisibasma(char d[6][5]);
void tekrarsorusu();

int main()
{	
	srand(time(NULL));//Rastgele gelen deðeri her seferinde farklý bir deðer almasýný saðlamasý için tanýmladým.
	int satir;//kullanýcýnýn girdiði satir deðerini tuttuðum deðiþken
	char oyunMat[6][5]; //6 satir 5 sütünluk matrisi oluþturdum
	
	tekrar:// Kullanýcý soruya evet dediðinde goto fonksiyonu ile tekrardan programý baþtan baþlattým.
		
	mayinyerlestirme(oyunMat);// Matrisi ve içine rastgele mayinlarý koyduðum fonksiyonu programýn baþýnda çaðýrdým.


	//kullanýcýdan alacaðým 6 adet satýr bilgisi ve verdiði satýr bilgilerinin mayýnla(X)'le kesisip kesiþmediðini kontrol ettirdiðim bloktur. X le kesitiðinde
	//Patlayan indise "P" yazdýrdým.
	for(int i=1;i<7;i++)
	{
	tekrar2:		
	cout<<"1-5 Arasi Deger Giriniz: ";//Kullanýcýdan 6 adet satýr indisi girmesini istedim.
	cin>>satir;//satir bilgisini satir adlý deðiþkende tuttum.
	cout<<endl;
	if(satir>5)
	{
		cout<<"5'ten buyuk bir deger girdiniz..."<<endl;
		goto tekrar2;
	}
	
		//OyunMat matrisimin ilk köþeli parantezi satýrý 2. köþeli parantezi ise sütünu temsil ettiðinden kullanýcýdan aldýðým satir deðiþkeni ile
		//o andaki indiste mayýn olup olmadýðýný kontrol ettirdim.
		if(oyunMat[i-1][satir-1]=='X')
		{			
		oyunMat[i-1][satir-1]='P';// satir deðiþkeni mayýnla kesiþtiði için o indise P yazdýrdým.
		cout<<"Mayin Patladi. Uzgunum Maalesef Kaybettiniz!"<<endl;// Mayýna basýldýðý için ekrana bilgi mesajý verdim.
		cout<<endl;
		matrisibasma(oyunMat);//oyunun sonunda kullanýcýnýn yolunu ve patlayan mayýný matris halinde ekrana bastýrdým.
		cout<<endl;
		tekrarsorusu();//kullanýcýya tekrar oynayýp oynamak istemediði sorusunu soran fonksiyonu çaðýrdým.
		
			if(secim=="E"|| secim=="e")//Evet e bastýðý taktirde goto fonksiyonu ile programý tekrardan baþlattým.
			{		
					
				goto tekrar;
								
			}
			else if(secim=="H"|| secim=="h")//Hayýr seçeneðini seçtiði taktirde programý sonlandýrdým.
			{	
					
   				exit(0);	
		   	
			}
		}
		
	oyunMat[i-1][satir-1]='O';//Mayýna basmadýðýysa o andaki indise kullanýcýnýn yolu olan 'O' harfini yazdým.
	
			if(i<6)
			{
	cout<<i+1<<". Satira Gectiniz"<<endl;//kaçýncý satýrda olduðunu i sayacý yardýmýyla kullanýcýya verdim.	
	
			}
	
	cout<<endl;
	
	}
	
	//Bu bloðumda kazanma durumunu oluþturdum. Son satýrýmýn tüm sutunlarýnda patlayan mayýn yoksa kazandýðýný belirttim.
	if(oyunMat[5][0]!= 'P' && oyunMat[5][1]!= 'P' && oyunMat[5][2]!= 'P' && oyunMat[5][3]!= 'P' && oyunMat[5][4]!= 'P')	
	{
		cout<<"Tebrikler Kazandiniz!"<<endl;
		cout<<endl;
		matrisibasma(oyunMat);//Matrisi bastýran fonksiyonumu çaðýrdým.
		cout<<endl;
		tekrarsorusu();//Tekrar oynayýp oynamayacaðýný sorguladým.
		if(secim=="E"|| secim=="e")//Evet e bastýðý taktirde goto fonksiyonu ile programý tekrardan baþlattým.
			{		
					
				goto tekrar;
								
			}
			else if(secim=="H"|| secim=="h")//Hayýr seçeneðini seçtiði taktirde programý sonlandýrdým.
			{	
					
   				exit(0);	
		   	
			}
	}
	   	
}
//Bu fonksiyona oyunMat isimli 2 boyutlu dizimin parametrelerini gönderdim. Yeni dizime d ismini verdim.
void matrisibasma(char d[6][5]) // Matrisi bastýrdýðým fonksiyon.
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

//Bu fonksiyona oyunMat isimli 2 boyutlu dizimin parametrelerini gönderdim. Yeni dizime d ismini verdim.
void mayinyerlestirme(char d[6][5])//Mayinlarý rastgele yerleþtirdiðim fonksiyon.
{	
	for(int i=0;i<6;i++)//6 satýrým olduðundan 6 uzunluðunda for döngümü oluþturdum.
	{
		int rst=rand()%5;//rastgele deðerimi oluþturdum. 0-la 5 arasý. Bu sayede rastgele sütunlara mayýn yerleþtirebildim.
		
		for(int j=0;j<5;j++)//Sütunlarýma ulaþmam için iç içe döngü ile 5 zunlupundaki sütunlarýma ulaþtým.
		{
			d[i][j]='T';//Ýndislerime T harfini yazdýrdým.
		}
		d[i][rst]='X';//rastgele deðeri tuttuðum rst deðiþkenini 2. köþeli parantezimin parametresi yaparak rastgele sütunlara mayýnlarýn terleþmesini saðladým.
		//Bu sayede her satýrýmda 1 adet mayýnýn rastgele bir indise yerleþmesini saðladým.
	}
		
}

void tekrarsorusu()//Kullanýcýya tekrardan oynamak istediðini sorduðum fonksiyon.
{
		cout<<"YENIDEN OYNAMAK ISTER MISINIZ? (Evet icin e/E, Hayir icin h/H giriniz)"<<endl;//Oyunun sonuna geldðimde kullanýcýya soru sordurdum.
		cin>>secim;	// secim deðiþkeni ile goto fonksiyonunu if else ile kontrol ettirdim.		
}

