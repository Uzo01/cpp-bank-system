#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>
#include <vector>

struct Transaction {
    std::string date;
    std::string type;
    double amount;
    double balanceAfter;
};

class BankAccount {
private:
    int accountNumber;
    std::string holderName;
    double balance;
    std::vector<Transaction> transactions;

public:
    BankAccount(int accNum, const std::string& name, double initialBalance = 0.0);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    int getAccountNumber() const { return accountNumber; }
    std::string getHolderName() const { return holderName; }
    void exportStatement(const std::string& filename) const;
};

#endif // BANKACCOUNT_H