#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
public:
    unsigned int accNo;
    string name;
    double balance;


    BankAccount()
    {
        //Default Constructor
    }

    BankAccount(string accountName, unsigned int accountNumber, double initialBalance):
        name(accountName),
        accNo(accountNumber)
    {
        if (initialBalance >= 0)
        {
            balance = initialBalance;
        }
        else
        {
            cout << "Invalid Amount\n";
            balance = 0;
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds." << endl;
        }
    }

    void display()
    {
        cout << "Account: " << name << "\nAccount " << accNo << "\nBalance: Rs. " << balance << endl;
    }
};

int userCount = 0;            // count of user
const int maxSize = 100;      // Maximum size of the array
BankAccount account[maxSize]; // Array of Person objects

BankAccount* chooseAccount(){
    unsigned int accSearch;
    cout << "Enter the account number for searching : " << endl;
    cin >> accSearch;

    for(int i = 0; i < userCount; i++) {
        if(account[i].accNo == accSearch){
            return &account[i];
        }
    }

}

void addUser()
{

    string name;
    double initialDeposit;
    unsigned int accountNumber;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

    cout << "Enter accountNumber: ";
    cin >> accountNumber;


    if (userCount < maxSize)
    {
        account[userCount] = BankAccount(name, accountNumber, initialDeposit); // Create a new Person object
        userCount++;
    }
    else
    {
        cout << "Bank Management is full, cannot add more User." << endl;
    }
}

int main()
{

    int choice;
    double amount;

    BankAccount* obPtr;

    do
    {
        cout << "\n" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Display Account" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the user details\n";
            addUser();
            break;
        case 2:
            obPtr = chooseAccount();
            cout << "Enter deposit amount: ";
            cin >> amount;
            obPtr->deposit(amount);
            break;
        case 3:
            obPtr = chooseAccount();
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            obPtr->withdraw(amount);
            break;
        case 4:
            obPtr = chooseAccount();
            obPtr->display();
            
            
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}