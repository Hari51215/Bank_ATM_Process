#include "Bank_ATM_Process.h"
using namespace std;

int main()
{
    ATM_Process user;
    cout<<right<<setw(70)<<"! . . . ZOHO Corporation Bank . . . !"<<endl;

    int select=0,users_count;
    int acc_num,pin_num;
    int a_num,p_num,check,button;
    double acc_bal;
    string acc_name;
    char data;

    while(1)
    {
        cout<<"__________________________________________________________________________________________________";
        cout<<"\nATM Main Menu : "<<endl;
        cout<<"\n1. Load Cash to ATM. \n2. Show Customer Details. \n3. Show ATM Operations. \n4. Exit ATM."<<endl;
        cout<<"\nSelect an Option to proceed further . . . ";
        cin>>select;
        switch(select)
        {
            case 1:
                    user.Load_Cash();
                    break;
            case 2:
                    cout<<"Do you need to include the Customer Details (Y/N) : ";
                    cin>>data;

                    if(data=='Y')
                    {
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
                        user.Show_Customer_Details();
                    }
                    else if(data=='N')
                    {
                        user.Read_Customer_Details();
                    }
                    else
                        cout<<"Oops..!, Invalid Input : Kindly enter Y or N only."<<endl;
                    break;
            case 3:
                    cout<<"Hi User, Welcome to Zoho Corporation Bank"<<endl;
                    cout<<"Enter your Account Number : ";
                    cin>>a_num;
                    cout<<"Enter your Pin Number : ";
                    cin>>p_num;

                    check = user.using_ATM(a_num,p_num);
                    if(check>=0)
                    {
                        cout<<endl<<"1. Check Balance \n2. Withdraw Money \n3. Transfer Money \n4. Check ATM Balance "<<endl<<endl;
                        cout<<"Selection the option to perfotm the Task : ";
                        cin>>button;
                        switch(button)
                        {
                            case 1:
                                    user_data[check].check_account_balance();
                                    break;
                            case 2:
                                    user_data[check].withdraw_money();
                                    break;
                            case 3:
                                    user_data[check].transfer_money();
                                    break;
                            case 4:
                                    user.check_atm_balance();
                                    break;
                            default:
                                cout<<"Invalid Option . . !\nChoose the Correct option Again"<<endl;
                                exit (0);
                        }
                    }
                    else
                    {
                        cout<<"Oops..!,Invalid Account : Must Create an Account."<<endl;
                    }
                    break;
            case 4:
                    cout<<"! ... Thank you ... !"<<endl;
                    return 0;
            default:
                    cout<<"Oops..!, Invalid Selection, Re-Select the Option Again."<<endl;
        }
    }
    return 0;
}