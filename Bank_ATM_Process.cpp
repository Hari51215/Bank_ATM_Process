#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class Customer_Details
{
    protected:
        int Account_number;
        int Pin_number;
        double Account_balance;
        string Account_holder;

    public:
        Customer_Details()
        {
            Account_number=0;
            Pin_number=0;
            Account_balance=0;
            Account_holder="NULL";
        }
        Customer_Details (int acc_num, string acc_name, int pin_num, double acc_bal)
        {
            Account_number = acc_num;
            Account_holder = acc_name;
            Pin_number = pin_num;
            Account_balance = acc_bal;
        }

        void display_details()
        {
            cout<<left<<setw(20)<<Account_number<<left<<setw(20)<<Account_holder<<left<<setw(20)<<Pin_number<<left<<Account_balance<<" ₹"<<endl;
        }

        void check_account_balance()
        {
            cout<<Account_holder<<"'s "<<"Account Balance : "<<Account_balance<<endl;
        }
};

vector<Customer_Details> user_data;

class ATM_Cash
{
    protected:
        double ATM_balance=0;
        char Feed_cash;
        int Two_thousand=0, Five_hundred=0, Hundred=0;

    public:
        void set_atm_balance()
        {
            cout<<"ATM Balance = "<<ATM_balance<<endl;
            cout<<"Is it Required to Feed the Money into the ATM (Y/N): ";
            cin>>Feed_cash;

            if(Feed_cash=='Y')
            {
                cout<<endl<<"Enter the Number of 2,000 Currency Notes to be feed into the ATM : ";
                cin>>Two_thousand;
                cout<<"Enter the Number of 500 Currency Notes to be feed into the ATM : ";
                cin>>Five_hundred;
                cout<<"Enter the Number of 100  Currency Notes to be feed into the ATM : ";
                cin>>Hundred;

                ATM_balance=(2000*Two_thousand) + (500*Five_hundred) + (100*Hundred);

                cout<<"\nMoney Feeded into the ATM, Dispalying it's Denominations."<<endl;
                cout<<endl<<left<<setw(20)<<"Denomination"<<left<<setw(20)<<"Number"<<left<<setw(20)<<"Value"<<endl;
                cout<<left<<setw(20)<<"2000"<<left<<setw(20)<<Two_thousand<<left<<setw(20)<<2000*Two_thousand<<endl;
                cout<<left<<setw(20)<<"500"<<left<<setw(20)<<Five_hundred<<left<<setw(20)<<500*Five_hundred<<endl;
                cout<<left<<setw(20)<<"100"<<left<<setw(20)<<Hundred<<left<<setw(20)<<100*Hundred<<endl;

                cout<<endl<<"ATM Balance = "<<ATM_balance<<endl;
            }
            else if(Feed_cash=='N')
               cout<<"ATM Balance = "<<ATM_balance<<endl;
            else
                cout<<"Invalid Input"<<endl;
        }

        void check_atm_balance()
        {
            cout<<endl<<left<<setw(20)<<"Denomination"<<left<<setw(20)<<"Number"<<left<<setw(20)<<"Value"<<endl;
            cout<<left<<setw(20)<<"2000"<<left<<setw(20)<<Two_thousand<<left<<setw(20)<<2000*Two_thousand<<endl;
            cout<<left<<setw(20)<<"500"<<left<<setw(20)<<Five_hundred<<left<<setw(20)<<500*Five_hundred<<endl;
            cout<<left<<setw(20)<<"100"<<left<<setw(20)<<Hundred<<left<<setw(20)<<100*Hundred<<endl;

            cout<<"ATM Balance = "<<ATM_balance<<endl;
        }
};

class ATM_Process : public ATM_Cash, public Customer_Details
{
    int User_acc_num, User_pin_num;
    public:
        int id=0,button;
        ATM_Process() {User_acc_num=0;User_pin_num=0;}

        void user_validation(int a_num,int p_num)
        {
            int i;
            User_acc_num=a_num;
            User_pin_num=p_num;
            
            for(i=0;i<user_data.size();i++)
            {
                if(Account_number[i]==User_acc_num && Pin_number[i]==User_pin_num)
                {
                    id=i;
                    break;
                }
            }
            if(id!=0) 
            {
                cout<<"1. Check Balance \n2. Withdraw Money \n3. Transfer Money \n4. Check ATM Balance "<<endl;
                cout<<"Selection the option to perfotm the Task : ";
                cin>>button;
                
                switch(button)
                {
                    case 1:
                            user_data[id].check_account_balance();
                            break;
                    case 2:
                            user_data[id].withdraw_money();
                            break;
                    case 3:
                            user_data[id].transfer_money();
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
                cout<<"Account Not Found"<<endl;
            }
        }

        void withdraw_money()
        {
            int withdraw_amount,ATM_pin_num;
            cout<<"Enter the Pin Number : ";
            cin>>ATM_pin_num;
            if(Pin_number[id]==ATM_pin_num)
            {
                cout<<"Enter the Amount to be Withdrawn : ";
                cin>>withdraw_amount;
                if(withdraw_amount>=100 && withdraw_amount<=10000)
                {
                    if(ATM_balance<withdraw_amount)
                        cout<<"ATM Balance Low"<<end;
                    else
                    {
                        if(Account_balance[i]<withdraw_amount)
                            cout<<"Your Account Balance is low"<<endl;
                        else
                        {
                            if(withdraw_amount<=5000)
                            {
                                if(withdraw_amount>3000)
                                {
                                    withdraw_amount-=2000;
                                    Two_thousand-=1;
                                    if(withdraw_amount>1500 && (withdraw_amount-1500)>=1000)
                                    {
                                        withdraw_amount-=1500;
                                        Hundred-=15;
                                        if(withdraw_amount>1000)
                                        {
                                            withdraw_amount-=1500;
                                            Five_hundred-=3;
                                        }
                                    }
                                    else 
                                    {
                                        if(withdraw_amount>1000)
                                        {
                                            withdraw_amount-=1000;
                                            Hundred-=10;
                                        }
                                        else
                                        {
                                            if(withdraw_amount<1000)
                                            {
                                                withdraw_amount-=500;
                                                Five_hundred-=1;
                                            }
                                        }
                                    }
            
                                }
                                else
                                {
                                    ;
                                }
                            }
                            else
                            {
                                ;
                                // 2000₹ X 2
                                // 500₹ X 2 (increase for higher amounts)
                                // 100₹ X 10 (Maximum 10 numbers)
                            }
                            Account_balance[id]-=withdraw_amount;
                        }
                        ATM_balance-=withdraw_amount;
                    }
                }
                else
                {
                    cout<<"Withdrawal limit for a single transaction is, Maximum=10,000₹ and Minimum = 100₹"<<endl;
                }
            }
        }

        void transfer_money()
        {
            int id_no;
            int Money_transfer,Bank_acc_num;
            cout<<"Account Number to which the money has to be transferred : ";
            cin>>Bank_acc_num;
                
            for(int i=0;i<user_data.size();i++)
            {
                if(Account_number[i]==Bank_acc_num)
                {
                    id_no=i;
                    break;
                }
            }
            
            if(id_no!=0)
            {
                cout<<"Enter the Money to be Transferred : ";
                cin>>Money_transfer;
                if(!(Money_transfer>=1000 && Money_transfer<=10000))
                    cout<<"Transfer limit per transaction is, Maximum = 10,000 ₹ and Minimum = 1000 ₹"<<endl;
                else
                {
                    Account_balance[id_no]+=Money_transfer;
                    Account_balance[id]-=Money_transfer;
                }
            }
            else
            {
                cout<<"Invalid Account Number"<<endl;
            }
        }
};