#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

class employee;
class manager 
{
protected:
	string name, username, password;
public:
	manager() 
	{
		name = username = password = "NULL";
	}
	manager(string n, string u, string p) 
	{
		name = n;
		username = u;
		password = p;
	}
	friend void saveEmployeeInfo(employee obj);
	void getData() 
	{
		cout << "\t\t\t\tEnter Username: "; cin >> username;
		cout << "\t\t\t\tEnter Password: "; cin >> password;
		cout << "\t\t\t\tEnter name: "; cin >> name;
	}
	void putData() 
	{
		cout << "\n\n\t\t\t\tManager Name: " << name;
	}
};
class employee : public manager 
{
private:
	int emp_id, login_check = 0;
	string emp_post, check_username, check_pass, line;
protected:
	bool isEmpLoggedIn = 0;
public:	
	bool isManager = 0;
	employee() 
	{
		emp_id = 0;
		emp_post = "NULL";
	}
	employee(int i,string ep) 
	{
		emp_id = i;
		emp_post = ep;
	}
	friend void saveEmployeeInfo(employee obj);
	void getData() 
	{
		srand(time(0));
		manager::getData();
		emp_id = rand() % 10000;
		cout << "\t\t\t\tEnter employee post: "; cin >> emp_post;
		employee obj(emp_id, emp_post);
		obj.name = name;
		obj.username = username;
		obj.password = password;
		saveEmployeeInfo(obj);
	}
	void putData() 
	{
		manager::putData();
		cout << "\t\t\t\tEmployee ID: " << emp_id << endl;
		cout << "\t\t\t\tEmployee post: " << emp_post << endl;
	}
	void empLogin() 
	{
		while (1) 
		{
			cout << "\n\n\t\t\t\t======================\n";
			cout << "\t\t\t\t       BTL BANK" << endl;
			cout << "\t\t\t\t======================\n";
			cout << "\t\t\t\t  ::EMPLOYEE LOGIN::\n";
			cout << "\t\t\t\tEnter Username: "; cin >> check_username;
			cout << "\t\t\t\tEnter Password: "; cin >> check_pass; 
			ifstream file((check_username + ".txt").c_str());
			login_check = 0;
			int nameCheck = 0;
			while (file) 
			{
				getline(file, line);
				if (line == check_username && nameCheck == 0) 
				{
					login_check++;
					nameCheck++;
				}
				if (line == check_pass)
					login_check++;
				if (line == "Manager")
					isManager++;
			}
			try 
			{
				if (login_check == 2) 
				{
					isEmpLoggedIn = 1;
					cout << "\n\t\t\t\t!!Account Logged in!!" << endl;
					cout << "\t\t\t\tWelcome to employee portal\n" << endl;
					break;
				}
				else
					throw runtime_error("Error! wrong Username or PIN");
			}
			catch (exception & e) 
			{
				cout << "\t\t\t\tException caught: " << e.what() << endl;
			}
			file.close();
		}
	}
};
class managerFunctions : virtual public employee, public manager, public accountActions 
{
private:
	int book_id;
	char choice;
	string user_delete, line;
public:
	void addEmployee() 
	{
		try 
		{
			if (isEmpLoggedIn == 1) 
			{
				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\t       BTL BANK" << endl;
				cout << "\t\t\t\t======================\n";
				cout << "\t\t\t\t   ::ADD EMPLOYEE::\n";
				employee::getData();
			}
			else
				throw runtime_error("\n\t\t\t\tAccount not logged in!");
		}
		catch (exception & e) 
		{
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	void removeEmployee() 
	{
		try {
			if (isEmpLoggedIn == 1) 
			{
				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\t       BTL BANK" << endl;
				cout << "\t\t\t\t======================\n";
				cout << "\t\t\t\t ::REMOVE EMPLOYEE::\n";
				cout << "\t\t\tEnter the username of employee you want to remove: "; cin >> user_delete;
				ifstream file((user_delete + ".txt").c_str());
				try 
				{
					if (file) 
					{
						while (1) 
						{
							cout << "\t\t\tAre you sure you want to remove this employee (Y/N)? "; cin >> choice;
							if (choice == 'Y' || choice == 'y') 
							{
								file.close();
								remove((user_delete + ".txt").c_str());
								break;
							}
							else if (choice == 'N' || choice == 'n') 
							{
								break;
							}
							else
								cout << "\t\t\t\tWrong choice!";
						}
					}
					else
						throw runtime_error("\n\t\t\t\tNo employee exists with that Username!");
				}
				catch (exception & e) 
				{
					cout << "\t\t\t\tException caught " << e.what() << endl;
				}
			}
			else
				throw runtime_error("\n\t\t\t\tAccount not logged in!");
		}
		catch (exception & e) 
		{
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	void checkClientData() 
	{
		try {
			if (isEmpLoggedIn == 1) 
			{
				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\t       BTL BANK" << endl;
				cout << "\t\t\t\t======================\n";
				cout << "\t\t\t\t   ::CLIENT DETAILS::\n";
				cout << "\t\t\t\tEnter Client ID: "; cin >> checkID;
				try 
				{
					isLoggedIn = 1;
					getInfo();
					ifstream file((checkID + ".txt").c_str());
					if (file) 
					{
						ifstream file((checkID + ".txt").c_str());
						cout << endl;
						while (file) 
						{
							getline(file, line);
							cout << "\t\t\t\t" << line << endl;
						}
					}
					else
						throw runtime_error("No account exists with that ID!");
				}
				catch (exception & e) 
				{
					cout << "\t\t\t\tException caught " << e.what() << endl;
				}
			}
			else
				throw runtime_error("Account not logged in!");
		}
		catch (exception & e) 
		{
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	void modifyClientData() 
	{
		try 
		{
			if (isEmpLoggedIn == 1) 
			{
				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\t       BTL BANK" << endl;
				cout << "\t\t\t\t======================\n";
				cout << "\t\t\t\t   ::MODIFY CLIENT::\n";
				cout << "\t\t\t\tEnter Client ID: "; cin >> checkID;
				isLoggedIn = 1;
				getInfo();
				ifstream file((checkID + ".txt").c_str());
				try 
				{
					if (file) 
					{
						cout << "\n\t\t\t\tWhat do you want modify: " << endl;
						cout << "\t\t\t\t1. Client Name: " << endl;
						cout << "\t\t\t\t2. Client PIN: " << endl;
						cout<<"\n\n\t\t\t\tSelect Your Option (1-2): ";
						while (1) 
						{
							cin >> choice;
							if (choice == '1') 
							{
								cout << "\t\t\t\tEnter client Name: "; cin >> clientName;
								newAccount obj(clientName, clientDOB, accountType, idStr, balance, id, pin);
								saveInfo(obj);
								break;
							}
							else if (choice == '2') 
							{
								cout << "\n\t\t\t\tEnter new PIN: "; cin >> pin;
								newAccount obj(clientName, clientDOB, accountType, idStr, balance, id, pin);
								saveInfo(obj);
								break;
							}
							else 
							{
								cout << "\t\t\t\tEnter correct choice: ";
							}
						}
					}
					else
						throw runtime_error("No account exists with that ID!");
				}
				catch (exception & e) 
				{
					cout << "\t\t\t\tException caught " << e.what() << endl;
				}
			}
			else
				throw runtime_error("Account not logged in!");
		}
		catch (exception & e) 
		{
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	void issueChequeBook() 
	{
		srand(time(0));
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\t       BTL BANK" << endl;
		cout << "\t\t\t\t======================\n";
		cout << "\t\t\t\t ::ISSUE CHEQUEBOOK::\n";
		cout << "\t\t\t\tEnter ID: "; cin >> checkID;
		book_id = rand() % 10000000;
		cout << "\t\t\t\tChequebook " << book_id << " issued to account " << checkID << endl;
	}
};
void saveEmployeeInfo(employee obj) 
{
	ofstream file((obj.username + ".txt").c_str());
	while (file) 
	{
		file << obj.username << endl;
		file << obj.password << endl;
		file << obj.name << endl;
		file << obj.emp_id << endl;
		file << obj.emp_post << endl;
		break;
	}
	file.close();
}
