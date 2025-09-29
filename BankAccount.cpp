#include "BankAccount.h"
#include <iostream>

using namespace std;


// Contructor 
BankAccount::BankAccount(int accNum, string accName, double intialbalance) {
    accountNumber = accNum;
    name = accName;
    balance = intialbalance;
}

void BankAccount::deposit(double amount){
    if (amount > 0){
        balance += amount;
        cout << "Successfully deposited $" << amount
                << ". New balance:  $" << balance << endl;
    }else{
        cout << "Invalid deposit amount. \n";
    }
}

void BankAccount::withdraw(double amount){
    if (amount > 0){
        balance += amount;
        cout << " Invalid withdrawal amount. \n";
    }else if(amount > balance){
        cout << "Insufficient funds. Current balance:   $ " << balance << endl;
    }else{
        balance -= amount;
        cout << "Successfully withdrew $" << amount
                << ". Remaining balance:    $" << balance << endl;
    }
}

void BankAccount::displayAccount(){
    cout << "\n===== Account Details =====\n";
    cout << "Account Number:    " << accountNumber << endl;
    cout << "Name:  " << name << accountNumber << endl;
    cout << "Balance:   $" << balance << endl;
    cout << "=================================\n";
}

int BankAccount::getAccountNumber(){
    return accountNumber;
}