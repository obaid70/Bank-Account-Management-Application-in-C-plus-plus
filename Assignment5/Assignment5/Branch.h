#pragma once
#include"Account.h"
#include"CheckingAccount.h"
#include"CurrentAccount.h"
#include"InvestmentAccount.h"
#include"SavingAccount.h"
class Branch
{
private:
	Account ** account;
	int size;
	int totalBalance;
public:
	~Branch();
	void AddAccount();
	void deleteAccount();
	void UpdateAccount();
	void FindAccountByAN();
	void FindAccountByTitle();
	void setTotalBalance();
	int getSize();
	Account** getAccount();
	int getTotalBalance();
	void Menu();
	void Display();
	Account * & operator [](int);
	Account ** regrow();
	bool compare(char *, char *);
	void Shift(int);
};

