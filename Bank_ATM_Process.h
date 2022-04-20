#ifndef ATM
#define ATM
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

class Customer_Details
{
    protected:
        int Account_number, Pin_number;
        double Account_balance;
        string Account_holder;
    public:
        Customer_Details();
        Customer_Details(int acc_num, string acc_name, int pin_num, double acc_bal);
        void display_details();
        void check_account_balance();
};

vector<Customer_Details> user_data;

class ATM_Cash : public Customer_Details
{
    protected:
        double ATM_balance;
        char Feed_cash;
        int Two_thousand, Five_hundred, Hundred;
    public:
        int set_atm_balance();
        void check_atm_balance();   
};

class ATM_Process : public ATM_Cash, public Customer_Details
{
    int User_acc_num, User_pin_num;
    public:
        ATM_Process();
        void set_user_details(int acc_num, int pin_num);
        void user_validation(int a_num,int p_num);
        void withdraw_money();
        void transfer_money();
};

// class NegativeValueException
// {
//     public:
//         NegativeValueException()=default;
//         ~NegativeValueException()=default;
// };

// class InvalidInputException
// {
//     public:
//         InvalidInputException()=default;
//         ~InvalidInputException()=default;
// };

#endif