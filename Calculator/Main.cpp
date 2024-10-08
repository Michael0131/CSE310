#include <iostream>
#include <string>
#include "Calculator.h"

void displayMenu() {
    // Display the menu only once
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

    // Loop until the user chooses to exit
    while (true) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Convert choice to lowercase to handle case insensitivity
        for (auto& c : choice) {
            c = std::tolower(c);
        }

        // Exit condition: check if the user wants to quit
        if (choice == "exit" || choice == "-1") {
            std::cout << "Exiting the calculator.\n";
            break;  // Exit the loop
        }

        // Handle the choice based on the user's input
        if (choice == "1" || choice == "add") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for numbers. Try again.\n";
            } else {
                calc.add(num1, num2);
            }
        } else if (choice == "2" || choice == "subtract") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for numbers. Try again.\n";
            } else {
                calc.subtract(num1, num2);
            }
        } else if (choice == "3" || choice == "multiply") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for numbers. Try again.\n";
            } else {
                calc.multiply(num1, num2);
            }
        } else if (choice == "4" || choice == "divide") {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input for numbers. Try again.\n";
            } else {
                try {
                    calc.divide(num1, num2);
                } catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
            }
        } else if (choice == "5" || choice == "show" || choice == "history") {
            calc.showHistory();
        } else if (choice == "6" || choice == "save") {
            calc.saveHistoryToFile("history.txt");
        } else {
            std::cout << "Invalid choice. Please select from the menu options.\n";
        }
    }

    return 0;
}
