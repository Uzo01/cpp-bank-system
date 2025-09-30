#include "BankAccount.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;


// Contructor 
BankAccount::BankAccount(int accNum, const std::string& name, double initialBalance)
    : accountNumber(accNum), holderName(name), balance(initialBalance) {}

void BankAccount::deposit(double amount){
   balance += amount;


   // log transaction
   time_t now = time(0);
   transactions.push_back({ctime(&now), "Withdraw", amount, balance});
}

void BankAccount::withdraw(double amount){
    if (amount > balance) {
        cout << "Insufficient Funds.\n";
        return;
    }
    balance -= amount;

    // log transaction
    time_t now = time(0);
    transactions.push_back({ctime(&now), "Withdraw", amount, balance});
}

double BankAccount::getBalance() const{
    return balance;
}

void BankAccount::exportStatement(const string& filename) const{
    ofstream file(filename);

    if (!file)
    {
        cerr << "Error opening file:    " << filename << "\n";
        return;
    }

    file << "Date,Type,Amount,Balance\n";
    for (const auto& t : transactions) {
        file << t.date.substr(0, t.date.size()-1) << ","  // remove newline from ctime
             << t.type << ","
             << t.amount << ","
             << t.balanceAfter << "\n";
    }

    file.close();
    std::cout << "Bank statement exported to " << filename << "\n";
}