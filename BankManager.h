#ifndef BANKMANAGER_H
#define BANKMANAGER_H

#include "BankAccount.h"
#include <vector>
#include <string>

class BankManager {
private:
    std::vector<BankAccount> accounts;

public:
    void createAccount(int accNum, const std::string& name, double initialBalance);
    BankAccount* findAccount(int accNum);
    void transferFunds(int fromAcc, int toAcc, double amount);
};

#endif // BANKMANAGER_H