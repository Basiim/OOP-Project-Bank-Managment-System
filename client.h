#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

class client { //Abstract class
protected:
	int id, pin;
	string clientName;
	string clientDOB;
	string accountType; // Savings or current
	string idStr;
	double balance;
public:
	client() {
		
	}
	client(int i, int p) { // Assigning id and pin to an account
		id = i;
		pin = p;
	}
	virtual void getInfo() = 0; // Pure virtual function
	virtual void displayInfo() = 0;
};
class newAccount : public client {
private:
public:
	newAccount() {

	}
	newAccount(string cn, string cd, string at,string ids, float b, int i, int p) {
		clientName = cn;
		clientDOB = cd;
		accountType = at;
		idStr = ids;
		balance = b;
		id = i;
		pin = p;
	}
	friend void saveInfo(newAccount obj);
	void getInfo() {
		srand(time(0)); // Random seed
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\t       BTL BANK" << endl;
		cout << "\t\t\t\t======================\n";
		cout << "\t\t\t\t    ::NEW ACCOUNT::\n";
		cout << "\t\t\t\tEnter Name: "; cin >> clientName;
		cout << "\t\t\t\tEnter date of birth: "; cin >> clientDOB;
		cout << "\t\t\t\tEnter account type (C/S): "; cin >> accountType;
		cout << "\t\t\t\tEnter initial balance: "; cin >> balance;
		cout << "\t\t\t\tEnter PIN: "; cin >> pin;
		id = rand() % 10000; // randomly generated account id
		cout << "\t\t\t\tAccount " << id << " created sucessfully" << endl;
		idStr = to_string(id);
		newAccount obj(clientName, clientDOB, accountType,idStr, balance, id, pin);
		saveInfo(obj);
	}
	void displayInfo() {

	}
};
class exsistingAccount : public client {
private:
	string line;
	string bal, idx, p;
	int loginCheck = 0;
protected:
	bool isLoggedIn = 0;
	string checkID, checkPIN;
public:
	void login() {
		while (1) {
			cout << "\n\n\t\t\t\t======================\n";
			cout << "\t\t\t\t       BTL BANK" << endl;
			cout << "\t\t\t\t======================\n";
			cout << "\t\t\t\t  ::CLIENT LOGIN::\n";
			cout << "\t\t\t\tEnter ID: ";cin >> checkID;
			idStr = checkID;
			cout << "\t\t\t\tEnter PIN: "; cin >> checkPIN;
			ifstream file((idStr + ".txt").c_str());
			loginCheck = 0;
			while (file) {
			getline(file, line);
				if (line == checkID) //ID found
				loginCheck++;
				if (line == checkPIN) //PIN found
				loginCheck++;
			}
			try {
				if (loginCheck >= 2) {
					isLoggedIn = 1;
					getInfo();
					cout << "\n\t\t\t\t!Account Logged in!" << endl;
					cout << "\t\t\t\t Welcome " << clientName << endl;
					break;
				}
				else
					throw runtime_error("Error! wrong ID or PIN");
			}
			catch (exception& e) {
				cout << "\t\t\t\tException caught: " << e.what() << endl;
			}
			file.close();
		}
	}
	void getInfo() {
		try {
			if (isLoggedIn == 1) {
				idStr = checkID;
				int count = 0;
				ifstream file((idStr + ".txt").c_str());
				while (getline(file, line)) {
					count++;
					stringstream ss(line);
					switch (count) {
					case 1:
						ss >> clientName;
						break;
					case 2:
						ss >> clientDOB;
						break;
					case 3:
						ss >> accountType;
						break;
					case 4:
						ss >> bal;
						break;
					case 5:
						ss >> idx;
						break;
					case 6:
						ss >> p;
						break;
					}
				}
				file.close();
				stringstream z(p);
				z >> pin;
				stringstream y(idx);
				y >> id;
				stringstream x(bal);
				x >> balance;
			}
			else
				throw runtime_error("Account not logged in!");
		}
		catch (exception & e) {
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	void displayInfo()
	{
		try {
			if (isLoggedIn == 1) {
				cout << "\n\n\t\t\t\t======================\n";
				cout << "\t\t\t\t       BTL BANK" << endl;
				cout << "\t\t\t\t======================\n";
				cout << "\t\t\t\t ::ACCOUNT DETAILS::\n";
				cout << "\n\n\t\t\t\tName: " << clientName << endl;
				cout << "\t\t\t\tDOB: " << clientDOB << endl;
				cout << "\t\t\t\tAccount Type: " << accountType << endl;
				cout << "\t\t\t\tBalance: " << balance << endl;
			}
			else
				throw runtime_error("Account not logged in!");
		}
		catch (exception & e) {
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
	friend void saveInfo(newAccount obj);
};
class accountActions : public exsistingAccount{ // Add functions of exsisting account here
private:
	float withdraw;
	float deposit;
	float transfer;
	string accID;
	char choice;
public:
	friend void saveInfo(newAccount obj);
	void withdrawMoney() {
		getInfo();
		while (1) {
			cout << "\n\n\t\t\t\t======================\n";
			cout << "\t\t\t\t       BTL BANK" << endl;
			cout << "\t\t\t\t======================\n";
			cout << "\t\t\t\t   ::WITHDRAW CASH::\n";
			cout << "\t\t\t\tEnter the amount to withdraw: "; cin >> withdraw;
			if (withdraw > balance)
				cout << "\t\t\t\tInsufficient balance!" << endl;
			else {
				balance = balance - withdraw;
				cout << "\t\t\t\tAmount " << withdraw << " has been debted from your account" << endl;
				newAccount obj(clientName, clientDOB, accountType, idStr, balance, id, pin);
				saveInfo(obj);
				break;
			}
		}
	}
	void depositMoney() {
		getInfo();
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\t       BTL BANK" << endl;
		cout << "\t\t\t\t======================\n";
		cout << "\t\t\t\t   ::DEPOSIT CASH::\n";
		cout << "\t\t\t\tEnter the amount to deposit: "; cin >> deposit;
		balance = balance + deposit;
		cout << "\t\t\t\tAmount " << deposit << " has been deposited to your account" << endl;
		newAccount obj(clientName, clientDOB, accountType, idStr, balance, id, pin);
		saveInfo(obj);
	}
	void deleteAccount() {
		while (1) {
			cout << "\n\n\t\t\t\t======================\n";
			cout << "\t\t\t\t       BTL BANK" << endl;
			cout << "\t\t\t\t======================\n";
			cout << "\t\t\t\t  ::DELETE ACCOUNT::\n";
			cout << "\t\t\tAre you sure you want to delete your account (Y/N)? "; cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				getInfo();
				remove((idStr + ".txt").c_str());
				break;
			}
			else if (choice == 'N' || choice == 'n') {
				break;
			}
			else
				cout << "\t\t\t\tWrong choice!";
		}
	}
	void transferMoney() {
		getInfo();
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\t       BTL BANK" << endl;
		cout << "\t\t\t\t======================\n";
		cout << "\t\t\t\t   ::TRANSFER CASH::\n";
		cout << "\t\t\t\tRecepient Account ID: "; cin >> accID;
		ifstream file((accID + ".txt").c_str());
		try {
			if (file) { // File exsists?
				while (1) {
					cout << "\t\t\t\tEnter the amount to transfer: "; cin >> transfer;
					if (transfer > balance) {
						cout << "\t\t\t\tInsufficient balance!" << endl;
						continue;
					}
					balance = balance - transfer;
					newAccount obj(clientName, clientDOB, accountType, idStr, balance, id, pin);
					saveInfo(obj); // updating account from which money is transfered
					accountActions a;
					a.isLoggedIn = 1;
					a.checkID = accID;
					a.getInfo();
					a.balance = a.balance + transfer;
					newAccount obj1(a.clientName, a.clientDOB, a.accountType, a.idStr, a.balance, a.id, a.pin);
					saveInfo(obj1); // updating account to which money is transfered
					cout << "\t\t\t\tAmount " << transfer << " has been transfered" << endl;
					break;
				}
			}
			else
				throw runtime_error("No account exists with that ID!");
		}
		catch (exception & e) {
			cout << "\t\t\t\tException caught " << e.what() << endl;
		}
	}
};
void saveInfo(newAccount obj) {
	ofstream file((obj.idStr + ".txt").c_str());
	while (file) {
		file << obj.clientName << endl;
		file << obj.clientDOB << endl;
		file << obj.accountType << endl;
		file << obj.balance << endl;
		file << obj.id << endl;
		file << obj.pin << endl;
		break;
	}
	file.close();
}
