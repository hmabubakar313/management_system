#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
class Employe
{
    protected:
    string key,customer_id,account_number,first_name,last_name,cust_father_name,cust_mother_name,cust_cnic;
    //*setter and getter start from here
    void set_cust_id(string ci)
    {
        customer_id = ci;
    }
    string get_cust_id()
    {
        return customer_id;
    }
    void set_cust_account(string a_n)
    {
        account_number = a_n;
    }
    string get_cust_account()
    {
        return account_number;
    }
    void set_first_name(string f_n)
    {
        first_name = f_n;
    }
    string get_first_name()
    {
        return first_name;
    }
    void set_last_name(string l_n)
    {
        last_name = l_n;
    }
    string get_last_name()
    {
        return last_name;
    }
    void set_father_name(string father_n)
    {
        cust_father_name = father_n;
    }
    string get_father_name()
    {
        return cust_father_name;
    }
        void set_mother_name(string m_n)
    {
        cust_mother_name = m_n;
    }
    string get_cust_id()
    {
        return cust_mother_name;
    }
    void set_cust_cnic(string c_cnic)
    {
        cust_cnic = c_cnic;
    }
    string get_cust_id()
    {
        return cust_cnic;
    }
    void set_key(string k)
    {
        key = k;
    }
    string get_key()
    {
        return key;
    }
    //!setter and getter end here
};
class Customer :public Employe
{
void get_data()
{
    cout<<"Welcome to the ----- Bank\n";           //!stylling for Aqib
    cout<<"Enter Your First Name\n";
    cin>>first_name;
    cout<<"Enter Your Last Name\n";
    cin>>last_name;
    cout<<"Enter Your father Name\n";
    cin>>cust_father_name;
    cout<<"Enter Your Mother Name\n";
    cin>>cust_mother_name;
    cout<<"Enter Your CNIC\n";
    cin>>cust_cnic;
    cout<<"Press 1 to generate customer ID\n";
    cin>>key;
    // * generating customer id
     if (int(key)==1) //we took key as string here it create error for comparing int w/ string therfore i use int 
     {
         customer_id = rand() % 100;
     }
     cout<<"Congratulation your account created and your Customer ID is :"<<customer_id<<endl;

}

};
using namespace std;
int main()
{
    cout<<"Hello World\n";
}