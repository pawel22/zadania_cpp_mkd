#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	int user_number,q0=0,q1=0,q2=0,q3=0,q4=0,x=1,last=0,a,change[15],b=0,lng;
	

string state [3][5]={{"1 q1 L","1, q3, L","0, q4, L","0, q3, L","1, q3, L"},
					{"0, q2, L","0, q4, L","1, q4, L","1, q3, L","0, q4, L"},
					{"1, q1, L","1, q3, -","0, q4, L","-, q3, -","1, q3, -"}};
					

cout<<"Ile znakow bedzie miala twoja liczba"<<endl;
cin>>lng;
//cout<<state[0][1];

//cout<<"Podaj liczbe w systemie binarnym:  ";
//cin>>user_number;

 cout << "Podaj jakas liczbe binarna... \n";
    char tab[lng];
    scanf("%s", tab); //wczytywanie pojedynczych znaków do tablicy liczb
    
    //tab[5]=5;

cout<<"Przeszliœmy kolejno przez : "<<endl;
    
     for(int i = 0;i<lng;i++){
        tab[i]= tab[i] - 48;

	 }



for(int i=lng-1; i>=0; i--){
	a=i;
	
 	 if(tab[i]==0)
	  {

	  		if(x==1){
	  			cout<<"0, q0, "<<state[0][0]<<endl;
	  			q1=1;
	  			q2=0,q3=0,q4=0;
	  			x=0;
	  			change[i]=1;
			  }
	  		else if(q1==1){
	  			cout<<"0, q1, "<<state[0][1]<<endl;
	  			q2=0,q1=0,q4=0;
	  			q3=1;
	  			last=1;
	  			change[i]=1;
		  }
		  else if(q3==1){
		  	cout<<"0, q3, "<<state[0][3]<<endl;
		  	q1,q2,q4=0;
		  	last=3;
		  	change[i]=0;
		  }
		  	else if(q2==1){
		  	cout<<"0, q2, "<<state[0][2]<<endl;
		  	q1=0,q2=0,q3=0;
		  	q4=1;
		  	last=2;
		  	change[i]=0;
		  }
		   	else if(q4==1){
		  	cout<<"0, q4, "<<state[0][4]<<endl;
		  	q1=0,q2=0,q4=0;
		  	q3=1;
		  	last=4;
		  	change[i]=1;
		  }
		  //continue;
}
if(tab[i]==1)
{
		  	if(x==1){
	  			cout<<"1, q0, "<<state[1][0]<<endl;
	  			q2=1;
	  			q1=0,q3=0,q4=0;
	  			x=0;
	  			change[i]=0;
	  			
			  }
			  else if(q2==1){
	  			cout<<"1, q2, "<<state[1][2]<<endl;
	  			q2=0,q3=0,q1=0;
	  			q4=1;
	  			last=2;
	  			change[i]=1;
		  }
		  	  else if(q1==1){
	  			cout<<"1, q1, "<<state[1][1]<<endl;
	  			q1=0,q2=0,q3=0;
	  			q4=1;
	  			last=1;
	  			change[i]=0;
		  }
		  	  else if(q3==1){
	  			cout<<"1, q3, "<<state[1][3]<<endl;
	  			q2=0,q1=0,q4=0;
	  			q3=1;
	  			last=3;
	  			change[i]=1;

		  }
		  	  else if(q4==1){
	  			cout<<"1, q4, "<<state[1][4]<<endl;
	  			q2=0,q3=0,q1=0;
	  			q4=1;
	  			last=4;
	  			change[i]=1;
		  }
		//continue;
	  }
	  
	  
	  	if(last==1 & a==0){
	  		
	  		cout<<"@, q1, 1, q3, -"<<endl;
	  		change[i+1]=1;
	  		
		  }
		  else if(last==2 & a==0){
		  
		  	cout<<"@, q2, 0, q4, L"<<endl;
		  	change[i+1]=0;
		  }
		  else if(last==3 & a==0){
		  		cout<<"@, q3, -, q3, -"<<endl;
		  	change[i+1]=0;
		  }
		   else if(last==4 & a==0){
		  		cout<<"@, q4, 1, q3, -"<<endl;
		 	 	change[i+1]=1;
		  }	
}

/*
cout<<"Liczba po zamianie to: ";
for(int i=0; i<=b; i++){
cout<<change[i];
}
*/
	return 0;
		
}


