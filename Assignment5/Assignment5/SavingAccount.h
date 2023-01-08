#pragma once
#include "Account.h"
class SavingAccount :	public Account
{
private:
	float interestRate;
public:
	void CalculateInterest();
	void display();
	void Deposit(int);
	void Withdraw(int);
	SavingAccount(const char * = {}, const char * = {}, int = {}, float = {});
	SavingAccount(const SavingAccount &);
	~SavingAccount();
	void setInterestRate(float);
	float getInterestRate();
	SavingAccount & operator = (const SavingAccount &);
	bool operator == (const SavingAccount &);
	bool operator != (const SavingAccount &);
	ostream & operator << (ostream &);
	istream & operator >> (istream &);
};

