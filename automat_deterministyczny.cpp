#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
    int q0,q1,q2,q3,q4,q5,q6,moneta,zliczanie,suma;
    int tab_monety [10];
    string tab_stany [10];
cout<<"Automat z herbata"<<endl;
    cout << "Wrzuc monete: ";
	cin>>moneta;

while(moneta != 2 & moneta != 1 & moneta !=5) 
	{
	cout <<"Wrzuciles bledna monete, wrzuc ponownie"<<"\n";
	cout << "Wrzuc monete: ";
	cin>>moneta;
    }  
suma=moneta	;
	switch(moneta)
{
	case 1:
		tab_monety[0]=moneta;
		tab_stany[0]="q1";
		cout<<"Jestesmy w stanie "<<tab_stany[0]<<""<<endl;
		zliczanie = 1;
		break;
	case 2:
		tab_monety[0]=moneta;
		tab_stany[0]="q2";
		cout<<"Jestesmy w stanie "<<tab_stany[0]<<""<<endl;
		zliczanie = 2;
		break;
	case 5:
		tab_monety[0]=moneta;
		tab_stany[0]="q3";
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Wydaje herbatke"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<""<<endl;
		return 0;
		
}
cout<<"Wrzucono "<<suma<<""<<endl;
  cout << "Wrzuc monete: ";
	cin>>moneta;

while(moneta != 2 & moneta != 1 & moneta !=5) 
	{
	cout <<"Wrzuciles bledna monete, wrzuc ponownie"<<"\n";
	cout << "Wrzuc monete: ";
	cin>>moneta;
    }  
    suma=suma+moneta;
zliczanie=zliczanie+moneta;
	switch(zliczanie)
{
	case 2:
		zliczanie = 2;
		tab_monety[1]=moneta;
		tab_stany[1]="q2";
		cout<<"Jestesmy w stanie "<<tab_stany[1]<<""<<endl;
		break;
	case 3:
		zliczanie = 3;
		tab_monety[1]=moneta;
		tab_stany[1]="q5";
		cout<<"Jestesmy w stanie "<<tab_stany[1]<<""<<endl;
		break;
	case 4:
		zliczanie = 4;
		tab_monety[1]=moneta;
		tab_stany[1]="q4";
		cout<<"Jestesmy w stanie "<<tab_stany[1]<<""<<endl;
		break;
	case 6:
	case 7:
		tab_monety[1]=moneta;	
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Kwota za duza , zwracam pieniadze"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<",q6"<<endl;
		return 0;
		
}

cout<<"Wrzucono "<<suma<<""<<endl;
  cout << "Wrzuc monete: ";
	cin>>moneta;

while(moneta != 2 & moneta != 1 & moneta !=5) 
	{
	cout <<"Wrzuciles bledna monete, wrzuc ponownie"<<"\n";
	cout << "Wrzuc monete: ";
	cin>>moneta;
    }  
    suma=suma+moneta;
    zliczanie=zliczanie+moneta;
    
	switch(zliczanie)
{
	case 3:
		zliczanie=3;
		tab_monety[2]=moneta;
		tab_stany[2]="q5";
		cout<<"Jestesmy w stanie "<<tab_stany[2]<<""<<endl;
		break;
	case 4:
		zliczanie=4;
		tab_monety[2]=moneta;
		tab_stany[2]="q4";
		cout<<"Jestesmy w stanie "<<tab_stany[2]<<""<<endl;
		break;
	case 5:
		tab_monety[2]=moneta;
		tab_stany[2]="q3";
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Wydaje herbatke"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<","<<tab_stany[2]<<""<<endl;
		return 0;
	case 6:
	case 8:
	case 7:
	case 9:
		tab_monety[2]=moneta;	
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Kwota za duza , zwracam pieniadze"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<",q6"<<endl;
		return 0;
}
cout<<"Wrzucono "<<suma<<""<<endl;
  cout << "Wrzuc monete: ";
	cin>>moneta;

while(moneta != 2 & moneta != 1 & moneta !=5) 
	{
		cout <<"Wrzuciles bledna monete, wrzuc ponownie"<<"\n";
		cout << "Wrzuc monete: ";
		cin>>moneta;
    }  
    suma=suma+moneta;
	zliczanie=zliczanie+moneta;

	switch(zliczanie)
{
	case 4: 
		zliczanie = 4;
		tab_monety[3]=moneta;
		tab_stany[3]="q4";
		cout<<"Jestesmy w stanie "<<tab_stany[3]<<""<<endl;
		break;
	case 5: 
		tab_monety[3]=moneta;
		tab_stany[3]="q3";
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Wydaje herbatke"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<","<<tab_monety[3]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<","<<tab_stany[2]<<","<<tab_stany[3]<<""<<endl;
		return 0;
	case 6:
	case 8:
	case 9:
		tab_monety[3]=moneta;
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Kwota za duza , zwracam pieniadze"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<","<<tab_monety[3]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<","<<tab_stany[2]<<",q6"<<endl;
		return 0;
		
}	
cout<<"Wrzucono "<<suma<<""<<endl;
cout << "Wrzuc monete: ";
	cin>>moneta;

while(moneta != 2 & moneta != 1 & moneta !=5) 
	{
		cout<<"Wrzucono "<<suma<<""<<endl;
	cout <<"Wrzuciles bledna monete, wrzuc ponownie"<<"\n";
	cout << "Wrzuc monete: ";
	cin>>moneta;
    }  
zliczanie=zliczanie+moneta;
	
	switch(zliczanie)
{

	case 5: 
		tab_monety[4]=moneta;
		tab_stany[4]="q3";
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Wydaje herbatke"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<","<<tab_monety[3]<<","<<tab_monety[4]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<","<<tab_stany[2]<<","<<tab_stany[3]<<","<<tab_stany[4]<<""<<endl;
		break;
	case 6:
	case 9:
		tab_monety[4]=moneta;
		cout<<"Wrzucono "<<suma<<""<<endl;
		cout<<"Kwota za duza , zwracam pieniadze"<<endl;
		cout<<"wrzucono monety: "<<tab_monety[0]<<","<<tab_monety[1]<<","<<tab_monety[2]<<","<<tab_monety[3]<<","<<tab_monety[4]<<""<<endl;
		cout<<"Przeszlismy przez stany: q0,"<<tab_stany[0]<<","<<tab_stany[1]<<","<<tab_stany[2]<<","<<tab_stany[3]<<",q6"<<endl;
		return 0;
		
}	
	
	return 0;
		
}


