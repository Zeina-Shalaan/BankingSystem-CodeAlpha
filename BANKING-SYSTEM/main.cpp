#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct CustomerAccount {
    string name;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string CustomerId;
    double accountBalance;
};
// Function to generate a random customer ID
string generateCustomerID() {
    // Initialize random seed
    srand(time(0));

    // Generate a random number
    int randomNumber = rand() % 10000; // Random number between 0 and 9999

    // Create customer ID with "CUS" prefix and the random number
    return "CUS" + to_string(randomNumber);
}
class BankSystem
{
public :
    // Add customer data,with balance to create account, with struct as parameter
    void CreateAccount(CustomerAccount accounts[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\nEntering data for customer " << i + 1 << ":" << endl;

        cin.ignore();

        cout << "Name: ";
        getline(cin, accounts[i].name);
        cout << endl;
        cout << "Address: ";
        getline(cin, accounts[i].address);

        cout << "City: ";
        getline(cin, accounts[i].city);

        cout << "State: ";
        getline(cin, accounts[i].state);

        cout << "ZIP: ";
        getline(cin, accounts[i].zip);

        cout << "Phone Number: ";
        getline(cin, accounts[i].phoneNumber);

        do {
            cout << "Enter Account Balance: ";
            cin >> accounts[i].accountBalance;
            if (accounts[i].accountBalance < 0)
                cout << "Account balance cannot be negative. Please enter again." << endl;
        } while (accounts[i].accountBalance < 0);

        cin.ignore(); // To ignore the newline character after the double input

        // Generate and assign a unique customer ID
        accounts[i].CustomerId = generateCustomerID();

        // Display the generated customer ID
        cout << "Generated Customer ID: " << accounts[i].CustomerId << endl;

    }
}
//function to modify data
void modifyData(CustomerAccount accounts[], int size) {
    int accountNumber;
    cout << "Enter the account number you want to modify (1-" << size << "): ";
    cin >> accountNumber;
    cin.ignore(); // To ignore the newline character after the integer input

    if (accountNumber < 1 || accountNumber > size) {
        cout << "Invalid account number." << endl;
        return;
    }

    int i = accountNumber - 1;
    cout << "\nModifying data for customer " << accountNumber << ":" << endl;

    cout << "Name (" << accounts[i].name << "): ";
    getline(cin, accounts[i].name);

    cout << "Address (" << accounts[i].address << "): ";
    getline(cin, accounts[i].address);

    cout << "City (" << accounts[i].city << "): ";
    getline(cin, accounts[i].city);

    cout << "State (" << accounts[i].state << "): ";
    getline(cin, accounts[i].state);

    cout << "ZIP (" << accounts[i].zip << "): ";
    getline(cin, accounts[i].zip);

    cout << "Phone Number (" << accounts[i].phoneNumber << "): ";
    getline(cin, accounts[i].phoneNumber);

    do {
        cout << "Account Balance (" << accounts[i].accountBalance << "): ";
        cin >> accounts[i].accountBalance;
        if (accounts[i].accountBalance < 0)
            cout << "Account balance cannot be negative. Please enter again." << endl;
    } while (accounts[i].accountBalance < 0);

    cin.ignore(); // To ignore the newline character after the double input
}

//function to add money to account
void Deposit(CustomerAccount accounts[] ,int accountNumber, int size, double AmountAdded)
{
    if (accountNumber < 1 || accountNumber > size)
    {
        cout << "Invalid account number." << endl;
        return;
    }

    int i = accountNumber - 1;
    cout << "Your Current Balance is : "<< accounts[i].accountBalance << endl;
    accounts[i].accountBalance += AmountAdded;

    cout << "Your New Balance is : " << accounts[i].accountBalance << endl;
}

//function to remove/withdrawl money from account
void Withdrawl(CustomerAccount accounts[] ,int accountNumber, int size, double AmountTaken)
{
     if (accountNumber < 1 || accountNumber > size)
    {
        cout << "Invalid account number." << endl;
        return;
    }

    int i = accountNumber - 1;
    cout << "Your Current Balance is : "<< accounts[i].accountBalance << endl;
    if (AmountTaken > accounts[i].accountBalance)
    {
        cout << "Insufficient funds , your balance is : "<<accounts[i].accountBalance << endl;
    }
    else
    {
        accounts[i].accountBalance -= AmountTaken;
    }
    cout << "Your New Balance is : " << accounts[i].accountBalance << endl;
}

// transfer money to another account
void Transfer(CustomerAccount accounts[] , int size, int fromAccountNumber, int toAccountNumber, double TransferAmount)
{
    //to check account validity
   if (fromAccountNumber < 1 || fromAccountNumber > size || toAccountNumber < 1 || toAccountNumber > size)
    {
            cout << "Invalid account number(s)." << endl;
            return;
    }

    int fromIndex = fromAccountNumber - 1;
    int toIndex = toAccountNumber - 1;

    if (accounts[fromIndex].accountBalance < TransferAmount)
    {
        cout << "Insufficient funds in the source account." << endl;
        return;
    }
    else
    {
        accounts[fromIndex].accountBalance -= TransferAmount;
        accounts[toIndex].accountBalance += TransferAmount;
    }

    cout << "Transfer successful!" << endl;
    cout << "New balance for source account (" << accounts[fromIndex].CustomerId << "): " << accounts[fromIndex].accountBalance << endl;
    cout << "New balance for destination account (" << accounts[toIndex].CustomerId << "): " << accounts[toIndex].accountBalance << endl;

}
//to show customer account data
void displayCustomerData(const CustomerAccount accounts[], int size)
{
    cout << "\n-------------------------------------------" << endl;

        cout << "|             Customer Account Data          |" << endl;
        cout << "|-------------------------------------------|" << endl;
        for (int i = 0; i < size; i++) {
            cout << "\n-------------------------------------------" << endl;
            cout << "| Customer " << i + 1 << "                          |" << endl;
            cout << "|-------------------------------------------|" << endl;
            cout << "| Name:         " << accounts[i].name << "                 |" << endl;
            cout << "| Address:      " << accounts[i].address << "          |" << endl;
            cout << "| City:         " << accounts[i].city << "               |" << endl;
            cout << "| State:        " << accounts[i].state << "              |" << endl;
            cout << "| ZIP:          " << accounts[i].zip << "                |" << endl;
            cout << "| Phone Number: " << accounts[i].phoneNumber << "      |" << endl;
            cout << "| Customer ID:  " << accounts[i].CustomerId << "          |" << endl;
            cout << "| Balance:      $" << accounts[i].accountBalance << "         |" << endl;
            cout << "|-------------------------------------------|" << endl;
        }
}
};


int main()
{
    const int size = 2;
    CustomerAccount accounts[size];
    BankSystem bank;
    int accNum,amountIN,amountOUT;
    int accNumFROM,accNumTO,amountTRANSFER;
    int choice;

    do {
    cout << "\nCustomer Account Menu" << endl;
    cout << "1. Enter new account data" << endl;
    cout << "2. Modify existing account data" << endl;
    cout << "3. Deposit into existing account " << endl;
    cout << "4. WithDrawl from account " << endl;
    cout << "5. Transfer from account to another" << endl;
    cout << "6. Display account data" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice ;
    switch (choice){
    case 1:
        bank.CreateAccount(accounts,size);
        break;
    case 2:
        bank.modifyData(accounts,size);
        break;
    case 3:
        cout << "Enter account number you want to modify (1-2) : ";
        cin >> accNum;
        cout << "Enter amount needed for deposit : ";
        cin >> amountIN;
        bank.Deposit(accounts,accNum,size,amountIN);
        break;
    case 4:
        cout << "Enter account number you want to modify (1-2) : ";
        cin >> accNum;
        cout << "Enter amount needed for withdrawl : ";
        cin >> amountOUT;
        bank.Withdrawl(accounts,accNum,size,amountOUT);
        break;
    case 5:
        cout << "Enter account number you want to transfer from (1-2) : ";
        cin >> accNumFROM;
        cout << "Enter account number you want to transfer to (1-2) : ";
        cin >> accNumTO;
        cout << "Enter amount needed for transfer : ";
        cin >> amountTRANSFER;
        bank.Transfer(accounts,size,accNumFROM,accNumTO,amountTRANSFER);
        break;
    case 6:
        bank.displayCustomerData(accounts,size);
        break;
    case 7:
        cout << "exiting program :";
        break;
    default :
    cout << "invalid choice";
    }

    }while(choice != 7);


    return 0;
}

