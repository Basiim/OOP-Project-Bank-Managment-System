# OOP-Project-Bank-Managment-System
1	LIBRARIES
#include<iostream>
Used for standard input/output functions.
#include<fstream>
Used for file handling functions ifstream/ofstream.
#include<string>
Used to declare and use strings and string functions.
#include<time.h>
Used to generate random seed using srand() function.
#include<sstream>
Used for the functions “stringstream” to convert string to integer.

Concepts Used
	Inheritance.
	Polymorphism.
	Data encapsulation.
	Constructor overloading.
	Function overriding.
	Information hiding.
	Static and dynamic binding.
	Abstract class.
	Pure virtual functions.
	Friend function.
	Exception handling.
	File handling.
2	UML DIAGRAM
 
3	CLASSES
3.1	CLIENT
This is the base class for client portal. It is an abstract class with two pure virtual functions and data variables for saving client’s account data.
	Variables:
int id, pin;
	stringclientName;
	stringclientDOB;
	stringaccountType; // Savings or current
	stringidStr;
double balance;

	Functions:
virtualvoidgetInfo() = 0; // Pure virtual function
	virtualvoiddisplayInfo() = 0;
3.1.1	newAccount
This class is derived from the client class. It overwrites the pure virtual function getInfo() which inputs the data for a new account. It also has a friend function saveInfo which saves the data into a file. The multi argument constructor saves the data from the object into local variables that can then be sent to the saveInfo function.
	Functions: 
3.1.2	exsistingAccount
This class is also derived from the client class. It also overwrites the pure virtual functions and has some additional functions for an existing account.
Variables:
string line;
	stringbal, idx, p;
	intloginCheck = 0;
	boolisLoggedIn = 0;
	stringcheckID, checkPIN;
	string line is used to read a string from a file and save it in a local variable using the getline() function.
	Strings bal, idx, p are used to store the strings read from the file which will then be converted to integers using stringstream.
	int loginCheck is a counter used to check if PIN and ID entered while login are correct.
	bool isLoggedIn is a check used to determine if user has logged in before accessing any function.
	Strings checkID and checkPIN are used to compare with the PIN and ID stored in the file as the data stored in the file is a string.
	 	This function inputs ID and PIN from the user and opens the file with that ID. The function then reads the file using getline() function and if ID or PIN that was entered by the user is found in the file it increases the loginCheck variable. Then in an exception if loginCheck is 2 meaning both ID and PIN was found in the function the account is logged in and its data is read and saved in local variables.

	  	First of all this function checks if the user is logged in before accessing this function. It then opens the file with user’s ID and reads the data from the file. As the data is written in the file in order being
1.	Client Name
2.	Client DOB
3.	Account Type
4.	Balance
5.	ID
6.	PIN
The function reads each of the line in every iteration of loop and stores it in correct local variable. 
As the balance, ID and PIN are stored as strings in a file. But for use in functions we need them in integers so we convert strings into integers using stringstream.

	 	This function displays the account details of a client.
3.1.3	accountActions
This class is derived from exsistingAccount class and contains the main functions used by the client.
	Variables:
float withdraw;
float deposit;
	float transfer;
	stringaccID;
charchoice;
	float withdraw and deposit are used to withdraw and deposit money from an account.
	float transfer is used to transfer money from one account to another account.
	String accID is used to input the ID of recipient for transfer of money.
	char choice is used to confirm deletion of account from the user.

Functions:
 	This function inputs the amount to withdraw from the user account. If the amount entered is more than user’s balance it gives an error else, it subtracts the withdrawn amount from the balance and save the data in the user file.
 
This function inputs the amount of deposit to the user account. The deposit money added into the current balance and shows a message that amount has been deposited to your account and save the data in the user file.

 
        This function is for deleting the account. Firstly, it asks the user to delete or not after that if the answer is yes it will remove the file of that user. If the choice is No the file isn’t deleted and continues.

  
        This function is used to transfer money. It asks the user for recipient ID and if an account exist with that ID it asks the user to enter the amount to transfer. If the amount is more than balance it gives an error else it deducts that amount from the account and saves it. The function then creates a new object and loads data of recipient and adds the transferred amount to recipient balance and saves it.
3.1.3.1	Friend Function
 

		This function is for saving the information. It takes the object of new account as input and saves that object into the file named ID of that user.

3.2	MANAGER
This is the base class for employee portal.
Variables:	
string name, username, password;
Functions: 
This class contains basic getData() and putData() functions.
3.2.1	Employee
	Variables:
int emp_id, login_check = 0;
	string emp_post, check_username, check_pass, line;
	bool isEmpLoggedIn = 0;	
	bool isManager = 0;
Functions:
 
	This function is for getdata and putdata. In getdata it asks to Enter employee post and randomly generates the id of employee through srand(). It also called the object of employee and  saves username and password in saveEmployeeinfo. In putdata function it shows the employee id and employee post. 
  
	This function is for employee login. It asks the user to put the username and password. It checks both username and password if its correct 
3.2.2	managerFunctions
	Variables:
	Int book_id;
	char choice;
	string user_delete, line;
	string line is used to read a string from a file and save it in a local variable using the getline() function.
	Char choice is used to confirm deletion of account.

Functions:
  
	This function is for showing the client data. Firstly, it checks that the employee is logged in or not. If the employee is logged in it asks the user to put Client ID. If that Id exist, it loads the data of that ID and display the information of that client. If user puts the wrong ID then error occurs that Exception caught No account exists with that ID it also gives error if the employee is not logged in. 

  
	This function is for removing the Employee. This function check that employee is logged in or not if the employee is logged in it asks the user to Enter the username of employee you wants to remove. If the username exists it asks that are you sure you want to remove this employee(Y\N)?. If user choice is yes it deletes that file of employee. If the Username doesn't exist than exception throw that No employee exists with that username. If user enter wrong choice is gives message that wrong choice!.It aslo throw exception if the employee is not logged in. 
  
 	This function is for issuing a new chequebook. Firstly, it takes user id and assign him randomly generated number of chequebook. After that it gives a message that Chequebook issued to account.
   
	This function is for modifying client data. Firstly, it checks that employee is logged in or not. If the employee id is logged in it asks the user to enter the client id and load the data of that client. After that it gives choice to change the client name or client pin. If user wants to change the client name it press 1 and after changing the name object of new account is called and all the data is saved. If user choice is 2 then same process execute for Pin change and all the data saves in that file. In case of wrong Id exception caught that no account exists with that Id.
 
	This function add the new employee. Firstly it checks that the Id is logged in or not. If the id is logged in  it can access the getdata function of employee and add the new employee otherwise it throw exception that account not logged in.

3.2.2.1	Friend Function
 
		This function is for saving the information of Employee. It takes the object of employee as input and saves that object into the file named ID of that user.
4	MAIN
Main function provides a user-friendly menu with different options, client portal, employee portal, creating new account. Which further divides into sub menus containing specific options which the user can interact with.
	The concept of polymorphism is also used in the main function by using the pointer of base class to access the pure virtual functions defined in the derived classes.
	In employee portal if the user is a manager, it will give the option to add and remove and employee.
	Separate files of both, employees and clients are made to save and access their data. With username being the name of file for employee and ID of client account being the name of file for clients.


    
5	FILES EXAMPLE
Employee 
Client 
