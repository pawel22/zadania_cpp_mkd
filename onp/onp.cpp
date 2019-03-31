// Odwrotna notacja polska by PN

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std; 

int main()
{
	int j=0,lng=0,Operator=0,h,przypisanie=0,g=0,nawias_kon=0,error=1,repeat=0;
	int first=1;
	char stos[30];
	float obliczenia;
	char stos_naw[10];
	cout<<"Wpisz znaki: "<<endl;
	char znaki[30];
	scanf("%s", znaki);
	float znaki_i[30];
	 
	while(znaki[j]!=0){
		j++;
		lng++;
	} 
	
	for(int i=0;i<lng; i++){
		znaki_i[i]=znaki[i]-48;
		//cout<<znaki_i[i];
	}
	 //cout<<znaki_i[2]*znaki_i[3];
	for(int i=0; i<lng; i++){
	
		if(znaki[i]>47 && znaki[i]<58)
		{
			cout<<znaki_i[i];
		}
		else
		{
		
		switch(znaki[i]){
			case 40:
			if(repeat==1){
				error=0;
				h=g;
				break;
			}
			else{
			repeat=1;
			h=g;	
			break;
			}
			
			case 41:
				if(nawias_kon==1 && error==0){
					for(int i=0; i<=g; i++){
					cout<<stos[i];
				}
				return 0;
				}
				else if(nawias_kon==1 && error==1){
					cout<<endl;
					system ("cls");
				cout<<"Wpisano bledny ciag";
				return 0;
				}	
				else{
			for(int i=1; i<=g; i++){
			cout<<stos[i];
				}
			for(int i=1; i<=g; i++){
			stos[i]=0;
				}
			g=0;
			Operator=0;
			nawias_kon=1;
			break;
				}

			case 42:
			if(Operator==1){
				if(first==1){
					cout<<stos[g-1];
					stos[g]=znaki[i];
					first=0;
				}
				else{
				cout<<stos[g];
				stos[g]=znaki[i];
				}	
			}
			else{
			stos[g]=znaki[i];
			g++;
			Operator=1;
			}
			break;
			case 43:
				if(Operator==1){
				if(first==1){
					cout<<stos[g-1];
					stos[g]=znaki[i];
					first=0;
				}
				else{
				cout<<stos[g];
				stos[g]=znaki[i];
				}	
			}
			else{
			stos[g]=znaki[i];
			g++;
			Operator=1;
			}
			break;
			case 45:
			if(Operator==1){
				if(first==1){
					cout<<stos[g-1];
					stos[g]=znaki[i];
					first=0;
				}
				else{
				cout<<stos[g];
				stos[g]=znaki[i];
				}	
			}
			else{
			stos[g]=znaki[i];
			g++;
			Operator=1;
			}
			break;
			case 47:
				if(Operator==1){
				if(first==1){
					cout<<stos[g-1];
					stos[g]=znaki[i];
					first=0;
				}
				else{
				cout<<stos[g];
				stos[g]=znaki[i];
				}	
			}
			else{
			stos[g]=znaki[i];
			g++;
			Operator=1;
			}
			break;
				case 94:
				if(Operator==1){
				if(first==1){
					cout<<stos[g-1];
					stos[g]=znaki[i];
					first=0;
				}
				else{
				cout<<stos[g];
				stos[g]=znaki[i];
				}	
			}
			else{
			stos[g]=znaki[i];
			g++;
			Operator=1;
			}
			break;
		}
	}
}
	 		for(int i=1; i<=g; i++){
			cout<<stos[i];
				}
	
	return 0;
}
