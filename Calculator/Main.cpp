#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;
    int choice;
    double num1, num2;

    // Display a message to inform the user about the exit condition
    std::cout << "To exit, enter -1 at the menu.\n";

    // Loop until the user enters -1 to exit
    while (true) {
        // Display the menu
        std::cout << "\nCalculator Menu:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "5. Show History\n";
        std::cout << "6. Save History\n";
        std::cout << "Enter -1 to exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Exit condition: check if the user wants to quit
        if (choice == -1) {
            std::cout << "Exiting the calculator.\n";
            break;  // Exit the loop
        }

        // Perform the selected operation
        switch (choice) {
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                calc.add(num1, num2);
                break;

            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                calc.subtract(num1, num2);
                break;

            case 3:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                calc.multiply(num1, num2);
                break;

            case 4:
                std::cout << "Enter two numbers: ";
                std::cin >> num1 >> num2;
                try {
                    calc.divide(num1, num2);
                } catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << std::endl;
                }
                break;

            case 5:
                calc.showHistory();
                break;

            case 6:
                calc.saveHistoryToFile("history.txt");
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
