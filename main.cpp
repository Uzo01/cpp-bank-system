#include <iostream>
#include <vector>
#include "BankAccount.h"


using namespace std;

// Step 2: Menu Function
void showMenu(){
    cout <<"\n===== Bank Menu =====\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "Enter choice:  ";
}

int main(){
    vector<BankAccount> accounts; //List of all accounts
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice){
            case 1:{
                    int accNum;
                    string accName;
                    double initialBalance;

                    cout << "Enter Account Number:  ";
                    cin >> accNum;
                    cout << "Enter Name:    ";
                    cin.ignore(); // clear all input buffer
                    getline(cin, accName);
                    cout << "Enter Intial Balance:  ";
                    cin >> initialBalance;

                    BankAccount newAccount(accNum, accName, initialBalance);
                    accounts.push_back(newAccount);

                    cout << "Account created succesfully!\n";
                    break;
                    }
                
                
            case 2:{
                    int accNum;
                    double amount;
                    cout << "Enter Account Number:  ";
                    cin >> accNum;

                    bool found = false;
                    for(auto &acc : accounts){
                        if (acc.getAccountNumber() == accNum){
                            cout << "Enter deposit amount:  ";
                            cin >> amount;
                            acc.deposit(amount);
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        cout << "Account not found. \n";
                    }
                    break;
                }                
            case 3:{
                int accNum;
                double amount;
                cout << "Enter Account Number:  ";
                cin >> accNum;

                bool found = false;
                for (auto &acc : accounts){
                    if (acc.getAccountNumber() == accNum){
                        cout << "Enter withdrawal amount:   ";
                        cin >> amount;
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "Account not found. \n";
                }
                break;
            }
            case 4: {
                int accNum;
                cout << "Enter Account Number:  ";
                cin >> accNum;

                bool found = false;
                for (auto &acc : accounts){
                    if (acc.getAccountNumber() == accNum){
                        acc.displayAccount();
                        found = true;
                        break;
                    }
                }
                if (!found){
                    cout << "Account not found. \n";
                }
                break;
            }
            case 5:
                cout << "Option 5: Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            
            
        }
    }while (choice != 5);

    return 0; 
}