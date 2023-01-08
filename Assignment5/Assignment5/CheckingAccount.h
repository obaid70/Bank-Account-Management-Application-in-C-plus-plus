#pragma once
#include "Account.h"
class CheckingAccount :	public Account
{
private:
	int fees;
public:
	void display();
	void Deposit(int);
	void Withdraw(int);
	CheckingAccount(const char * = {}, const char * = {}, int = {}, int = {});
	CheckingAccount(const CheckingAccount &);
	~CheckingAccount();
	void setFees(int);
	int getFees();
	CheckingAccount & operator = (const CheckingAccount &);
	bool operator == (const CheckingAccount &);
	bool operator != (const CheckingAccount &);
	ostream & operator << (ostream &);
	istream & operator >> (istream &);
};

