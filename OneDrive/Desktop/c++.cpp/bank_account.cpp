#include <iostream>
using namespace std;

class BankAccount
{
    public:

    string accountHolder;
    double balance;

    void deposit(double amount)
    {
        balance = balance + amount;
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "withdraw successful\n";
        }
        else
        {
            cout << "Insufficient balance\n";
        }
    }
    void displayBalance()
    {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
    }
};
int main()
{
    BankAccount account;

    account.accountHolder = "Tunnu";
    account.balance = 1000000;

    account.withdraw(3000);

    account.displayBalance();

    return 0;
}