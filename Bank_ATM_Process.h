#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<fstream>

using namespace std;
class Customer_Details;

double ATM_balance;
int Two_thousand=0, Five_hundred=0, Hundred=0;
vector<Customer_Details> user_data;
vector<int> ATM_Cash;

class Customer_Details
{
    public:
        int Account_number;
        int Pin_number;
        double Account_balance;
        string Account_holder;
        Customer_Details(){}
        Customer_Details (int acc_num, string acc_name, int pin_num, double acc_bal)
        {
            Account_number = acc_num;
            Account_holder = acc_name;
            Pin_number = pin_num;
            Account_balance = acc_bal;
        }

        void Read_Customer_Details()
        {
            int num,pin;
            double bal;
            string name;

            fstream Details;
            Details.open("Customer.txt",ios::in);
            if(Details.is_open())
            {
                while(Details>>num>>name>>pin>>bal)
                {
                    user_data.push_back(Customer_Details(num,name,pin,bal));
                }
                Details.close();
            }
        }

        void Show_Customer_Details()
        {
            cout<<endl<<left<<setw(20)<<"Account Number"<<left<<setw(20)<<"Account Holder"<<left<<setw(20)<<"Pin Number"<<left<<setw(20)<<"Account Balance"<<endl;
            for(int i=0; i<user_data.size(); ++i)
            {
                cout<<left<<setw(20)<<user_data[i].Account_number<<left<<setw(20)<<user_data[i].Account_holder<<left<<setw(20)<<user_data[i].Pin_number<<left<<setw(20)<<user_data[i].Account_balance<<endl;
            }
        }

        void check_account_balance()
        {
            cout<<Account_holder<<"'s "<<"Account Balance : "<<Account_balance<<endl;
        }

        void withdraw_money()
        {
            int withdraw_amount,ATM_pin_num,value=0,rem=0,temp=0;
            cout<<"Enter the Pin Number : ";
            cin>>ATM_pin_num;

            if(Pin_number==ATM_pin_num)
            {
                cout<<"Enter the Amount to be Withdrawn : ";
                cin>>withdraw_amount;
                if(withdraw_amount>=100 && withdraw_amount<=10000)
                {
                    if(ATM_balance<withdraw_amount)
                        cout<<"ATM Balance Low"<<endl;
                    else
                    {
                        if(Account_balance<withdraw_amount)
                            cout<<"Your Account Balance is low"<<endl;
                        else
                        {
                            if(withdraw_amount<=5000)
                            {
                                temp=withdraw_amount;
                                if(temp>3000)
                                {
                                    value=temp/2000;
                                    temp-=2000*value;
                                    Two_thousand-=value;
                                }
                                if(temp>1000)
                                {
                                    value=temp/500;
                                    temp-=500*value;
                                    Five_hundred-=value;
                                }
                                if(temp>1500)
                                {
                                    value=temp/100;
                                    temp-=100*value;
                                    Hundred-=value;   
                                }
                                else
                                {
                                    value=temp/100;
                                    temp-=100*value;
                                    Hundred-=value;   
                                }
                            }
                            else
                            {
                                if(withdraw_amount>5000)
                                {
                                    value=withdraw_amount/2000;
                                    rem=withdraw_amount%2000;
                                    Two_thousand-=value; 
                                }
                                if(rem>=500)
                                {
                                    value=rem/500;
                                    rem=rem%500;
                                    Five_hundred-=value;
                                }
                                if(rem<500)
                                {
                                    value=rem/100;
                                    rem=rem%100;
                                    Hundred-=value;
                                }
                            }
                            Account_balance-=withdraw_amount;
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
            int id_no,symbol;
            int Money_transfer,Bank_acc_num;
            cout<<"Account Number to which the money has to be transferred : ";
            cin>>Bank_acc_num;

            fstream Details;
            Details.open("Customer_Details.txt",ios::in);
            if(Details.is_open())
            {    
                while(Details>>Account_number>>Account_holder>>Pin_number>>Account_balance>>symbol)
                {
                    user_data.push_back(Customer_Details(Account_number,Account_holder,Pin_number,Account_balance));
                }
                Details.close();
            }

            for(int i=0;i<user_data.size();i++)
            {
                if(user_data[i].Account_number==Bank_acc_num)
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
                    user_data[id_no].Account_balance+=Money_transfer;
                    Account_balance-=Money_transfer;
                    cout<<"Money Transfer Successfully."<<endl;
                }
            }
            else
            {
                cout<<"Invalid Account Number"<<endl;
            }
        }
};

class ATM_Process : public Customer_Details
{
    protected:
        char Feed_cash;
        int User_acc_num, User_pin_num;
    public:
        int id;
        void Load_Cash()
        {
            int note,number,total;
            fstream Cash;
            Cash.open("ATM_Cash.txt",ios::in);
            if(Cash.is_open())
            {
                while(Cash>>note>>number>>total)
                {
                    ATM_Cash.push_back(total);
                }
                Cash.close();
            }

            cout<<"ATM Balance = "<<ATM_balance<<endl;
            cout<<"Is it Required to Feed the Money into the ATM (Y/N): ";
            cin>>Feed_cash;
            int TT=0,FH=0,H=0;
            if(Feed_cash=='Y')
            {
                cout<<endl<<"Enter the Number of 2,000 Currency Notes to be feed into the ATM : ";
                cin>>TT;
                cout<<"Enter the Number of 500 Currency Notes to be feed into the ATM : ";
                cin>>FH;
                cout<<"Enter the Number of 100  Currency Notes to be feed into the ATM : ";
                cin>>H;

                Two_thousand+=TT;
                Five_hundred+=FH;
                Hundred+=H;

                ATM_balance=(2000*Two_thousand) + (500*Five_hundred) + (100*Hundred);
                
                fstream Cash;
                Cash.open("ATM_Cash.txt",ios::out);
                if(Cash.is_open())
                {
                    Cash<<left<<setw(20)<<"2000"<<left<<setw(20)<<Two_thousand<<left<<setw(20)<<2000*Two_thousand<<endl;
                    Cash<<left<<setw(20)<<"500"<<left<<setw(20)<<Five_hundred<<left<<setw(20)<<500*Five_hundred<<endl;
                    Cash<<left<<setw(20)<<"100"<<left<<setw(20)<<Hundred<<left<<setw(20)<<100*Hundred<<endl;

                    Cash<<endl<<"ATM Balance = "<<ATM_balance<<endl;
                    Cash.close();
                }
                cout<<endl<<"Cash loaded into the ATM is Successfully and Stored in the ATM_Cash.txt file"<<endl;
            }
            else if(Feed_cash=='N')
               cout<<"ATM Balance = "<<ATM_balance<<endl;
            else
                cout<<"Invalid Input"<<endl;
        }

        int using_ATM(int a_num,int p_num)
        {
            int symbol;
            User_acc_num=a_num;
            User_pin_num=p_num;

            fstream Details;
            Details.open("Customer_Details.txt",ios::in);
            if(Details.is_open())
            {    
                while(Details>>Account_number>>Account_holder>>Pin_number>>Account_balance>>symbol)
                {
                    user_data.push_back(Customer_Details(Account_number,Account_holder,Pin_number,Account_balance));
                }
                Details.close();
            }

            for(int i=0;i<user_data.size();i++)
            {
                if(user_data[i].Account_number==User_acc_num && user_data[i].Pin_number==User_pin_num)
                {
                    id=i;
                    return id;
                }
            }
            return 0;

        }

        void check_atm_balance()
        {
            cout<<endl<<left<<setw(20)<<"Denomination"<<left<<setw(20)<<"Number"<<left<<setw(20)<<"Value"<<endl;
            cout<<left<<setw(20)<<"2000"<<left<<setw(20)<<Two_thousand<<left<<setw(20)<<2000*Two_thousand<<endl;
            cout<<left<<setw(20)<<"500"<<left<<setw(20)<<Five_hundred<<left<<setw(20)<<500*Five_hundred<<endl;
            cout<<left<<setw(20)<<"100"<<left<<setw(20)<<Hundred<<left<<setw(20)<<100*Hundred<<endl;

            cout<<"Total Amount available in the ATM = "<<ATM_balance<<" ₹"<<endl;
        }
};