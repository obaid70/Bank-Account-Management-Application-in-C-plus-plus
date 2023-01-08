#pragma once
#include "Account.h"
class InvestmentAccount : public Account
{
private:
	int fees;
	int MinBalance;
	float profit;
public:
	void display();
	void Deposit(int);
	void Withdraw(int);
	InvestmentAccount(const char * = {}, const char * = {}, int = {}, int = {}, int = {}, float = {});
	InvestmentAccount(const InvestmentAccount &);
	~InvestmentAccount();
	void setFees(int);
	int getFees();
	void setMinBalance(int);
	int getMinBalance();
	void setProfit(float);
	float getProfit();
	InvestmentAccount & operator = (const InvestmentAccount &);
	bool operator == (const InvestmentAccount &);
	bool operator != (const InvestmentAccount &);
	ostream & operator << (ostream &);
	istream & operator >> (istream &);
};

