#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

const char* FILENAME = "accounts.dat";//define file name


class BankAccount {
public:
    BankAccount(string name, int accountNumber, float balance) {
        this->name = name;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount " << amount << " deposited. New balance is " << balance << endl;
    }

    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Insufficient balance." << endl;
        } else {
            balance -= amount;
            cout << "Amount " << amount << " withdrawn. New balance is " << balance << endl;
        }
    }

    void balanceEnquiry() {
        cout << "Current balance: " << balance << endl;
    }

 void calculateSimpleInterest(float rate, int time) {
        float interest = balance * rate * time;
        cout << "Simple interest for " << time << " years at a rate of " << rate << "% per annum is: $" << interest << endl;
    }
     void saveToFile() {
        ofstream fout(FILENAME, ios::app);
        fout << name << "," << accountNumber << "," << balance << endl;
        fout.close();
    }

    string getName() const {
        return name;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    float getBalance() const {
        return balance;
    }

private:
    string name;
    int accountNumber;
    float balance;
};
void loadFromFile() {
    ifstream fin(FILENAME);
    string line;
    while (getline(fin, line)) {
        istringstream iss(line);
        string name;
        int accountNumber;
        float balance;
        getline(iss, name, ',');
        iss >> accountNumber >> balance;
        BankAccount account(name, accountNumber, balance);
    }
    fin.close();
}
// Function to display welcome message
void introduction() {
    cout << "WELCOME TO BANK MANAGEMENT SYSTEM:" << endl;
}
// Function to display main menu options
void mainmenu() {
    cout << endl;
    cout << "Mainmenu:" << endl;
    cout << "1. Create new account" << endl;
    cout << "2. Enter deposit amount" << endl;
    cout << "3. Enter withdraw amount" << endl;
    cout << "4. Balance enquiry" << endl;
    cout << "5. Calculate simple interest" << endl;
    cout << "6. Exit"<<endl;
    cout << endl;
}

int main() {
    introduction();
    mainmenu();
    loadFromFile();

    //rest of program

    int accountNumber;
    float balance;
    string name;
    char type;

    // Prompt user for input
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accountNumber;
    cout<<"\t Enter the type of the account (C/S): ";
    cin>>type;
    cout << "Enter initial balance: ";
    cin >> balance;
    cout << endl;

    // Create a new BankAccount object
    BankAccount account(name, accountNumber, balance);
    account.saveToFile();
    cout << "New account created." << endl;
    cout << "Account holder: " << name << endl;
    cout << "Account number: " << accountNumber << endl;
    cout << "Current balance: " << balance << endl;
    cout << endl;


    int option;
    float amount;

    do {
        mainmenu();
        cin >> option;

        switch (option) {
            case 1:
                cout << "Account already created." << endl;
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;

            case 4:
                account.balanceEnquiry();
                break;

            case 5:
                double principle, rate, time, interest;
            cout << "Enter the interest rate (in %): ";
            cin>> rate;
            cout << "Enter the time period (in years): ";
            cin >> time;
            cout << "Enter the principle amount: ";
            cin >> principle;

            // calculate simple interest
            interest = (principle * rate * time)/100;
            cout << "Interest earned" << fixed << setprecision(2) << interest << endl;

            break;
         case 6:
            cout << "Thank you for using Bank Management System, Goodbye!." << endl;
            break;
            default:
             cout << "Invalid choice. Please try again." << endl;
              cout<<endl;
               break;


        }

    }
     while (option != 6);

    return 0;
}



