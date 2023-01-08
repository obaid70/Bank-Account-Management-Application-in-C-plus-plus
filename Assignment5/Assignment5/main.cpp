#include<iostream>
using namespace std;
#include"Branch.h"
void display(Branch &);

int main()
{
	Branch bank;
	bank.Menu();
	display(bank);
	return 0;
}

void display(Branch & bank )
{
	bank.setTotalBalance();
	cout << "\n Total Balance in the branch : " << bank.getTotalBalance() << endl << endl;
	if (bank.getSize()== 0)
	{
		cout << "\n There are 0 Bank Accounts in the Branch.\n\n";
	}
	else
	{
		for (int i = 0; i < bank.getSize(); i++)
		{
			cout << "\n Account number " << i + 1 << " :-\n";
			bank.getAccount()[i]->display();
			cout << endl << endl;
		}
	}
	cout << endl;
}