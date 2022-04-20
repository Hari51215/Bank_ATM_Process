#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include "Bank_ATM_Process.h"

int main()
{
    int acc_num,pin_num,users_count;
    string acc_name;
    double acc_bal;
    
    cout<<right<<setw(60)<<"! . . . ZOHO Corporation Bank . . . !"<<endl<<endl;
    cout<<"Enter the Number of Customer Details to be stored into the Bank Database System : ";
    cin>>users_count;
    
    for(int i=0;i<users_count;i++)
    {
        cout<<endl<<"Enter the Account Number : ";
        cin>>acc_num;
        cout<<"Enter the Account Holder Name : ";
        cin>>acc_name;
        cout<<"Enter the ATM Pin Number of User : ";
        cin>>pin_num;
        cout<<"Enter the Account Balance in the User Account : ";
        cin>>acc_bal;
        
        user_data.push_back(Customer_Details(acc_num,acc_name,pin_num,acc_bal));
        cout<<endl;
    }
    cout<<left<<setw(20)<<"Account Number"<<left<<setw(20)<<"Account Holder"<<left<<setw(20)<<"Pin Number"<<left<<setw(20)<<"Account Balance"<<endl;
    for(int i=0;i<user_data.size();i++)
    {
        user_data[i].display_details();
    }
    
    ATM_Process user;
    cout<<right<<setw(60)<<"! . . . ZOHO Corporation ATM . . . !"<<endl<<endl;
    user.set_atm_balance();
    user.check_atm_balance();
    
    int button,a_num,p_num;
    cout<<"Enter your Account Number : ";
    cin>>a_num;
    cout<<"Enter your Pin Number : ";
    cin>>p_num;
    user.user_validation(a_num,p_num);
    
    return 0;
}