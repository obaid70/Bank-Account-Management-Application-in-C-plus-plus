#include "CurrentAccount.h"

void CurrentAccount::display()
{
	cout << "\n Title : " << Title;
	cout << "\n Account Number : " << AccountNumber;
	cout << "\n Account Balance : Rs." << AccountBalance;
}
void CurrentAccount::Deposit(int amount)
{
	AccountBalance = AccountBalance + amount - fees;
}
void CurrentAccount::Withdraw(int amount)
{
	AccountBalance = AccountBalance - amount - fees;
	if (AccountBalance < 0)
	{
		AccountBalance = 0;
	}
}
CurrentAccount::CurrentAccount(const char * name, const char * num, int balance, int fee, int Min) :Account(name, num, balance)
{
	MinBalance = Min;
	fees = fee;
}
CurrentAccount::CurrentAccount(const CurrentAccount & obj) : Account(obj)
{
	fees = obj.fees;
	MinBalance = obj.MinBalance;
}
CurrentAccount::~CurrentAccount()
{
	fees = 0;
	MinBalance = 0;
}
void CurrentAccount::setFees(int fee)
{
	fees = fee;
}
int CurrentAccount::getFees()
{
	int fee = fees;
	return fee;
}
void CurrentAccount::setMinBalance(int min)
{
	MinBalance = min;
}
int CurrentAccount::getMinBalance()
{
	int min = MinBalance;
	return min;
}
CurrentAccount & CurrentAccount::operator = (const CurrentAccount & obj)
{
	CurrentAccount s;
	s.AccountBalance = obj.AccountBalance;
	int size = 0;
	for (int i = 0; obj.Title[i] != '\0'; i++)
	{
		size++;
	}
	if (s.Title != nullptr)
	{
		delete[]s.Title;
		s.Title = nullptr;
	}
	s.Title = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		s.Title[i] = obj.Title[i];
	}
	s.Title[size] = '\0';
	size = 0;
	for (int i = 0; obj.AccountNumber[i] != '\0'; i++)
	{
		size++;
	}
	if (s.AccountNumber != nullptr)
	{
		delete[]s.AccountNumber;
		s.AccountNumber = nullptr;
	}
	s.AccountNumber = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		s.AccountNumber[i] = obj.AccountNumber[i];
	}
	s.AccountNumber[size] = '\0';
	s.fees = obj.fees;
	s.MinBalance = obj.MinBalance;
	return s;
}
bool CurrentAccount::operator == (const CurrentAccount & obj)
{
	int size = 0, count = 0;
	for (int i = 0; Title[i] != '\0'; i++)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		if (Title[i] == obj.Title[i])
		{
			count++;
		}
	}
	if (count != size)
	{
		return false;
	}
	size = 0, count = 0;
	for (int i = 0; AccountNumber[i] != '\0'; i++)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		if (AccountNumber[i] == obj.AccountNumber[i])
		{
			count++;
		}
	}
	if (count != size)
	{
		return false;
	}
	if (AccountBalance != obj.AccountBalance)
	{
		return false;
	}
	if (fees != obj.fees)
	{
		return false;
	}
	if (MinBalance != obj.MinBalance)
	{
		return false;
	}
	return true;
}
bool CurrentAccount::operator != (const CurrentAccount & obj)
{
	int size = 0, count = 0;
	for (int i = 0; Title[i] != '\0'; i++)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		if (Title[i] == obj.Title[i])
		{
			count++;
		}
	}
	if (count == size)
	{
		return false;
	}
	size = 0, count = 0;
	for (int i = 0; AccountNumber[i] != '\0'; i++)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		if (AccountNumber[i] == obj.AccountNumber[i])
		{
			count++;
		}
	}
	if (count == size)
	{
		return false;
	}
	if (AccountBalance == obj.AccountBalance)
	{
		return false;
	}
	if (fees == obj.fees)
	{
		return false;
	}
	if (MinBalance == obj.MinBalance)
	{
		return false;
	}
	return true;
}
ostream & CurrentAccount::operator << (ostream & out)
{
	out << "\n Title : " << Title;
	out << "\n Account Number : " << AccountNumber;
	out << "\n Account Balance : Rs." << AccountBalance;
	out << "\n Fees : " << fees;
	out << "\n Minimum Balance Requirement : Rs." << MinBalance;
	return out;
}
istream & CurrentAccount::operator >> (istream & in)
{
	int size = 0;
	char array[200] = { '\0' };
	cout << "\n Enter Title : ";
	cin.getline(array, 200);
	if (Title != nullptr)
	{
		delete[]Title;
		Title = nullptr;
	}
	for (int i = 0; array[i] != '\0'; i++)
	{
		size++;
	}
	Title = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		Title[i] = array[i];
	}
	Title[size] = '\0';
	cout << "\n Enter Account Number : ";
	cin.getline(array, 200);
	if (AccountNumber != nullptr)
	{
		delete[]AccountNumber;
		AccountNumber = nullptr;
	}
	for (int i = 0; array[i] != '\0'; i++)
	{
		size++;
	}
	AccountNumber = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		AccountNumber[i] = array[i];
	}
	AccountNumber[size] = '\0';
	cout << "\n Enter Account Balance : ";
	in >> AccountBalance;
	cout << "\n Enter Fees : ";
	in >> fees;
	cout << "\n Enter Minimum Balance Requirement : ";
	in >> MinBalance;
	return in;
}