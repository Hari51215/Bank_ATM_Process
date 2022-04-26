#include "Bank_ATM_Process.h"

int main()
{
    ATM_Process user;
    cout<<right<<setw(70)<<"! . . . ZOHO Corporation Bank . . . !"<<endl;

    int select=0,users_count=0;
    int acc_num=0,pin_num=0;
    int a_num=0,p_num=0,check=0,button=0;
    double acc_bal=0;
    string acc_name;
    char data;

    user.Read_Customer_Details();
    ATM_Process::Read_ATM_Cash();
    
    while(1)
    {
        ATM_Process::Write_ATM_Cash();
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
                    user.Show_Customer_Details();
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
                                    user.Write_ATM_Cash();
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