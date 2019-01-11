#include <iostream>
#include <conio.h>
#include <cmath>
#include <stdio.h>
#include <cstdlib>

#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

using namespace std;

bool czy_string_jest_liczba(char arg[]);
bool sprawdz_arg2(char arg[]);
int **stworz_pelna_talie();
void tasuj_talie(unsigned int seed, int **talia);
bool runda(int Talia1[][2],int Talia2[][2], int &kart1, int &kart2, int grajaca_karta);
void wyswietl_karte(int Talia[][2], int karta);
void rozdziel_talie(int **Talia,int Talia1[][2], int Talia2[][2], int kart);
void graj(int MaxRund, int *Talia[], int kart);
void uzup_talie_zerami(int Talia1[][2],int Talia2[][2], int kart);
void wypisz_karty_gracza(int Talia[][2], int kart, int gracz);
void wez_karte( int Talia1[][2], int &kart1, int Talia2[][2], int &kart2, int kto_bierze);
bool remis_wojna(int Talia1[][2], int &kart1, int Talia2[][2], int &kart2, int grajaca_karta);
int policz_karty(char *arg);
void karty_do_tablicy(int **Talia, int kart, char arg[]);
int **stworz_tablice(int kart);

int main (int argc, char *argv[]) {

	if (!(argc==3))
	{
		cout<<"Nalezy podac ilosc rund i karty lub rand_seed jako argument.";
		return EXIT_FAILURE;
	}

	int max_rund=0;
	if (czy_string_jest_liczba(argv[1]))
	{
		sscanf(argv[1],"%d",&max_rund);
	}
	if (!max_rund)
	{
		cout<<"Ilosc rund powinna byc dodatnia liczba calkowita.";
 		return EXIT_FAILURE;
 	}

 	if (czy_string_jest_liczba(argv[2]))
 	{
		unsigned int random_seed;
		sscanf(argv[2],"%u",&random_seed);
		int **Talia=stworz_pelna_talie();
		int kart=52;
		tasuj_talie(random_seed,Talia);
		graj(max_rund,Talia,kart);
	}
 	else if (sprawdz_arg2(argv[2]))
 	{
 		int kart=policz_karty(argv[2]);
 		int **Talia=stworz_tablice(kart);
 		karty_do_tablicy(Talia,kart,argv[2]);
 		graj(max_rund,Talia,kart);
 	}
 	else return EXIT_FAILURE;

	return EXIT_SUCCESS;
}

void graj(int MaxRund, int *Talia[], int kart)
{
	int Talia1[kart][2];
	int Talia2[kart][2];
	uzup_talie_zerami(Talia1,Talia2,kart);
	rozdziel_talie(Talia,Talia1,Talia2,kart);
	int nr_rundy=1, kart1=kart/2, kart2=kart/2;
	bool koniec=0;
	while (nr_rundy<=MaxRund && !koniec)
	{
		cout<<"Runda: "<<nr_rundy<<"\n";
		koniec=runda(Talia1,Talia2,kart1,kart2,0);
		nr_rundy++;
	}
	if (koniec)
	{
		if (kart1==kart2)
		{
			cout<<"\nRemis. Obu graczom braklo kart by brac udzial w wojnie.";
		}
		else if(kart1==1 || (kart1==2 && kart2>2))
		{
			cout<<"\nGracz 1 przegral: mial za malo kart by brac udzial w wojnie.";
		}
		else if(kart2==1 || (kart2==2 && kart1>2))
		{
			cout<<"\nGracz 2 przegral: mial za malo kart by brac udzial w wojnie.";
		}
	}
	if (kart1==0 || kart2==0)
	{
		cout<<"Partie wygral: ";
		if (kart1)
		{
			cout<<"1";
		}
		else cout<<"2";
	}
	else if (nr_rundy>MaxRund)
	{
		cout<<"Partia zakonczona - osiagnieto maksymalna ilosc rund.";
	}
}

bool runda(int Talia1[][2],int Talia2[][2], int &kart1, int &kart2, int grajaca_karta)
{
	wyswietl_karte(Talia1,grajaca_karta);
	cout<<" / ";
	wyswietl_karte(Talia2,grajaca_karta);
	if (Talia1[grajaca_karta][0]>Talia2[grajaca_karta][0])
	{
		cout<<"     Karty bierze gracz: 1"<<endl;
		for(int i=0; i<grajaca_karta+1;i++)
		{
			wez_karte(Talia1,kart1,Talia2,kart2,1);
		}
		wypisz_karty_gracza(Talia1,kart1,1);
		wypisz_karty_gracza(Talia2,kart2,2);
	}
	else if (Talia1[grajaca_karta][0]<Talia2[grajaca_karta][0])
	{
		cout<<"     Karty bierze gracz: 2"<<endl;
		for(int i=0; i<grajaca_karta+1;i++)
		{
			wez_karte(Talia1,kart1,Talia2,kart2,2);
		}
		wypisz_karty_gracza(Talia1,kart1,1);
		wypisz_karty_gracza(Talia2,kart2,2);
	}
	else
	{
		bool koniec=remis_wojna(Talia1,kart1,Talia2,kart2,grajaca_karta+2);
		if (koniec)
		{
			return 1;
		}
	}

	if (kart1==0 || kart2==0)
	{
		return 1;
	}
	return 0;
}

bool remis_wojna(int Talia1[][2], int &kart1, int Talia2[][2], int &kart2, int grajaca_karta)
{
	cout<<"     Wojna:\t";
	bool koniec=1;
	if (kart1>grajaca_karta-1 && kart2>grajaca_karta-1)
	{
		cout<<"[";
		wyswietl_karte(Talia1,grajaca_karta-1);
		cout<<" / ";
		wyswietl_karte(Talia2,grajaca_karta-1);
		cout<<"] ";
		if (kart1>grajaca_karta && kart2>grajaca_karta)
		{
			koniec=runda(Talia1,Talia2,kart1,kart2,grajaca_karta);
		}
	}
	return koniec;

}

void karty_do_tablicy(int **Talia, int kart, char arg[])
{
	for (int i=0; i<kart; i++)
	{
		switch (arg[2*i])
		{
			case '0': Talia[i][0]=10;
				break;
			case 'W': Talia[i][0]=11;
				break;
			case 'D': Talia[i][0]=12;
				break;
			case 'K': Talia[i][0]=13;
				break;
			case 'A': Talia[i][0]=14;
				break;
			default: Talia[i][0]=arg[2*i]-'0';
		}
		switch (arg[2*i+1])
		{
			case 'K': Talia[i][1]=0;
				break;
			case 'k': Talia[i][1]=1;
				break;
			case 'T': Talia[i][1]=2;
				break;
			case 'P': Talia[i][1]=3;
				break;
		}
	}
}

int policz_karty(char *arg)
{
	int licznik=0;
	while (arg[licznik]) licznik++;
	return licznik/2;
}

int **stworz_tablice(int kart)
{
	int **tab;
	tab=new int*[kart];
	for (int i=0; i<kart; i++)
	{
		tab[i]=new int[2];
	}
	return tab;
}

void wypisz_karty_gracza(int Talia[][2], int kart, int gracz)
{
	cout<<"Karty "<<gracz<<" ["<<kart<<"]: ";
	if (kart)
	{
		for (int i=0; i<kart; i++)
		{
			wyswietl_karte(Talia,i);
			cout<<" ";
		}
	}
	cout<<endl;
}

void wez_karte( int Talia1[][2], int &kart1, int Talia2[][2], int &kart2, int kto_bierze)
{
	if (kto_bierze==1)
	{
		Talia1[kart1+1][0]=Talia2[0][0];
		Talia1[kart1+1][1]=Talia2[0][1];
		Talia1[kart1][0]=Talia1[0][0];
		Talia1[kart1][1]=Talia1[0][1];
		kart1++;
		kart2--;
	}
	else
	{
		Talia2[kart2+1][0]=Talia2[0][0];
		Talia2[kart2+1][1]=Talia2[0][1];
		Talia2[kart2][0]=Talia1[0][0];
		Talia2[kart2][1]=Talia1[0][1];
		kart2++;	
		kart1--;
	}
		for (int i=0; i<kart1; i++)
		{
			Talia1[i][0]=Talia1[i+1][0];
			Talia1[i][1]=Talia1[i+1][1];
		}
		Talia1[kart1][0]=0;
		Talia1[kart1][1]=0;

		for (int i=0; i<kart2; i++)
		{
			Talia2[i][0]=Talia2[i+1][0];
			Talia2[i][1]=Talia2[i+1][1];
		}
		Talia2[kart2][0]=0;
		Talia2[kart2][1]=0;
}
void wyswietl_karte(int Talia[][2], int karta)
{
	switch (Talia[karta][0])
	{
		case 11: cout<<"W";
			break;
		case 12: cout<<"D";
			break;
		case 13: cout<<"K";
			break;
		case 14: cout<<"A";
			break;
		default:
			cout<<Talia[karta][0];
	}
	switch (Talia[karta][1])
	{
		case 0: cout<<" kier";
			break;
		case 1: cout<<" karo";
			break;
		case 2: cout<<" trefl";
			break;
		case 3: cout<<" pik";
	}
}
void rozdziel_talie(int **Talia,int Talia1[][2], int Talia2[][2], int kart)
{
	for (int i=0; i<kart/2; i++)
	{
		Talia1[i][0]=Talia[2*i][0];
		Talia1[i][1]=Talia[2*i][1];
		Talia2[i][0]=Talia[2*i+1][0];
		Talia2[i][1]=Talia[2*i+1][1];
	}
}
void tasuj_talie(unsigned int seed, int **talia)
{
	srand(seed);
	int k1, k2, temp;
	for (int i=0; i<10000; i++)
	{
		k1=rand()%52;
		k2=rand()%52;
		temp=talia[k1][0];
		talia[k1][0]=talia[k2][0];
		talia[k2][0]=temp;
		temp=talia[k1][1];
		talia[k1][1]=talia[k2][1];
		talia[k2][1]=temp;
	}
}

int **stworz_pelna_talie()
 {
 	int **tab;
 	tab=new int*[52];
 	for (int i=0; i<52; i++)
 	{
 		tab[i]=new int[2];
 	}
 	for (int j=0; j<4; j++)
	{
		for (int i=0; i<13;i++)
		{
			tab[i+13*j][0]=i+2;
			tab[i+13*j][1]=j;
		}
	}
	return tab;
 }

 bool sprawdz_arg2(char arg[])
 {
 	int licznik=0;
	while (arg[licznik]) licznik++;
	if (licznik%4!=0)
	{
		cout<<"Ilosc kart powinna byc parzysta.";
		return 0;
	}
	bool flaga=0;
	for (int i=0; i<licznik; i++)
	{
		if ((i%2==0) && !((arg[i]>='2' && arg[i]<='9') || arg[i]=='0' || arg[i]=='W' || arg[i]=='D' || arg[i]=='K' || arg[i]=='A'))
		{
			cout<<"Niepoprawna lista kart: "<<arg<<" ("<<arg[i]<<arg[i+1]<<")";
			return 0;
		}
		if ((i%2!=0) && !(arg[i]=='K' || arg[i]=='k' || arg[i]=='T' || arg[i]=='P'))
		{
			cout<<"Niepoprawna lista kart: "<<arg<<" ("<<arg[i-1]<<arg[i]<<")";
			return 0;
		}
	}
	return 1;
 }

 unsigned int przelicz_string_na_liczbe (char arg[])
 {
	int licznik=0;
	while (arg[licznik]) licznik++;
	licznik--;
	int wynik=0, mnoznik=1;
	for (licznik; licznik>=0; licznik--)
	{
		wynik+=mnoznik*(arg[licznik]-'0');
		mnoznik*=10;
	}
	return wynik;
 }

 bool czy_string_jest_liczba(char arg[])
 {
 	int licznik=0;
	while (arg[licznik]) licznik++;
	int i=0;
 	while (arg[i]>='0' && arg[i]<='9' && i<licznik) i++;
 	if (i==licznik) return 1;
 	else return 0;
 }
void uzup_talie_zerami(int Talia1[][2],int Talia2[][2], int kart)
{
	for (int i=0; i<kart; i++)
	{
		Talia1[i][0]=0;
		Talia1[i][1]=0;
		Talia2[i][0]=0;
		Talia2[i][0]=0;
	}
}
