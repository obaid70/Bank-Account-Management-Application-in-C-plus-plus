#include "SavingAccount.h"

void SavingAccount::CalculateInterest()
{
	int time = 0;
	cout << "\n Enter time since deposit in years : ";
	cin >> time;
	cout << "\n Calculated Interest : " << AccountBalance + (AccountBalance*interestRate*time) / 100 << endl;
}
void SavingAccount::display()
{
	cout << "\n Title : " << Title;
	cout << "\n Account Number : " << AccountNumber;
	cout << "\n Account Balance : Rs." << AccountBalance;
}
void SavingAccount::Deposit(int amount)
{
	AccountBalance = AccountBalance + amount;
}
void SavingAccount::Withdraw(int amount)
{
	AccountBalance = AccountBalance - amount;
	if (AccountBalance < 0)
	{
		AccountBalance = 0;
	}
}
SavingAccount::SavingAccount(const char * name, const char * num, int balance, float rate):Account(name,num,balance)
{
	interestRate = rate;
}
SavingAccount::SavingAccount(const SavingAccount & obj):Account(obj)
{
	interestRate = obj.interestRate;
}
SavingAccount::~SavingAccount()
{
	interestRate = 0;
}
void SavingAccount::setInterestRate(float rate)
{
	interestRate = rate;
}
float SavingAccount::getInterestRate()
{
	float interest = interestRate;
	return interest;
}
SavingAccount & SavingAccount::operator = (const SavingAccount & obj)
{
	SavingAccount s;
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
	s.interestRate = obj.interestRate;
	return s;
}
bool SavingAccount::operator == (const SavingAccount & obj)
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
	if (interestRate != obj.interestRate)
	{
		return false;
	}
	return true;
}
bool SavingAccount::operator != (const SavingAccount & obj)
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
	if (interestRate == obj.interestRate)
	{
		return false;
	}
	return true;
}
ostream & SavingAccount::operator << (ostream & out)
{
	out << "\n Title : " << Title;
	out << "\n Account Number : " << AccountNumber;
	out << "\n Account Balance : Rs." << AccountBalance;
	out << "\n Interest Rate : " << interestRate;
	return out;
}
istream & SavingAccount::operator >> (istream & in)
{
	int size = 0;
	char array[200] = { '\0' };
	cout << "\n Enter Title : ";
	cin.getline(array,200);
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
	cout << "\n Enter Interest Rate : ";
	in >> interestRate;
	return in;
}