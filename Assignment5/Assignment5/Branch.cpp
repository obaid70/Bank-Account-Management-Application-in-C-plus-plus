#include "Branch.h"

Branch::~Branch()
{
	for (int i = 0; i < size; i++)
	{
		account[i]->~Account();
	}
	delete[]account;
	account = nullptr;
}
void Branch::AddAccount()
{
	int option = 0, balance = 0, fee = 0, MinBal = 0;
	char name[200] = { '\0' }, num[200] = { '\0' };
	float IR = 0, profit = 0;
	if (size == 0)
	{
		account = new Account*[1];
		size++;
		cout << "\n Please enter 1 for Saving Account.\n";
		cout << "\n Please enter 2 for Checking Account.\n";
		cout << "\n Please enter 3 for Current Account.\n";
		cout << "\n Please enter 4 for Investment Account.\n ";
		while (option < 1 || option >4)
		{
			cout << "\n Please select an option (1-4) : ";
			cin >> option;
			cin.ignore();
		}
		if (option == 1)
		{
			cout << "\n Please enter title : ";
			cin.getline(name, 200);
			cout << "\n Please enter Account number : ";
			cin.getline(num, 200);
			cout << "\n Please enter Account Balance : ";
			cin >> balance;
			cout << "\n Please enter Interest Rate : ";
			cin >> IR;
			account[0] = new SavingAccount(name,num,balance,IR);
			cout << "\n Account Added Successfully!\n";
			cout << endl;
		}
		if (option == 2)
		{
			cout << "\n Please enter title : ";
			cin.getline(name, 200);
			cout << "\n Please enter Account number : ";
			cin.getline(num, 200);
			cout << "\n Please enter Account Balance : ";
			cin >> balance;
			cout << "\n Please enter Transaction Fee : ";
			cin >> fee;
			account[0] = new CheckingAccount(name,num,balance,fee);
			cout << "\n Account Added Successfully!\n";
			cout << endl;
		}
		if (option == 3)
		{
			cout << "\n Please enter title : ";
			cin.getline(name, 200);
			cout << "\n Please enter Account number : ";
			cin.getline(num, 200);
			cout << "\n Please enter Account Balance : ";
			cin >> balance;
			cout << "\n Please enter Transaction Fee : ";
			cin >> fee;
			cout << "\n Please enter Minimum Required Balance : ";
			cin >> MinBal;
			account[0] = new CurrentAccount(name, num, balance, fee, MinBal);
			cout << "\n Account Added Successfully!\n";
			cout << endl;
		}
		if (option == 4)
		{
			cout << "\n Please enter title : ";
			cin.getline(name, 200);
			cout << "\n Please enter Account number : ";
			cin.getline(num, 200);
			cout << "\n Please enter Account Balance : ";
			cin >> balance;
			cout << "\n Please enter Transaction Fee : ";
			cin >> fee;
			cout << "\n Please enter Minimum Required Balance : ";
			cin >> MinBal;
			cout << "\n Please enter Profit : ";
			cin >> profit;
			account[0] = new InvestmentAccount(name, num, balance, fee, MinBal, profit);
			cout << "\n Account Added Successfully!\n";
			cout << endl;
		}
	}
	else
	{
	account = regrow();
	size++;
	cout << "\n Please enter 1 for Saving Account.\n";
	cout << "\n Please enter 2 for Checking Account.\n";
	cout << "\n Please enter 3 for Current Account.\n";
	cout << "\n Please enter 4 for Investment Account.\n ";
	while (option < 1 || option >4)
	{
		cout << "\n Please select an option (1-4) : ";
		cin >> option;
		cin.ignore();
	}
	if (option == 1)
	{
		cout << "\n Please enter title : ";
		cin.getline(name, 200);
		cout << "\n Please enter Account number : ";
		cin.getline(num, 200);
		cout << "\n Please enter Account Balance : ";
		cin >> balance;
		cout << "\n Please enter Interest Rate : ";
		cin >> IR;
		account[size - 1] = new SavingAccount(name, num, balance, IR);
		cout << "\n Account Added Successfully!\n";
		cout << endl;
	}
	if (option == 2)
	{
		cout << "\n Please enter title : ";
		cin.getline(name, 200);
		cout << "\n Please enter Account number : ";
		cin.getline(num, 200);
		cout << "\n Please enter Account Balance : ";
		cin >> balance;
		cout << "\n Please enter Transaction Fee : ";
		cin >> fee;
		account[size - 1] = new CheckingAccount(name, num, balance, fee);
		cout << "\n Account Added Successfully!\n";
		cout << endl;
	}
	if (option == 3)
	{
		cout << "\n Please enter title : ";
		cin.getline(name, 200);
		cout << "\n Please enter Account number : ";
		cin.getline(num, 200);
		cout << "\n Please enter Account Balance : ";
		cin >> balance;
		cout << "\n Please enter Transaction Fee : ";
		cin >> fee;
		cout << "\n Please enter Minimum Required Balance : ";
		cin >> MinBal;
		account[size - 1] = new CurrentAccount(name, num, balance, fee, MinBal);
		cout << "\n Account Added Successfully!\n";
		cout << endl;
	}
	if (option == 4)
	{
		cout << "\n Please enter title : ";
		cin.getline(name, 200);
		cout << "\n Please enter Account number : ";
		cin.getline(num, 200);
		cout << "\n Please enter Account Balance : ";
		cin >> balance;
		cout << "\n Please enter Transaction Fee : ";
		cin >> fee;
		cout << "\n Please enter Minimum Required Balance : ";
		cin >> MinBal;
		cout << "\n Please enter Profit : ";
		cin >> profit;
		account[size - 1] = new InvestmentAccount(name, num, balance, fee, MinBal, profit);
		cout << "\n Account Added Successfully!\n";
		cout << endl;
	}
	}
}
void Branch::deleteAccount()
{
	int choice = 0, check = 0;
	char array[200] = { '\0' };
	cout << "\n Please enter Account Title : ";
	cin.getline(array, 200);
	for (int i = 0; i < size; i++)
	{
		if (compare(array, account[i]->getTitle()) == true)
		{
			check = 1;
			Shift(i);
			cout << "\n\n Account Deleted Successfully!\n\n";
			break;
		}
	}
	if (check == 0)
	{
		cout << "\n\n No Account Found by this Title!\n";
	}
}
void Branch::UpdateAccount()
{
	int amount = 0, choice = 0, check = 0;
	char array[200] = { '\0' };
	cout << "\n Please enter account title : ";
	cin.getline(array, 200);
	for (int i = 0; i < size; i++)
	{
		if (compare(array, account[i]->getTitle()) == true)
		{
			check = 1;
			cout << "\n 1.Enter 1 to Deposit Amount.\n";
			cout << "\n 2.Enter 2 to Withdraw Amount.\n";
			while (choice < 1 || choice >2)
			{
				cout << "\n Please select an option (1-2) : ";
				cin >> choice;
				cin.ignore();
			}
			if (choice == 1)
			{
				cout << "\n\n Please enter Amount to Deposit : Rs.";
				cin >> amount;
				cin.ignore();
				account[i]->Deposit(amount);
				cout << "\n Rs."<<amount<<" Deposited Successfully!\n\n";
			}
			else if (choice == 2)
			{
				cout << "\n\n Please enter Amount to Withdraw : Rs.";
				cin >> amount;
				cin.ignore();
				if (amount > account[i]->getAccountBalance())
				{
					cout << "\n Insufficient Funds in the Account!\n\n";
				}
				else
				{
					account[i]->Withdraw(amount);
					cout << "\n Rs."<<amount<<" Withdraw Successfully!\n\n";
				}
			}
			break;
		}
	}
	if (check == 0)
	{
		cout << "\n\n No Account Found by this Title!\n";
	}
}
void Branch::FindAccountByAN()
{
	int check = 0;
	char array[200] = { '\0' };
	cout << "\n Please enter account Number : ";
	cin.getline(array, 200);
	for (int i = 0; i < size; i++)
	{
		if (compare(array, account[i]->getAccountNumber()) == true)
		{
			check = 1;
			cout << endl;
			account[i]->display();
			cout << endl << endl;
			break;
		}
	}
	if (check == 0)
	{
		cout << "\n\n No Account Found by this Account Number!\n";
	}
}
void Branch::FindAccountByTitle()
{
	int choice = 1, check = 0;
	char array[200] = { '\0' };
	cout << "\n Please enter Account Title : ";
	cin.getline(array, 200);
	for (int i = 0; i < size; i++)
	{
		if (compare(array, account[i]->getTitle()) == true)
		{
			check = 1;
			cout << "\n Account number " << choice << " :-\n";
			account[i]->display();
			cout << endl << endl;
			choice++;
		}
	}
	if (check == 0)
	{
		cout << "\n\n No Account Found by this Title!\n";
	}
}
void Branch::Menu()
{
	int option = -1;
	while(option!=0)
	{ 
		option = -1;
		cout << "\n\n					Banking Management System :- \n\n";
		cout << "\n 0.Press 0 to Exit from program.\n";
		cout << "\n 1.Press 1 for Adding an Account.\n";
		cout << "\n 2.Press 2 for Deleting an Account. \n";
		cout << "\n 3.Press 3 for Updating ( Deposit / Withdraw ) an Account.\n";
		cout << "\n 4.Press 4 for Finding an Account by Account Number.\n";
		cout << "\n 5.Press 5 for Finding an Account by Title.\n";
		cout << "\n 6.Press 6 to Display all Accounts.\n ";
		while (option < 0 || option>6)
		{
			cout << "\n Please select an option ( 0-6 ) : ";
			cin >> option;
			cin.ignore();
		}
		system("CLS");
		if (option == 0)
		{
			cout << "\n\n Thank You! For Using the Banking Management System.\n\n";
			system("pause");
		}
		else if (option == 1)
		{
			AddAccount();
			system("pause");
		}
		else if (option == 2)
		{
			deleteAccount();
			system("pause");
		}
		else if (option == 3)
		{
			UpdateAccount();
			system("pause");
		}
		else if (option == 4)
		{
			FindAccountByAN();
			system("pause");
		}
		else if (option == 5)
		{
			FindAccountByTitle();
			system("pause");
		}
		else if (option == 6)
		{
			Display();
			system("pause");
		}
		system("CLS");
	}
}
void Branch::Display()
{
	setTotalBalance();
	cout << "\n Total Balance in the branch : Rs." << totalBalance << endl << endl;
	if (size == 0)
	{
		cout << "\n There are 0 Bank Accounts in the Branch.\n\n";
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << "\n Account number " << i + 1 << " :-\n";
			account[i]->display();
			cout << endl;
			cout << "_________________________________________\n";
		}
	}
	cout << endl;
}
int Branch::getSize()
{
	return size;
}
Account** Branch::getAccount()
{
	return account;
}
void Branch::setTotalBalance()
{
	totalBalance = 0;
	for (int i = 0; i < size; i++)
	{
		totalBalance = totalBalance + account[i]->getAccountBalance();
	}
}
int Branch::getTotalBalance()
{
	return totalBalance;
}
Account * & Branch::operator [](int i)
{
	return account[i];
}
Account ** Branch::regrow()
{
	Account ** temp = account;
	account = nullptr;
	account = new Account *[size + 1];
	for (int i = 0; i < size; i++)
	{
		account[i] = temp[i];
	}
	account[size] = nullptr;
	delete[]temp;
	temp = nullptr;
	return account;
}

bool Branch::compare(char * array1, char * array2)
{
	int count = 0,  size = 0;
	for (int i = 0; array1[i] != '\0'; i++)
	{
		size++;
	}
	for (int i = 0; i < size; i++)
	{
		if (array1[i] == array2[i])
		{
			count++;
		}
	}
	if (count == size)
	{
		return true;
	}
	return false;
}

void Branch::Shift(int index)
{
	for (int i = index; i < size-1; i++)
	{
		account[i] = account[i + 1];
	}
	Account ** temp = account;
	account = nullptr;
	account = new Account *[size - 1];
	size--;
	for (int i = 0; i < size; i++)
	{
		account[i] = temp[i];
	}
	delete[]temp;
	temp = nullptr;
}