#include <iostream>
#include <string>
#include <algorithm>
#include <limits>  // Add this to use std::numeric_limits
#include "Calculator.h"

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

    displayMenu();  // Show the menu once at the start

    while (choice != "exit" && choice != "-1") {
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice);  // Read the entire line of input

        std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

        if (choice == "1" || choice == "add") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            calc.add(num1, num2);
        } else if (choice == "2" || choice == "subtract") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            calc.subtract(num1, num2);
        } else if (choice == "3" || choice == "multiply") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            calc.multiply(num1, num2);
        } else if (choice == "4" || choice == "divide") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            calc.divide(num1, num2);
        } else if (choice == "5" || choice == "show" || choice == "history") {
            calc.showHistory();
        } else if (choice == "6" || choice == "save") {
            calc.saveHistoryToFile("history.txt");
        }

        // Clear the input buffer after each operation
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Exiting the calculator.\n";
    return 0;
}
