#ifndef BANKINGGUI_H
#define BANKINGGUI_H

#include "BankManager.h"
#include "imgui.h"
#include <GLFW/glfw3.h>
#include <string>

class BankingGUI {
private:
    BankManager bankManager;
    // Buffers for input fields
    char accNumBuffer[32];
    char nameBuffer[64];
    float initialBalance;
    char fromAccBuffer[32];
    char toAccBuffer[32];
    float amount;
    char filenameBuffer[64];
    std::string statusMessage; // For displaying success/error messages

public:
    BankingGUI();
    void render(); // Render the ImGui menu
    void setStatusMessage(const std::string& message);
};

#endif // BANKINGGUI_H