#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

static int p=0;

class a{
	char busn[5],driver[10],arrival[10],depart[5],from[10],to[10],seat[8][4][10];
	
 
public:
 void install();
 void allotment();
 void empty();
 void show();
 void avail();
 void position(int i);
}
bus[10];
void vline(char ch){
	for(int i=80;i>0;i++)
	cout<<ch;
	
}
void a::install(){
	cout <<"enter bus no";
	cin>>bus[p].busn;
	cout <<"\n enter driver name :";
	cin>>bus[p].driver;
	cout<<"\narrival time :";
	cin>>bus[p].arrival;
	cout<<"\n Departure :";
	cin>>bus[p].depart;
	cout<<"\n From \t\t";
	cin>>bus[p].from;
	cout<<"\n To : \t\t\t";
	cin>>bus[p].to;
  
   bus[p].empty();
   p++;
  	
}
void a::allotment(){
	int seat;
	char number[5];
	top:
	cout<<"Bus no:";
	cin>>number;
	int n;
	
	for(n=0;n<=p;n++){
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while (n<=p){
		cout<<"\n seat no:";
		cin>>seat;
		if(seat>32){
			cout<<"\n There are only 32 seats available in the bus";
			
		}
		else{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"Empty")==0){
				cout<<"Enter passenger name :";
				cin>>bus[n].seat[seat/4][(seat%4)-1];
				break;
			}
		else
		   cout<<"the seat no is already reserved \n";
		   
		}
	}
	if(n>p){
		cout<<"Enter the correct bus no \n";
		goto top;
	}
}
void a::empty(){
	for(int i =0;i<8;i++){
		for(int j=0;j<4;j++){
			strcpy(bus[p].seat[i][j],"empty");
		}
	}
} 
void a::show(){
	int n;
	char number[5];
	cout<<"enter  bus no :";
	cin>>number;
	for(n=0;n<=p;n++){
		if(strcmp(bus[n].busn,number)==0){
			break;
		}
		while(n<=p){
			vline('*');
			cout<<"Bus no :\t "<<bus[n].busn
		<<"\n Driver : \t"<<bus[n].driver <<"\t \t Arrival time : \t "
		<<bus[n].arrival<<"\t Department  time  :"<<bus[n].depart
        <<"\n From \t\t"<<bus[n].from<<"\t \t to \t\t"
		<<bus[n].to<<"\n";
		vline('*');
		bus[0].position(n);
		int a=1;
		for (int i=0;i<8;i++){
			for (int j=0;j<4;j++){
				a++;
				if(strcmp(bus[n].seat[i][j],"empty")!=0)
				cout<<"\nthe  seat no"<<(a-1)<<"is reserved for"<<bus[n].seat[i][j]<<".";
			}
		}			
		break;
		}
		if(n>p)
		cout<<"enter correct bus no :";
	}

}
void a::position(int i){
	int s= 0;p =0;
		cout<<"\n";
	for(int i =0;i<8;i++){
			cout<<"\n";
			for(int j=0;j<4;j++){
	     s++;
	     if(strcmp(bus[1].seat[i][j],"empty")==0){
	     	cout.width(5);
	     	cout.fill(' ');
	     	cout<<s<<".";
	     	cout.width(10);
	     	cout.fill(' ');
	     	cout<<bus[1].seat[i][j];
	     	p++;
		 }
		 else{
		 	cout.width(5);
	     	cout.fill(' ');
	     	cout<<s<<".";
	     	cout.width(10);
	     	cout.fill(' ');
	     	cout<<bus[1].seat[i][j];
		 }
	}
}
cout<<"\n \n There are "<<p<<"seats empty in bus no: "<<bus[1].busn;
}
void a::avail(){
	for(int n=0;n<p;n++){
	
	vline('*');
	cout<<"Bus no :\t"<<bus[n].busn<<"\n Driver : \t "<<bus[n].driver
	<<"\t \t Arrival Time :  \t"<<bus [n].arrival<<"\t Departue Time : \t "
	<<bus[n].depart<<"\n Form :\t \t"<<bus [n].from <<"\t \t to \t \t "
	<<bus[n].to<<"\n";
	vline('*');
	vline('_');

   }
}

int main(){
	system("cls");
	int w;
	
	while (1){
		
		cout<<"\n\n\n\n\n";
		cout<<"\t\t\t1.install\n\t\t\t"
		<<"\t\t\t2.Reserrvation\n\t\t\t"
		<<"\t\t\t3.show\n\t\t\t"
		<<"\t\t\t4.Buses available\n\t\t\t"
		<<"\t\t\t5.Exit\n\t\t\t";
		cout<<"\n \t\t\t Enter your chice";
		cin>>w;
		switch(w){
			case 1:bus[p].install();
			       break;
		    case 2:bus[p].allotment();
			       break; 
			case 3:bus[p].show();
			       break;     
			case 4:bus[p].avail();
			       break;      
			case 5:exit(0);
			       
	 }
		
	} 
	return 0;
}
