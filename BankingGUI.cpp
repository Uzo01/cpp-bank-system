#include "BankingGUI.h"
#include <stdexcept>
#include <sstream>
#include <iomanip> // Added to provide std::setprecision

BankingGUI::BankingGUI() : initialBalance(0.0f), amount(0.0f) {
    accNumBuffer[0] = '\0';
    nameBuffer[0] = '\0';
    fromAccBuffer[0] = '\0';
    toAccBuffer[0] = '\0';
    filenameBuffer[0] = '\0';
}

void BankingGUI::setStatusMessage(const std::string& message) {
    statusMessage = message;
}

void BankingGUI::render() {
    ImGui::Begin("Banking System Menu", nullptr, ImGuiWindowFlags_AlwaysAutoResize);

    // Status message display
    if (!statusMessage.empty()) {
        ImGui::TextColored(ImVec4(1.0f, 0.5f, 0.0f, 1.0f), "%s", statusMessage.c_str());
        ImGui::Separator();
    }

    // Create Account
    if (ImGui::CollapsingHeader("Create Account")) {
        ImGui::PushID("CreateAccount");
        ImGui::InputText("Account Number", accNumBuffer, IM_ARRAYSIZE(accNumBuffer));
        ImGui::InputText("Holder Name", nameBuffer, IM_ARRAYSIZE(nameBuffer));
        ImGui::InputFloat("Initial Balance", &initialBalance, 0.0f, 1000000.0f, "%.2f");
        if (ImGui::Button("Create")) {
            try {
                int accNum = std::atoi(accNumBuffer);
                if (accNum <= 0) throw std::invalid_argument("Invalid account number.");
                bankManager.createAccount(accNum, nameBuffer, initialBalance);
                setStatusMessage("Account created successfully!");
                accNumBuffer[0] = '\0';
                nameBuffer[0] = '\0';
                initialBalance = 0.0f;
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Deposit
    if (ImGui::CollapsingHeader("Deposit")) {
        ImGui::PushID("Deposit");
        ImGui::InputText("Account Number##Deposit", accNumBuffer, IM_ARRAYSIZE(accNumBuffer));
        ImGui::InputFloat("Amount##Deposit", &amount, 0.01f, 1000000.0f, "%.2f");
        if (ImGui::Button("Deposit")) {
            try {
                int accNum = std::atoi(accNumBuffer);
                if (accNum <= 0) throw std::invalid_argument("Invalid account number.");
                BankAccount* acc = bankManager.findAccount(accNum);
                if (!acc) throw std::runtime_error("Account not found.");
                acc->deposit(amount);
                std::stringstream ss;
                ss << std::fixed << std::setprecision(2) << acc->getBalance();
                setStatusMessage("Deposit successful! New balance: " + ss.str());
                accNumBuffer[0] = '\0';
                amount = 0.0f;
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Withdraw
    if (ImGui::CollapsingHeader("Withdraw")) {
        ImGui::PushID("Withdraw");
        ImGui::InputText("Account Number##Withdraw", accNumBuffer, IM_ARRAYSIZE(accNumBuffer));
        ImGui::InputFloat("Amount##Withdraw", &amount, 0.01f, 1000000.0f, "%.2f");
        if (ImGui::Button("Withdraw")) {
            try {
                int accNum = std::atoi(accNumBuffer);
                if (accNum <= 0) throw std::invalid_argument("Invalid account number.");
                BankAccount* acc = bankManager.findAccount(accNum);
                if (!acc) throw std::runtime_error("Account not found.");
                acc->withdraw(amount);
                std::stringstream ss;
                ss << std::fixed << std::setprecision(2) << acc->getBalance();
                setStatusMessage("Withdrawal successful! New balance: " + ss.str());
                accNumBuffer[0] = '\0';
                amount = 0.0f;
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Check Balance
    if (ImGui::CollapsingHeader("Check Balance")) {
        ImGui::PushID("CheckBalance");
        ImGui::InputText("Account Number##Balance", accNumBuffer, IM_ARRAYSIZE(accNumBuffer));
        if (ImGui::Button("Check")) {
            try {
                int accNum = std::atoi(accNumBuffer);
                if (accNum <= 0) throw std::invalid_argument("Invalid account number.");
                BankAccount* acc = bankManager.findAccount(accNum);
                if (!acc) throw std::runtime_error("Account not found.");
                std::stringstream ss;
                ss << std::fixed << std::setprecision(2) << acc->getBalance();
                setStatusMessage("Account: " + acc->getHolderName() + ", Balance: " + ss.str());
                accNumBuffer[0] = '\0';
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Transfer Funds
    if (ImGui::CollapsingHeader("Transfer Funds")) {
        ImGui::PushID("TransferFunds");
        ImGui::InputText("From Account", fromAccBuffer, IM_ARRAYSIZE(fromAccBuffer));
        ImGui::InputText("To Account", toAccBuffer, IM_ARRAYSIZE(toAccBuffer));
        ImGui::InputFloat("Amount##Transfer", &amount, 0.01f, 1000000.0f, "%.2f");
        if (ImGui::Button("Transfer")) {
            try {
                int fromAcc = std::atoi(fromAccBuffer);
                int toAcc = std::atoi(toAccBuffer);
                if (fromAcc <= 0 || toAcc <= 0) throw std::invalid_argument("Invalid account number.");
                bankManager.transferFunds(fromAcc, toAcc, amount);
                setStatusMessage("Transfer successful!");
                fromAccBuffer[0] = '\0';
                toAccBuffer[0] = '\0';
                amount = 0.0f;
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Export Statement
    if (ImGui::CollapsingHeader("Export Statement")) {
        ImGui::PushID("ExportStatement");
        ImGui::InputText("Account Number##Export", accNumBuffer, IM_ARRAYSIZE(accNumBuffer));
        ImGui::InputText("Filename", filenameBuffer, IM_ARRAYSIZE(filenameBuffer));
        if (ImGui::Button("Export")) {
            try {
                int accNum = std::atoi(accNumBuffer);
                if (accNum <= 0) throw std::invalid_argument("Invalid account number.");
                BankAccount* acc = bankManager.findAccount(accNum);
                if (!acc) throw std::runtime_error("Account not found.");
                acc->exportStatement(filenameBuffer);
                setStatusMessage("Statement exported to " + std::string(filenameBuffer));
                accNumBuffer[0] = '\0';
                filenameBuffer[0] = '\0';
            } catch (const std::exception& e) {
                setStatusMessage(std::string("Error: ") + e.what());
            }
        }
        ImGui::PopID();
    }

    // Exit Button
    if (ImGui::Button("Exit")) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
    }

    ImGui::End();
}