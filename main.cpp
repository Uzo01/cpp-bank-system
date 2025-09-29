#include <iostream>
#include <string>
#include <vector>


using namespace std;

//Step 1: Create a BankAccount class 
class BankAccount{
private: 
    int accoountNumber;
    string name;
    double balance;

public:
    //constuctor 
    BankAccount(int accNum, string accName, double initialBalance){
        accoountNumber = accNum;
        name = accNum;
        balance = initialBalance;
    }

    //A place holder function 
    void displayAccount(){
        cout << "Account Number:    "  << accoountNumber << endl;
        cout << "Name:  " << name << endl;
        cout << "Balance:  $ " << balance << endl;
    }
    // Get account number (to find accounts later)
    int getAccountNumber(){
        return accoountNumber;
    }
};

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
                
                
            case 2:
                cout << "Option 2: Deposit (coming soon)\n";
                break;
            case 3:
                cout << "Option 3: Withdraw (coming soon)";
                break;
            case 4:
                cout << "Option 4: Check Balance (coming soon)\n";
                break;
            case 5:
                cout << "Option 5: Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
            
            
        }
    }while (choice != 5);

    return 0; 
}