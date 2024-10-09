#include <iostream>
#include <string>
#include <algorithm>
#include <limits>  
#include "Calculator.h"

void centerScreen() {
    system("clear");  // Clears the screen (use "cls" for Windows)
    
    // Add padding to move the text upwards (10 blank lines in this example)
    for (int i = 0; i < 10; ++i) {
        std::cout << "\n";
    }
}


void displayMenu() {
    std::cout << "\nCalculator Menu:\n";
    std::cout << "1. Add\n";
    std::cout << "2. Subtract\n";
    std::cout << "3. Multiply\n";
    std::cout << "4. Divide\n";
    std::cout << "5. Show History\n";
    std::cout << "6. Save History\n";
    std::cout << "Enter 'exit' or -1 to exit\n";
}

int main() {
    Calculator calc;
    std::string choice;
    double num1, num2;

    centerScreen();

    displayMenu();  // Show the menu once at the start

    while (choice != "exit" && choice != "-1") {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);  // Get the user's menu choice (whole line)

        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);  // Convert choice to lowercase

        if (choice == "1" || choice == "add") {
            std::cout << "Number 1: ";
            std::cin >> num1;
            std::cout << "Number 2: ";
            std::cin >> num2;
            calc.add(num1, num2);  // Call the add method in the Calculator class
        } else if (choice == "2" || choice == "subtract") {
            std::cout << "Number 1: ";
            std::cin >> num1;
            std::cout << "Number 2: ";
            std::cin >> num2;
            calc.subtract(num1, num2);  // Call the subtract method
        } else if (choice == "3" || choice == "multiply") {
            std::cout << "Number 1: ";
            std::cin >> num1;
            std::cout << "Number 2: ";
            std::cin >> num2;
            calc.multiply(num1, num2);  // Call the multiply method
        } else if (choice == "4" || choice == "divide") {
            std::cout << "Number 1: ";
            std::cin >> num1;
            std::cout << "Number 2: ";
            std::cin >> num2;
            calc.divide(num1, num2);  // Call the divide method
        } else if (choice == "5" || choice == "show" || choice == "history") {
            calc.showHistory();  // Call showHistory to display the history
        } else if (choice == "6" || choice == "save") {
            calc.saveHistoryToFile("history.txt");  // Save history to a file
            std::cout << "Press 'Enter' to Continue\n";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    }

    std::cout << "Exiting the calculator.\n";
    return 0;
}
