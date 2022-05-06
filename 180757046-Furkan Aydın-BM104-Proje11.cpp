#include<iostream>
#include<cstdlib> 
#include<ctime> 

using namespace std;
string secim;
void mayinyerlestirme(char d[6][5]);
void matrisibasma(char d[6][5]);

int main()
{	
	srand(time(NULL));
	int satir;
	char oyunMat[6][5]; 
	
	tekrar:
		
	cout<<endl;
	mayinyerlestirme(oyunMat);
	matrisibasma(oyunMat);
	
cout<<endl;
cout<<endl;
cout<<endl;

	for(int i=1;i<7;i++)
	{
		
	cout<<"1-5 Arasi Deger Giriniz: ";
	cin>>satir;
	cout<<endl;
	
		if(oyunMat[i-1][satir-1]=='X')
		{			
		oyunMat[i-1][satir-1]='P';
		cout<<"Mayin Patladi. Uzgünum Maalesef Kaybettiniz!"<<endl;
		matrisibasma(oyunMat);
		cout<<"YENIDEN OYNAMAK ISTER MISINIZ? (Evet icin e/E, Hayir icin h/H giriniz)"<<endl;
		cin>>secim;
		
		if(secim=="E"|| secim=="e")
			{
				
			goto tekrar;
			
			}
		else if(secim=="H"|| secim=="h")
			{	
					
   		exit(0);	
		   	
			}
		
		}
		
	
	oyunMat[i-1][satir-1]='O';
	cout<<i+1<<". Satira Gectiniz"<<endl;	
	cout<<endl;
	
	}	
}
	void matrisibasma(char d[6][5])
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

void mayinyerlestirme(char d[6][5])
{	
	for(int i=0;i<6;i++)
	{
		int rst=rand()%5;
		
		for(int j=0;j<5;j++)
		{
			d[i][j]='T';
		}
		d[i][rst]='X';
	}	
}

	
	
	

