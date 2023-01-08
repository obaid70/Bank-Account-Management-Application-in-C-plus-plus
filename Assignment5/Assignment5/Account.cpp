#include "Account.h"


Account::Account(const char * name,const char * AccNum, int Balance)
{
	int size = 0;
	if (name != nullptr)
	{
		for (int i = 0; name[i] != '\0'; i++)
		{
			size++;
		}
		Title = new char [size + 1];
		for (int i = 0; i < size; i++)
		{
			Title[i] = name[i];
		}
		Title[size] = '\0';
	}
	size = 0;
	if (AccNum != nullptr)
	{
		for (int i = 0; AccNum[i] != '\0'; i++)
		{
			size++;
		}
		AccountNumber = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			AccountNumber[i] = AccNum[i];
		}
		AccountNumber[size] = '\0';
	}
	AccountBalance = Balance;
}
Account::Account(const Account & obj)
{
	int size = 0;
	if (obj.Title != nullptr)
	{
		for (int i = 0; obj.Title[i] != '\0'; i++)
		{
			size++;
		}
		Title = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			Title[i] = obj.Title[i];
		}
		Title[size] = '\0';
	}
	AccountNumber = obj.AccountNumber;
	AccountBalance = obj.AccountBalance;
}
Account::~Account()
{
	if (Title != nullptr)
	{
		delete[]Title;
		Title = nullptr;
	}
	AccountBalance = 0;
	AccountNumber = 0;
}
void Account::setTitle(const char * name)
{
	int size = 0;
	if (name != nullptr)
	{
		for (int i = 0; name[i] != '\0'; i++)
		{
			size++;
		}
		Title = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			Title[i] = name[i];
		}
		Title[size] = '\0';
	}
}
void Account::setAccountNumber(const char * num)
{
	int size = 0;
	if (num != nullptr)
	{
		for (int i = 0; num[i] != '\0'; i++)
		{
			size++;
		}
		AccountNumber = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			AccountNumber[i] = num[i];
		}
		AccountNumber[size] = '\0';
	}
}
void Account::setAccountBalance(int balance)
{
	AccountBalance = balance;
}
char * Account::getTitle()
{
	int size = 0;
	char * name = nullptr;
	if (Title != nullptr)
	{
		for (int i = 0; Title[i] != '\0'; i++)
		{
			size++;
		}
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = Title[i];
		}
		name[size] = '\0';
	}
	return name;
}
char * Account::getAccountNumber()
{
	int size = 0;
	char * name = nullptr;
	if (AccountNumber != nullptr)
	{
		for (int i = 0; AccountNumber[i] != '\0'; i++)
		{
			size++;
		}
		name = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			name[i] = AccountNumber[i];
		}
		name[size] = '\0';
	}
	return name;
}
int Account::getAccountBalance()
{
	int balance = AccountBalance;
	return balance;
}
bool Account::operator == (const Account & obj)
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
	size = 0;
	count = 0;
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
	return true;
}
bool Account::operator != (const Account & obj)
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
	return true;
}
ostream & Account::operator << (ostream & out)
{
	out << "\n Title : " << Title;
	out << "\n Account Number : " << AccountNumber;
	out << "\n Account Balance : " << AccountBalance;
	return out;
}
istream & Account::operator >> (istream & in)
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
	return in;
}