#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <string>
#include <vector>

using namespace std;

struct Transaction {
    string date;
    string type;
    double amount;
    double balanceAfter;
};

class BankAccount{
    private:
    int accountNumber;
    string holderName;
    double balance;
    vector<Transaction> transactions;

    public:
    // Constructor
    BankAccount(int accNum, const string& name, double intialbalance = 0.0);

    // Methods
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;

    void exportStatement(const string& filename) const;


};

#endif