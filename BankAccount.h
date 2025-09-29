#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <string>

using namespace std;

class BankAccount{
    private:
    int accountNumber;
    string name;
    double balance;

    public:
    // Constructor
    BankAccount(int accNum, string accName, double intialbalance);

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
    void displayAccount();

    // Getter 

    int getAccountNumber();
};

#endif