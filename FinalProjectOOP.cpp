#include <iostream>
#include "client.h"
#include "employee.h"
using namespace std;

int main()
{
    client* ptr;
    managerFunctions obj1;
    accountActions obj2;
    char choice;
    while (1) {
        cout << "\n\n\t\t\t\t======================\n";
        cout << "\t\t\t\t  WELCOME TO BTL BANK" << endl;
        cout << "\t\t\t\t======================\n";
        cout << "\t\t\t\t    ::MAIN MENU::\n";
        cout << "\n\t\t\t\t 1. Employee Portal" << endl;
        cout << "\t\t\t\t 2. Client Portal" << endl;
        cout << "\t\t\t\t 3. Create a new account" << endl;
        cout << "\t\t\t\t 4. Exit" << endl;
        cout<<"\n\n\t\t\t\tSelect Your Option (1-4): ";
        cin >> choice;
        switch (choice) {
        case '1':
            system("CLS");
            obj1.empLogin();
            while (1) {
                if (obj1.isManager == 1) {
                    cout << "\n\t\t\t\t1. Add an employee" << endl;
                    cout << "\t\t\t\t2. Remove an employee" << endl;
                    cout << "\t\t\t\t3. Check client data" << endl;
                    cout << "\t\t\t\t4. Modify client data" << endl;
                    cout << "\t\t\t\t5. Issue checkbook" << endl;
                    cout << "\t\t\t\t6. Logout" << endl;
                    cout << "\n\n\t\t\t\tSelect Your Option (1-6): ";
                    cin >> choice;
                    switch (choice) {
                    case '1':
                        system("CLS");
                        obj1.addEmployee();
                        break;
                    case '2':
                        system("CLS");
                        obj1.removeEmployee();
                        break;
                    case '3':
                        system("CLS");
                        obj1.checkClientData();
                        break;
                    case '4':
                        system("CLS");
                        obj1.modifyClientData();
                        break;
                    case '5':
                        system("CLS");
                        obj1.issueChequeBook();
                        break;
                    case '6':
                        break;
                    default:
                        cout << "\t\t\t\tEnter valid choice" << endl;
                    }
                    if (choice == '6') {//Logout
                        obj1.isManager = 0;
                        system("CLS");
                        break;
                    }
                }
                else {
                    cout << "\t\t\t\t1. Check client data" << endl;
                    cout << "\t\t\t\t2. Modify client data" << endl;
                    cout << "\t\t\t\t3. Issue checkbook" << endl;
                    cout << "\t\t\t\t4. Logout" << endl;
                    cout << "\n\n\t\t\t\tSelect Your Option (1-4): ";
                    cin >> choice;
                    switch (choice) {
                    case '1':
                        system("CLS");
                        obj1.checkClientData();
                        break;
                    case '2':
                        system("CLS");
                        obj1.modifyClientData();
                        break;
                    case '3':
                        system("CLS");
                        obj1.issueChequeBook();
                        break;
                    case '4':
                        break;
                    default:
                        cout << "\t\t\t\tEnter valid choice" << endl;
                    }
                    if (choice == '4') {//Logout
                        system("CLS");
                        break;
                    }
                }
            }
            break;
        case '2':
            system("CLS");
            obj2.login();
            obj2.getInfo();
            while (1) {
                cout << "\n\n\t\t\t\t1. Balance inquiry" << endl;
                cout << "\t\t\t\t2. Withdraw cash" << endl;
                cout << "\t\t\t\t3. Deposit cash" << endl;
                cout << "\t\t\t\t4. Transfer cash" << endl;
                cout << "\t\t\t\t5. Delete account" << endl;
                cout << "\t\t\t\t6. Logout" << endl;
                cout <<"\n\n\t\t\t\tSelect Your Option (1-6): ";
                cin >> choice;
                switch (choice) {
                case '1':
                    system("CLS");
                    ptr = &obj2;
                    ptr->displayInfo();
                    break;
                case '2':
                    system("CLS");
                    obj2.withdrawMoney();
                    break;
                case '3':
                    system("CLS");
                    obj2.depositMoney();
                    break;
                case '4':
                    system("CLS");
                    obj2.transferMoney();
                    break;
                case '5':
                    system("CLS");
                    obj2.deleteAccount();
                case '6':
                    break;
                default:
                    cout << "\t\t\t\tEnter valid choice!" << endl;
                }
                if (choice == '6' || choice == '5') { // Have to login again if doesnt delete
                    system("CLS");
                    break;
                }
            }
            break;
        case '3':
            system("CLS");
            ptr = new newAccount;
            ptr->getInfo();
            break;
        case '4':
            exit(0);
        default:
            cout << "\t\t\t\tEnter valid choice!" << endl;
        }
    }
}
