#include <iostream>
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
    std::cout << "Enter -1 to exit\n";
}

int main() {
    Calculator calc;
    int choice = 0;
    double num1, num2;

    displayMenu();  // Show the menu once at the start

    // Loop until the user chooses to exit
    while (choice != -1) {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Input validation
        if (std::cin.fail()) {
            std::cin.clear();  // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore bad input
            std::cout << "Invalid input. Please enter a valid number from the menu.\n";
            continue;  // Skip this iteration and go back to asking for input
        }

        // Handle the choice based on the user's input
        switch (choice) {
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for numbers. Try again.\n";
                } else {
                    calc.add(num1, num2);
                }
                break;

            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for numbers. Try again.\n";
                } else {
                    calc.subtract(num1, num2);
                }
                break;

            case 3:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input for numbers. Try again.\n";
                } else {
                    calc.multiply(num1, num2);
                }
                break;

            case 4:
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
                break;

            case 5:
                calc.showHistory();
                break;

            case 6:
                calc.saveHistoryToFile("history.txt");
                break;

            case -1:
                std::cout << "Exiting the calculator.\n";
                break;

            default:
                std::cout << "Invalid choice. Please select from the menu options.\n";
                break;
        }
    }

    return 0;
}
