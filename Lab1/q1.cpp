#include<iostream>
using namespace std;

class BankAccount
{
    double *balance;

    public:
        BankAccount() : balance(new double(0.0)) {}

        BankAccount(string n, double bal) : balance(new double(bal)) {}

        BankAccount(const BankAccount& obj)
        {
            balance = new double(*(obj.balance) - 200.0);
        }

        void showDetails()
        {
            cout << "Balance : " << *balance << endl;
        }

        ~BankAccount()
        {
            delete balance;
        }
};

int main()
{
    BankAccount account1;
    cout << "Account 1 Details " << endl;
    account1.showDetails();

    BankAccount account2("Account2", 1000.0);
    cout << "Account 2 Details " << endl;
    account2.showDetails();

    BankAccount account3 = account2;
    cout << "Account 3 Details " << endl;
    account3.showDetails();

    cout << "Unchanged Account 2 Details " << endl;
    account2.showDetails();
}
