#pragma once
#include "Account.h"
class CurrentAccount :public Account
{
private:
	int fees;
	int MinBalance;
public:
	void display();
	void Deposit(int);
	void Withdraw(int);
	CurrentAccount(const char * = {}, const char * = {}, int = {}, int = {}, int = {});
	CurrentAccount(const CurrentAccount &);
	~CurrentAccount();
	void setFees(int);
	int getFees();
	void setMinBalance(int);
	int getMinBalance();
	CurrentAccount & operator = (const CurrentAccount &);
	bool operator == (const CurrentAccount &);
	bool operator != (const CurrentAccount &);
	ostream & operator << (ostream &);
	istream & operator >> (istream &);
};

