// Semaster_Project.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cmath>
//#include <string>
//#include <conio.h>

using namespace std;

class user{
protected:
	char F_name[10],L_name[10],email[25],mobi[12],type;
	double age,i,Acc_ID,pass,blnc;
public:
	void userdata(){
		cout<<"\n\t\t\t\t\t Enter First Name : ";
		cin>>F_name;
		cout<<"\n\t\t\t\t\t Enter last Name : ";
		cin>>L_name;
		cout<<"\n\t\t\t\t\t Enter Email-ID : ";
		cin>>email;
		cout<<"\n\t\t\t\t\t Enter Age : ";
		cin>>age;
		cout<<"\n\t\t\t\t\t Enter Mobile No : ";
		cin>>mobi;
	}
};
class Account : public user{
public:
	void UserData(){
		cout<<"\n\t\t\t\t\t Enter Account-ID : ";
		cin>>Acc_ID;
		do{
			cout<<"\n\t\t\t\t\t Enter type Account..(C/S) : ";
			cin>>type;
			if(type=='s' || type =='S')
			{
				cout<<"\n\t\t\t\t\t Enter Initial Amount (>= Rs.500) : ";
				cin>>blnc;
				if(blnc<500){
					cout<<"\n\t\t\t\t Please Enter greater than Rs.500"<<endl;
				}
				i=1;
			}
			else if(type=='C' || type =='c')
			{
				cout<<"\n\t\t\t\t\t Enter Initial Amount (>= Rs.1000) : ";
				cin>>blnc;

				if(blnc<1000){
					cout<<"\n\t\t\t\t Please Enter greater than Rs.1000"<<endl;
				}
				i=1;
			}
			else
			{
				cout<<"\n\t\t\t\t Try Again Press 'c' for Current Account , 's' for Saving Account"<<endl;
				i=0;
			}
		}while(i==0);
		cout<<"\n\t\t\t\t\t Enter Password : ";
		cin>>pass;
	}
	void nam()       // Name display
	{
		cout<<F_name<<"  "<<L_name;cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
	}
};
class Transaction : public Account    // class Transaction  , Account Inherit
{
	int amnt,p,t;
	float r,ci;
public:
	Transaction()
	{
		amnt=0;
	}
	void displ()
	{
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Account Name is "<<F_name<<" "<<L_name;
		cout<<"\n\t Balance is "<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		//	getch();
	}     
	void deposit()   // Deposit 
	{
		cout<<"\n\t  Enter amount to Deposit : ";
		cin>>amnt;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		if(amnt>=100)
		{
			blnc=blnc+amnt;
		}
		else
		{
			cout<<"\n\t Amount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n\t You have Deposited Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		//	getch(); 
	}   
	void withdraw()   // Withdraw
	{
		cout<<"\n\t  Enter amount to Withdraw : ";
		cin>>amnt;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		if(amnt>=100)
		{
			if(blnc-amnt<0)
			{
				cout<<"\n\t Insufficient Balance ";
				//				getch();
			}        
			else
				blnc=blnc-amnt;
		}
		else
		{
			cout<<"\n\tAmount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t You have Withdrawl Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		if(type=='c' || type=='C')
		{
			if(blnc<1000)
			{
				cout<<"\n\t Your have cross the limit of minimum balance charges may apply ";
				blnc=blnc-100;
			}
		}
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		//	getch(); 
	} 
	void blncenquiry()     // Balance Enquiry
	{
		cout<<"\n\t   Name : "<<F_name<<" "<<L_name;
		cout<<"\n\t   Account No : "<<Acc_ID;
		if(type=='s' || type== 'S')
			cout<<"\n\t   Type of Account : Saving";
		else
			cout<<"\n\t   Type of Account : Current"; 
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t   Your Available balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		//	getch();
	} 
	void checkbk()
	{
		if(type=='c' || type=='C')
		{
			system("cls");
			cout<<"\n\t Check Book Facility Available";
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
			//			getch();
		}
		else
		{
			//system("cls");
			cout<<"\n\t Check Book Facility Not Available";
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
			//	getch();
		}
	} 
	void compound()
	{
		system("cls");
		if(type=='s' || type=='S')
		{
			cout<<"\n\t   Enter Principle Amount : ";
			cin>>p; 
			cout<<"\n\t   Enter the rate of interest : ";
			cin>>r;
			cout<<"\n\t   Enter the time : ";
			cin>>t;  
			ci=p*(pow((1+r/100),t));
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
			cout<<"\n\n\t The Compound Interest is : "<<ci<<endl;
			cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		}
		else
			cout<<"\n\t Compound Interest Not Available in Current Account"<<"__________________________________________________";
		//	getch();
	}  
	void info()
	{
		system("cls");
		system("color d");
		cout<<"\n\n";
		cout<<"\n\t Name : "<<F_name<<" "<<L_name;
		cout<<"\n\t Account No : "<<Acc_ID;
		cout<<"\n\n\t\t\t\t\t\t\t\t Age : "<<age;
		cout<<"\n\n\t\t\t\t\t\t\t\t Email-Id : "<<email;
		cout<<"\n\n\t\t\t\t\t\t\t\t Mobile NO : "<<mobi;
		if(type=='S' || type=='s')
			cout<<"\n\n\t\t\t\t\t\t\t\t Type of Account : Saving";
		else
			cout<<"\n\n\t\t\t\t\t\t\t\t Type of Account : Current";
		cout<<"\n\n\t\t\t\t\t\t\t\t Available Balance : Rs."<<blnc;

		//getch();
		system("color 7");
	}       
};
int main()
{
	int j=0,ch;
	Transaction obj;
	do{
		cout <<"*********Wellcome*******";
		cout<<"\n\t 1. Costomer Data ";
		cout<<"\n\t 2. Account Data ";
		cout<<"\n\t 3. Display ";
		cout<<"\n\t 4. Deposit Amount ";
		cout<<"\n\t 5. Withdraw Amount ";
		cout<<"\n\t 6. Balance Enquiry ";
		cout<<"\n\t 7. Check Book Facility";
		cout<<"\n\t 8. Calculate Compound Interest ";
		cout<<"\n\t 9. Account Info";
		cout<<"\n\t  Exit(0)  \t\t Sign Out(s)";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t  Enter your choice : ";
		cin>>ch;

		if(ch==1){
			obj.userdata();
			j=0;
		}
		else if(ch==2){
			obj.UserData();
			j=0;
		}
		else if(ch==3){
			obj.displ();
			j=0;
		}
		else if(ch==4){
			obj.deposit();
			j=0;
		}
		else if(ch==5){
			obj.withdraw();
			j=0;
		}
		else if(ch==6){
			obj.blncenquiry();
			j=0;
		}
		else if(ch==7){
			obj.checkbk();
			j=0;
		}
		else if(ch==8){		
			obj.compound();
			j=0;
		}
		else if(ch==9){
			obj.info();
			j=0;
		}
		else if(ch==0){
			j=1;
		}
		else{
			j=0;
		}

	}while(j==0);
	obj.nam();


	return 0;
}
