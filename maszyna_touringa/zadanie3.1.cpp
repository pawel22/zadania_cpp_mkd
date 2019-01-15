#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	int user_number,q0=0,q1=0,q2=0,q3=0,q4=0,x=1,last=0,a,change[15],b=0,f=0,d=0;
	int koncowa[10];
	

string state [3][5]={{"1 q1 L","1, q3, L","0, q4, L","0, q3, L","1, q3, L"},
					{"0, q2, L","0, q4, L","1, q4, L","1, q3, L","0, q4, L"},
					{"1, q1, L","1, q3, -","0, q4, L","-, q3, -","1, q3, -"}};
					


//cout<<"Podaj liczbe w systemie binarnym:  ";
//cin>>user_number;

 cout << "Podaj jakas liczbe binarna... \n";
    char tab[10];
    scanf("%s", tab); //wczytywanie pojedynczych znaków do tablicy liczb
    
    //tab[5]=5;

cout<<"Przeszlismy kolejno przez : "<<endl;
    
     for(int i = 0;i<10;i++){
        tab[i]= tab[i] - 48;

	 }
	while( tab[d]==1 || tab[d]==0)
	{
		d++;
	}
	
	if(d==1)
	{
		if(tab[0]==0){
		
		cout<<"0, q0, "<<state[0][0]<<endl;
		cout<<"@, q1, "<<state[2][1]<<endl;
		cout<<"Liczba koncowa to:  "<<endl;
		cout<<"11";
		return 0;
		}
		else{
		cout<<"1, q0, "<<state[1][0]<<endl;
		cout<<"@, q1, "<<state[2][2]<<endl;
		cout<<"@, q3, "<<state[2][4]<<endl;
		cout<<"Liczba koncowa to:  "<<endl;
		cout<<"100";
		return 0;
		}
		
	}
for(int i=d-1; i>=0; i--){
	a=i;
	
 	 if(tab[i]==0)
	  {

	  		if(x==1){
	  			cout<<"0, q0, "<<state[0][0]<<endl;
	  			q1=1;
	  			q2=0,q3=0,q4=0;
	  			x=0;
	  			change[i]=1;
	  			koncowa[f]=1;
			  }
	  		else if(q1==1){
	  			cout<<"0, q1, "<<state[0][1]<<endl;
	  			q2=0,q1=0,q4=0;
	  			q3=1;
	  			last=1;
	  			change[i]=1;
	  			koncowa[f]=1;
		  }
		  else if(q3==1){
		  	cout<<"0, q3, "<<state[0][3]<<endl;
		  	q1,q2,q4=0;
		  	last=3;
		  	change[i]=0;
		  	koncowa[f]=0;
		  }
		  	else if(q2==1){
		  	cout<<"0, q2, "<<state[0][2]<<endl;
		  	q1=0,q2=0,q3=0;
		  	q4=1;
		  	last=2;
		  	change[i]=0;
		  	koncowa[f]=0;
		  }
		   	else if(q4==1){
		  	cout<<"0, q4, "<<state[0][4]<<endl;
		  	q1=0,q2=0,q4=0;
		  	q3=1;
		  	last=4;
		  	change[i]=1;
		  	koncowa[f]=1;
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
	  			koncowa[f]=0;
			  }
			  else if(q2==1){
	  			cout<<"1, q2, "<<state[1][2]<<endl;
	  			q2=0,q3=0,q1=0;
	  			q4=1;
	  			last=2;
	  			change[i]=1;
	  			koncowa[f]=1;
		  }
		  	  else if(q1==1){
	  			cout<<"1, q1, "<<state[1][1]<<endl;
	  			q1=0,q2=0,q3=0;
	  			q4=1;
	  			last=1;
	  			change[i]=0;
	  			koncowa[f]=0;
		  }
		  	  else if(q3==1){
	  			cout<<"1, q3, "<<state[1][3]<<endl;
	  			q2=0,q1=0,q4=0;
	  			q3=1;
	  			last=3;
	  			change[i]=1;
	  			koncowa[f]=1;

		  }
		  	  else if(q4==1){
	  			cout<<"1, q4, "<<state[1][4]<<endl;
	  			q2=0,q3=0,q1=0;
	  			q4=1;
	  			last=4;
	  			change[i]=1;
	  			koncowa[f]=0;
		  }
		//continue;
	  }
	  
	  
	  	if(last==1 & a==0){
	  		
	  		cout<<"@, q1, 1, q3, -"<<endl;
	  		change[i+1]=1;
	  		koncowa[f+1]=1;
		  }
		  else if(last==2 & a==0){
		  
		  	cout<<"@, q2, 0, q4, L"<<endl;
		  	change[i+1]=0;
		  	koncowa[f+1]=1;
		  }
		  else if(last==3 & a==0){
		  		cout<<"@, q3, -, q3, -"<<endl;
		  	change[i+1]=0;
		  	koncowa[f+1]=0;
		  }
		   else if(last==4 & a==0){
		  		cout<<"@, q4, 1, q3, -"<<endl;
		 	 	change[i+1]=1;
		 	 	koncowa[f+1]=1;
		  }	
		  f++;
}
cout<<"Liczba koncowa to:  "<<endl;
for(int c=f; c>=0; c--){
	
	cout<<koncowa[c];
}

/*
cout<<"Liczba po zamianie to: ";
for(int i=b; i<=b; i++){
cout<<change[i];
}
*/
	return 0;
		
}


