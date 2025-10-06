#include "BankAccount.h"
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

std::string getCurrentDate() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);
    std::stringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d");
    return ss.str();
}

BankAccount::BankAccount(int accNum, const std::string& name, double initialBalance)
    : accountNumber(accNum), holderName(name), balance(initialBalance) {
    if (initialBalance > 0) {
        Transaction initial;
        initial.date = getCurrentDate();
        initial.type = "Initial Deposit";
        initial.amount = initialBalance;
        initial.balanceAfter = balance;
        transactions.push_back(initial);
    }
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        Transaction deposit;
        deposit.date = getCurrentDate();
        deposit.type = "Deposit";
        deposit.amount = amount;
        deposit.balanceAfter = balance;
        transactions.push_back(deposit);
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        Transaction withdrawal;
        withdrawal.date = getCurrentDate();
        withdrawal.type = "Withdrawal";
        withdrawal.amount = -amount;
        withdrawal.balanceAfter = balance;
        transactions.push_back(withdrawal);
    }
}

double BankAccount::getBalance() const {
    return balance;
}

void BankAccount::exportStatement(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Account Number: " << accountNumber << "\n";
        file << "Holder Name: " << holderName << "\n";
        file << "Current Balance: " << std::fixed << std::setprecision(2) << balance << "\n";
        file << "Date,Type,Amount,Balance After\n";
        for (const auto& transaction : transactions) {
            file << transaction.date << "," << transaction.type << ","
                 << std::fixed << std::setprecision(2) << transaction.amount << ","
                 << std::fixed << std::setprecision(2) << transaction.balanceAfter << "\n";
        }
    }
}