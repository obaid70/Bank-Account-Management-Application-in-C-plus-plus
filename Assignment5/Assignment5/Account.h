#include<iostream>
using namespace std;
#pragma once
class Account
{
protected:
	char * Title; 
	char * AccountNumber;
	int AccountBalance;
public:
	virtual void display()=0;
	virtual void Deposit(int)=0;
	virtual void Withdraw(int)=0;
	Account(const char * = {},const char * = {}, int = {});
	Account(const Account &);
	virtual ~Account();
	void setTitle(const char *);
	void setAccountNumber(const char *);
	void setAccountBalance(int);
	char * getTitle();
	char * getAccountNumber();
	int getAccountBalance();
	bool operator == (const Account &);
	bool operator != (const Account &);
	ostream & operator << (ostream &);
	istream & operator >> (istream &);
};

