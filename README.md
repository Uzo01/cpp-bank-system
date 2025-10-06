# Banking System

A C++ desktop application implementing a banking system with a GUI built using ImGui, GLFW, and OpenGL. This project demonstrates Object-Oriented Programming (OOP) principles, modular code organization, and modern C++ (C++17) features. It is designed to showcase software development skills for a resume or portfolio.

## Features
- Create a new bank account with an account number, holder name, and initial balance.
- Deposit and withdraw funds with transaction logging.
- Check account balance.
- Transfer funds between accounts.
- Export transaction statements to a CSV file.
- User-friendly GUI with input validation and error messages.

## Project Structure
- `main.cpp`: Entry point, initializes GLFW, ImGui, and the GUI.
- `BankAccount.h/cpp`: Manages account details and transactions.
- `BankManager.h/cpp`: Handles multiple accounts and transfers.
- `BankingGUI.h/cpp`: Implements the ImGui-based menu interface.
- `imgui/`: ImGui library for GUI rendering.

## Build Instructions
### Prerequisites
- C++17 compatible compiler (e.g., g++ via MSYS2/MinGW64).
- GLFW 3.4 (included at `C:/Libraries/glfw-3.4.bin.WIN64` or install via package manager).
- CMake (optional, for cross-platform builds).

### Using VS Code
1. Ensure MSYS2/MinGW64 is installed with `g++`, `glfw`, and `opengl`.
2. Place ImGui in `imgui/` (or adjust paths in `tasks.json`).
3. Open the project in VS Code.
4. Run the "Build and Run Bank App" task (`Ctrl+Shift+B`).

### Using CMake
1. Install CMake and ensure GLFW is available.
2. Create a build directory: `mkdir build && cd build`.
3. Run: `cmake .. && cmake --build .`.
4. Execute: `./BankingSystem` (Windows: `BankingSystem.exe`).

## Dependencies
- ImGui (included in `imgui/`)
- GLFW 3.4
- OpenGL

## Future Improvements
- Add file I/O for persistent account storage.
- Implement user authentication.
- Display transaction history in the GUI.

## License
MIT License