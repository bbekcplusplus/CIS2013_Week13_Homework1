#include<iostream>
#include <cstdlib>

#include <ctime>

using namespace std;
// Studies Problem Solving with C++ (Course Book)
// Some online C++ books for example: Chegg (computer science learning materials)
class BankAccount{

public:

string name;

int account_num;

int phone;

int balance;

double rate;

static int acc_num;

BankAccount(string name,int phone,int balance,double rate)

{

static int acc_num=0;

this->account_num=++acc_num;

this->name=name;

this->phone=phone;

this->balance=balance;

this->rate=rate;

}

void deposit(int amount)

{

this->balance+=amount;

}

void withdraw(int amount)

{

this->balance-=amount;

cout<<"Successfully Withdrawn "<<amount<<endl;

}

int balance()

{

return this->balance;

}

};

class Savings:public BankAccount{

public:

int minimum_balance;

int withdraw_limit;

Savings(string name,int phone,int balance,double rate,int minimum_balance,int withdraw_limit):BankAccount(name,phone,balance,rate)

{

this->minimum_balance=minimum_balance;

this->withdraw_limit=withdraw_limit;

}

void withdraw(int amount)

{

if(amount>this->withdraw_limit)

{

cout<<"Amount greater than withdraw limit!\n";

}

else

{

this->balance-=amount;

cout<<"Successfully Withdrawn "<<amount<<endl;

if(this->balance<this->minimum_balance)

{

cout<<"Balance less than minimum balance, please deposit!\n";

}

}

}

};

class Checking:public BankAccount{

public:

int overdraft_fee;

Checking(string name,int phone,int balance,double rate,int overdraft_fee):BankAccount(name,phone,balance,rate){

this->overdraft_fee=overdraft_fee;

}

void withdraw(int amount)

{

this->balance-=amount;

if(this->balance<0)

{

cout<<"Overdraft fee charged!\n";

this->balance-=this->overdraft_fee;

}

}

};