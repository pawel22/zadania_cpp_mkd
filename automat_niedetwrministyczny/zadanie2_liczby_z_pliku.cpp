#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
int main()
{
    int i=0,c,zliczanie=3,g=0,pomocniczy=0,h=0,stanyp=0;
    fstream liczby,dl;
    string b,dlugosc;
    char tab[40];
    string stany[40];
    string dodatek[40];
    
 liczby.open(("E:/ZADANIE2/ciag.txt"), ios::in);
 dl.open(("E:/ZADANIE2/ciag.txt"), ios::in);
 getline(dl,dlugosc);
 c= dlugosc.length()/2+1;//ilosc znakow
 dl.close();
 while(!(liczby.eof()))
 {
  	liczby >>tab[i];
 	b=tab[i]; 
 	i++;	
 }
 	liczby.close();

for(int j=0; j<c;j++){
   	if(tab[j]==35)
	{
		cout<<"                   Rozpoczynamy nowy ciag"<<endl;
		for(int i=0; i<40; i++)		{
			stany[i]="";
			zliczanie =3;
			pomocniczy=0;
			stanyp=0;
		}
	}
	else if(tab[j]==48)
	{
		if(stanyp==1)		{
			stany[j]="q1 q0 q6 ";
		}
		else		{
			stany[j]="q1 q0 ";
		}		
		cout<<"Jestesmy w stanie "<<stany[j]<<""<<endl;
		if(tab[j+1]==48 & zliczanie == 3)		{
			zliczanie=1;
		}			
	}
	else if(tab[j]==49)	{		
				if(stanyp==1)		{
			stany[j]="q2 q0 q6 ";
		}
		else		{
			stany[j]="q2 q0 ";
		}
			cout<<"Jestesmy w stanie "<<stany[j]<<""<<endl;
	if(tab[j+1]==49 & zliczanie == 3)		{
			zliczanie=1;			
		}		
	}
	else if(tab[j]==50)	{		
			if(stanyp==1)		{
			stany[j]="q3 q0 q6 ";
		}
		else		{
			stany[j]="q3 q0 ";
		}
			cout<<"Jestesmy w stanie "<<stany[j]<<""<<endl;
	if(tab[j+1]==50 & zliczanie == 3)		{
			zliczanie=1;
		}		
	}
	else if(tab[j]==51)	{
				if(stanyp==1)		{
			stany[j]="q4 q0 q6 ";
		}
		else		{
			stany[j]="q4 q0 ";
		}
			cout<<"Jestesmy w stanie "<<stany[j]<<""<<endl;
			if(tab[j+1]==51 & zliczanie == 3)		{
			zliczanie=1;
			
		}		
	}
	else if(tab[j]==52)	{
				if(stanyp==1)		{
			stany[j]="q5 q0 q6 ";
		}
		else		{
			stany[j]="q5 q0 ";
		}
		cout<<"Jestesmy w stanie "<<stany[j]<<""<<endl;
			if(tab[j+1]==52 & zliczanie == 3)	{
			zliczanie=1;
			
		}			
	}
	else	{
		cout<<"Liczba jest spoza zakresu"<<endl;		
	}			
	if(zliczanie==2)	{		
		for(int k=0; k<=j; k++)		{			
			pomocniczy=1;
			zliczanie=4;
			h=j;			
		}
	}
	if(zliczanie==1)	{
		zliczanie=2;
		stanyp=1;
	}		
	if(pomocniczy==1)	{
		cout<<"Przeszlismy przez stany: q0 ";
		for(int k=0; k<=j; k++)	{
			cout<<stany[k];			
		}
		
		cout<<endl;	
	}
}
    return 0;
}
