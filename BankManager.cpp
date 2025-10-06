#include "BankManager.h"
#include <algorithm>
#include <stdexcept>

void BankManager::createAccount(int accNum, const std::string& name, double initialBalance) {
    if (findAccount(accNum) != nullptr) {
        throw std::runtime_error("Account number already exists.");
    }
    if (initialBalance < 0) {
        throw std::invalid_argument("Initial balance cannot be negative.");
    }
    accounts.emplace_back(accNum, name, initialBalance);
}

BankAccount* BankManager::findAccount(int accNum) {
    auto it = std::find_if(accounts.begin(), accounts.end(),
                           [accNum](const BankAccount& acc) { return acc.getAccountNumber() == accNum; });
    return (it != accounts.end()) ? &(*it) : nullptr;
}

void BankManager::transferFunds(int fromAcc, int toAcc, double amount) {
    BankAccount* from = findAccount(fromAcc);
    BankAccount* to = findAccount(toAcc);
    if (!from || !to) {
        throw std::runtime_error("One or both accounts not found.");
    }
    if (amount <= 0) {
        throw std::invalid_argument("Transfer amount must be positive.");
    }
    from->withdraw(amount);
    to->deposit(amount);
}