#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	int user_number,q0=0,q1=0,q2=0,q3=0,q4=0,x=1;

string state [3][5]={{"1 q1 L","1, q3, L","0, q4, L","0, q3, L","1, q3, L"},
					{"0, q2, L","0, q4, L","1, q4, L","1, q3, L","0, q4, L"},
					{"1, q1, L","1, q3, -","0, q4, L","-, q3, -","1, q3, -"}};
					

//cout<<state[0][1];

//cout<<"Podaj liczbe w systemie binarnym:  ";
//cin>>user_number;

 cout << "Podaj jak¹œ liczbê (o d³ugoœci 5 cyfr)... \n";
    char tab[4];
    scanf("%s", tab); //wczytywanie pojedynczych znaków do tablicy liczb
    
    //tab[5]=5;
    
     for(int i = 0;i<5;i++)
        tab[i]= tab[i] - 48;

 	 if(tab[1]==0)
	  {
	  	
	  		if(x==1){
	  			cout<<state[0][0]<<endl;
	  			q1=1;
	  			q2,q3,q4=0;
	  			x=0;
			  }
	  		else if(q1==1){
	  			cout<<state[0][1]<<endl;
	  			q2,q1,q4=0;
	  			q3=1;
		  }
		  else if(q3==1){
		  	cout<<state[0][3]<<endl;
		  	q1,q2,q4=0;
		  	
		  }
		  	else if(q2==1){
		  	cout<<state[0][2]<<endl;
		  	q1,q2,q0=0;
		  	q4=1;
		  }
		   	else if(q4==1){
		  	cout<<state[0][4]<<endl;
		  	q1,q2,q4=0;
		  	q3=1;
		  }
}
if(tab[1]==1)
{
		  	if(x==1){
	  			cout<<state[1][0]<<endl;
	  			q2=1;
	  			q1,q2,q3,q4=0;
	  			x=0;
	  			
			  }
			  else if(q2==1){
	  			cout<<state[1][2]<<endl;
	  			q2,q3,q4=0;
	  			q4=1;
	  		
		  }
		  	  else if(q1==1){
	  			cout<<state[1][1]<<endl;
	  			q1,q2,q3=0;
	  			q4=1;
		  }
		  	  else if(q3==1){
	  			cout<<state[1][3]<<endl;
	  			q2,q1,q4=0;
	  			q3=1;

		  }
		  	  else if(q4==1){
	  			cout<<state[1][2]<<endl;
	  			q2,q3,q4=0;
	  			q1=1;
	  		
		  }
		
	  }
	   
	return 0;
		
}


