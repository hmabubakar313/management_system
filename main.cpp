#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
// #include <cstring>
#include <cmath>
using namespace std;
class Employe
{
    public:
    string first_name,last_name,cust_father_name,cust_mother_name,cust_cnic;
    int key,customer_id,account_number,card_number,card_id;
    //*setter and getter start from here
    void set_cust_id(int ci)
    {
        customer_id = ci;
    }
    int get_cust_id()
    {
        return customer_id;
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
    string get_mother_name()
    {
        return cust_mother_name;
    }
    void set_cust_cnic(string c_cnic)
    {
        cust_cnic = c_cnic;
    }
    string get_cust_cnic()
    {
        return cust_cnic;
    }
    void set_key(int k)
    {
        key = k;
    }
    int get_key()
    {
        return key;
    }
    void set_account_number(int a_number)
    {
        account_number = a_number;
    }
    int get_account_number()
    {
        return account_number;
    }
    void set_card_number(int c_number)
    {
        card_number = c_number;
    }
    int get_card_number()
    {
        return card_number;
    }
    void set_card_id(int c_id)
    {
        card_id = c_id;
    }
    int get_card_id()
    {
        return card_id;
    }
    //!setter and getter end here
    
    
};
class Customer :public Employe
{
    public:
        // void get_data()
        // {
        //     cout<<"Welcome to the ----- Bank\n";           //!stylling for Aqib
        //     cout<<"Enter Your First Name\n";
        //     cin>>first_name;
        //     cout<<"Enter Your Last Name\n";
        //     cin>>last_name;
        //     cout<<"Enter Your father Name\n";
        //     cin>>cust_father_name;
        //     cout<<"Enter Your Mother Name\n";
        //     cin>>cust_mother_name;
        //     cout<<"Enter Your CNIC\n";
        //     cin>>cust_cnic;
        //     cout<<"Press 1 to generate customer ID\n";
        //     cin>>key;
        //     // * generating customer id
        //     if (key==1) 
        //     {
        //         srand(time(0));
        //         customer_id = (rand() % 100) + 1; // use for random number
        //     }
        //     cout<<"Congratulation your account created and your Customer ID is : 00"<<customer_id<<endl;

        // }

        // getting data for cards detail and checkbook

        void get_data_cards()
        {
            // cout<<"Welcome to the ----- Bank\n";           //!stylling for Aqib
            // cout<<"Enter Your First Name\n";
            // cin>>first_name;
            // cout<<"Enter Your Last Name\n";
            // cin>>last_name;
            // cout<<"Enter Your father Name\n";
            // cin>>cust_father_name;
            // cout<<"Enter Your Mother Name\n";
            // cin>>cust_mother_name;
            // cout<<"Enter Your CNIC\n";
            // cin>>cust_cnic;
            // cout<<"Enter Your Account Number\n";
            // cin>>account_number;
            cout<<"Press 1 to generate customer ID\n";
            cin>>key;
            // * generating customer id
            if (key==1) 
            {
                srand(time(0));
                card_number = (rand() % 100000000) + 1; // use for random number
            }
            cout<<"Congratulation your account created and your Credit and Debit Card ID is : 00"<<card_id<<endl;

        }
         

};

int main()
{
    Customer cust_obj;
    // cust_obj.get_data();
    cust_obj.get_data_cards();
    return 0;   
}