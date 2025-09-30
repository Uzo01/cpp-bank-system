#include <iostream>
#include "BankAccount.h"

int main() {
    BankAccount account(1, "John Doe", 500.0);

    int choice;
    do {
        std::cout << "\n--- Bank Menu ---\n";
        std::cout << "1. Deposit\n";
        std::cout << "2. Withdraw\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Export Statement\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (choice == 1) {
            double amount;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            double amount;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            std::cout << "Current balance: " << account.getBalance() << "\n";
        } else if (choice == 4) {
            account.exportStatement("statement.csv");
        }

    } while (choice != 5);

    return 0;
}
