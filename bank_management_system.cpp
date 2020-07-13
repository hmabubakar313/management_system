// BANK_Managment_System_Final.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip> 

using namespace std;

class Account{
protected:
	string name,email,M_no,pass;
	double age,years,amt ,i,Acc_ID;
	double initial_amt,blnc;
public:
	// create virtual functions
	virtual void display()=0;  
	virtual void create_ac()=0;  
	virtual void deposit()=0;  
	virtual void withdraw()=0;  
	virtual void blncenquiry()=0;  
	virtual void checkbk()=0;
	virtual void info()=0;
	// function setter and getter
	void setter(string n,string e, string mn,string p,double a,double y,double am,double AC,double i_am,double b){
		name=n;
		email=e;
		M_no=mn;
		age=a;
		years=y;
		amt=am;
		Acc_ID=AC;
		initial_amt=i_am;
		blnc=b;
		pass=p;
	}

	string get_name(){	return name;}
	string get_email(){	return email;	}
	string get_MobileNomber(){	return M_no;	}
	string get_Password(){	return pass;}
	double get_age(){return age; }
	double get_years(){return years; }
	double get_Amount(){return amt; }
	double get_Account_ID(){return Acc_ID; }
	double get_Init_amount(){return initial_amt; }
	double get_balance(){return blnc; }
	// function get data of costumer
	void getdata()
	{
		cout<< "\nEnter Name Account Holder   : ";
		cin >> name; 
		cout<< "\nEnter Email_ID  : ";
		cin >> email;
		cout<< "\nEnter Age  : ";
		cin >> age;
		cout<< "\nEnter mobile Number : ";
		cin >> M_no; 
		cout <<"\n========================\n";
	} 
};

class CurrentAccount : public Account
{
protected:
	int k,x; 
public:  
	CurrentAccount()
	{
		Acc_ID=000;
		blnc=amt=initial_amt=0.0;
	}
	int gen_acc_num()
	{
			
		static int s_nID=001;
		ofstream file1("CurrentAccount.txt",ios::app);
		file1<<"Account ID\t"<<"Name :\t"<<"E-mail :\t"<<"   Mobile Number :\n";
		file1<<s_nID<<"\t\t"<<name<<"\t"<<email<<"\t\t    "<<M_no<<"\t\t"<<endl;
		file1.close();
		// !remove("CurrentAccount.txt");
		
		return s_nID++;
	}
	//!  here apply file handling 
	void display()
	{
		cout<<"\n\t\t<><><><><><><><><><><><><><>\n";
		cout<<"\t\tAccount holder name is :"<< name <<endl;
		cout<<"\t\tbalance :"<<blnc<<endl;						
		cout<<"\n\t\t<><><><><><><><><><><><><><>\n";
	} 
	void create_ac()
	{
		cout<<"\nNEW Current Account\n";  
		cout<<"\nEnter Accout ID : "; 
		 x=gen_acc_num();
		cout<<setw(3)<<setfill('0')<< x <<endl;  
		cout <<"Enter Password : ";
		cin >>pass;
		k=1;
		while (k==1) 
		{
			cout<<"\nEnter initial amount of deposit: \n";  
			cin>>amt;  
			if(amt<500)  
			{  
				cout<<"\nMinimum deposit amount: Rs500\nTry Again\n";   
				// k=2; //!here is the  mistake
				k=1;
			} 
			else
			{
				blnc = amt;  
				initial_amt=amt;
				k=0;
			}
		}
	}  
	void deposit()
	{
		cout<<"\n\t  Enter amount to Deposit : \n";
		cin>>amt;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		if(amt>=100)
		{
			blnc=blnc+amt;
		}
		else
		{
			cout<<"\n\t Amount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n\t You have Deposited Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}  
	void withdraw()
	{
		cout<<"\n\t  Enter amount to Withdraw : ";
		cin>>amt;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		if(amt>=100)
		{
			if(blnc-amt<0)
			{
				cout<<"\n\t Insufficient Balance ";
			}        
			else
			{
				blnc=blnc-amt;
			}
		}
		else
		{
			cout<<"\n\tAmount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t You have Withdrawl Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		do
		{
			if(blnc<1000)
			{
				cout<<"\n\t Your have cross the limit of minimum balance charges may apply ";
				blnc=blnc-100;
			}
			else
			{
				i=0;
			}
		}while(i==1);
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}  
	void blncenquiry()
	{
		cout<<"\n\t   Name : "<<name;
		cout<<"\n\t   Account No : ";
		cout<<setw(4)<<setfill('0')<< x <<endl;
		cout<<"\n\t   Type of Account : Current"; 
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t   Your Available balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}  
	void checkbk()
	{	
		cout<<"\n\t Check Book Facility Available";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
	void info()
	{
		cout<<"\n\n";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";	
		cout<<"\n\t Name			  : "<< name;
		cout<<"\n\t Account No		  : ";
		cout<<setw(4)<<setfill('0')<< x <<endl;
		cout<<"\n\t Age			 : "<<age;
		cout<<"\n\t Email-Id		  : "<<email;
		cout<<"\n\t Mobile NO		  : "<<M_no;
		cout<<"\n\t Type of Account	  : Current";
		cout<<"\n\t Available Balance	  : Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
};

class SaveingAccount : public Account{
protected:
	double p_amt,time,rate,com_interest;
	int k,x;
public:  
	SaveingAccount()
	{
		Acc_ID=000;
		blnc=amt=initial_amt=0.0;
		p_amt=0;
		time=0;
		rate=0;
		com_interest=0;
	}
	int gen_acc_num()
	{	
		ofstream File("SavingAcount.txt",ios::app);		
		static int s_nID=001;
		File<<"Account ID\t"<<"Name :\t"<<"E-mail :\t"<<"   Mobile Number :\n";
		File<<s_nID<<"\t\t"<<name<<"\t"<<email<<"\t\t    "<<M_no<<"\t\t"<<endl;
		File.close();
		//!remove("SavingAcount.txt");	
		return s_nID++;
	}
	// here apply file handling
	void display()
	{			
		cout<<"\n<><><><><><><><><><><><><><>\n";
		cout<<"Account holder name is : "<< name<<endl;
		cout<<"Balance				  : "<<blnc<<endl;
		cout<<"\tSaveing Account .....";
		cout<<"\n<><><><><><><><><><><><><><>\n";
	} 
	void create_ac()
	{
		cout<<"\n\t NEW Saving Account\n";  
		x=gen_acc_num();
		cout<<"Enter Accout ID : "; 
		x=gen_acc_num();
		cout<<setw(3)<<setfill('0')<< x <<endl;
		cout<<"Enter Password : ";
		cin >>pass;
		cout<<"\nEnter initial amount of deposit: ";  
		cin >>amt;
		k=1;  
		while(k==1)
		{
			if(amt<500)  
			{  
				cout<<"Minimum deposit amount: Rs500\n...Try Again... \n";    
				k=1;
			} 
			else
			{
				blnc = amt;  
				initial_amt=amt;
				k=0;
			}
		}
	}  
	void deposit()
	{
		cout<<"\n\t  Enter amount to Deposit : ";
		cin>>amt;
		cout<<"\n+++++++++++++++++++++++++++++++++++\n";
		if(amt>=100)
		{
			blnc=blnc+amt;
		}
		else
		{
			cout<<"\n\t Amount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n\t You have Deposited Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++\n";
	}  
	void withdraw()
	{
		cout<<"\n\t  Enter amount to Withdraw : ";
		cin>>amt;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++\n";
		if(amt>=100)
		{
			if(blnc-amt<0)
			{
				cout<<"\n\t Insufficient Balance ";
			}        
			else
				blnc=blnc-amt;
		}
		else
		{
			cout<<"\n\tAmount Should be Greater than equal Rs.100 "<<endl<<endl<<endl;
		}
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t You have Withdrawl Successfully ";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		do
		{
			if(blnc<1000)
			{
				cout<<"\n\t Your have cross the limit of minimum balance charges may apply ";
				blnc=blnc-100;
			}
			else
			{
				i=0;
			}
		}while(i==1);
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t Current Balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
	}  
	void blncenquiry()
	{
		cout<<"\n\t   Name : "<<name;
		cout<<"\n\t   Account No : ";
		cout<<setw(4)<<setfill('0')<< x <<endl;
		cout<<"\n\t   Type of Account : Saveing"; 
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\t   Your Available balance is Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}  
	void checkbk()
	{	
		cout<<"\n\t Check Book not Facility Available";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
	void compound()
	{
		// system("cls");
		cout<<"\n\t   Enter Principle Amount : ";
		cin>>p_amt; 
		cout<<"\n\t   Enter the rate of interest : ";
		cin>>rate;
		cout<<"\n\t   Enter the time : ";
		cin>>time;  
		com_interest=p_amt*(pow((1+rate/100),time));
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++";
		cout<<"\n\n\t The Compound Interest is : "<<com_interest<<endl;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}  
	void info(){
		cout<<"\n\n";
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
		cout<<"\n\t Name			  : "<< name;
		cout<<"\n\t Account No		  : ";
		cout<<setw(4)<<setfill('0')<< x <<endl;
		cout<<"\n\t Age		  : "<<age;
		cout<<"\n\t Email-Id		  : "<<email;
		cout<<"\n\t Mobile NO		  : "<<M_no;
		cout<<"\n\t Type of Account	  : Saveing";
		cout<<"\n\t Available Balance     : Rs."<<blnc;
		cout<<"\n+++++++++++++++++++++++++++++++++++++++++++\n";
	}
}; 

int main()
{
	int choice,ch,i=1,j=1;
	char type;
	CurrentAccount CA;
	SaveingAccount SA;
	while (j==1)
	{
		cout << "\n\t\t=-=-=-=-=-=-=-=-=-=-=\n";
		cout << "\t\t|   Group Members   |";
		cout << "\n\t\t=-=-=-=-=-=-=-=-=-=-=\n";
		cout << "Roll NO.\t\t\t Name";
		cout <<"\n\t------------------------------------\n";
		cout << "BCS-192012\t\t\t Muhammad Abu Bkar\n";
		cout << "BCS-192015\t\t\t Aqib Ahmed\n";
		cout << "BCS-192032\t\t\t Soban Zahid\n";
		cout << "\n\t\t=-=-=-=-=-=-=-=-=-=-=-=\n";
		cout << "\t\t| Wlcome to XYZ Bank  |";
		cout << "\n\t\t=-=-=-=-=-=-=-=-=-=-=-=\n";
		cout <<"1 .. For Create Account  ....\n2 .. For Exit\t\n";
		cout <<"\n\t-----------------------------\n";
		cin >> choice;
		cout<<endl;
		if (choice==1)
		{
			system("cls"); 
			CA.getdata();
		

			cout <<" C/c .. for Current  or S/s .. for saving...\n ---------------------\n";
			cout <<" Type of Account : ";
			cin  >> type; 
			if (type == 'C' || type == 'c')
			{
				while(i==1)
				{
					cout<<" \t1..for account create \n \t2..for Display \n \t3..for Deposit \n \t4..for Withdraw \n \t5..for Balance Enquiry\n";
					cout <<" \t6..for Check Book \n \t7..for Info \n \t8..for Exit \n";
					cout <<"=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=.=\n";
					cin>>ch;
					cout<<endl;
					if (ch==1)	{
						CA.create_ac();
						i=1;
					}
					else if (ch==2)	{
						CA.display();
						i=1;
					}
					else if (ch==3)	{
						CA.deposit();
						i=1;
					}
					else if (ch==4)	{
						CA.withdraw();
						i=1;
					}
					else if (ch==5) {
						CA.blncenquiry();
						i=1;
					}
					else if (ch==6)	{
						CA.checkbk();
						i=1;
					}
					else if (ch==7)	{
						CA.info();
						i=1;
					}
					else if (ch==8) {
						i=0;
					}
					else
					{
						cout <<"Invailed  ......try again ";
						i=1;
					}
				}
			}
			else if(type == 'S' || type == 's')
			{
				while(i==1)
				{
					cout<<"\n \t1..for account create \n \t2..for Display \n \t3..for Deposit \n \t4..for Withdraw \n \t5..for Balance Enquiry\n";
					cout <<" \t6..for Check Book \n \t7..for interest compound \n \t8..Info \n \t9..for exit\n";
					cout <<"\n\t:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:=:\n";
					cin>>ch;
					cout<<endl;
					if (ch==1)		{	
						SA.create_ac();
						i=1;
					}
					else if (ch==2)	{
						SA.display();
						i=1;
					}
					else if (ch==3)	{
						SA.deposit();
						i=1;
					}
					else if (ch==4)	{
						SA.withdraw();
						i=1;
					}
					else if (ch==5)	{
						SA.blncenquiry();
						i=1;
					}
					else if (ch==6) {
						SA.checkbk();
						i=1;
					}
					else if (ch==6) {
						SA.checkbk();
						i=1;
					}
					else if (ch==7)	{
						SA.compound();
						i=1;
					}
					else if (ch==8)	{
						SA.info();
						i=1;
					}
					else if (ch==9)	{
						i=0;
					}
					else
					{
						cout <<"\n\tinvalid....Try Again ...";
						i=1;
					}
				}
			}
			
		}
		else if (choice==2)
		{
			j=0;
		}
		else{ j=1; }
	}
	return 0;
}

