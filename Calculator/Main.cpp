#include <iostream>
#include <string>
#include <algorithm>
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
    std::string userInput;

    displayMenu();  // Show the menu once at the start

    // Loop until the user chooses to exit
    while (choice != "exit" && choice != "-1") {
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "You entered something else: " << choice << std::endl;

        // Handle the choice based on the user's input
        // if (choice == "1" || choice == "add") {
        //     std::cout << "Enter two numbers: ";
        //     std::cin >> num1 >> num2;
        //     calc.add(num1, num2);
        // } else if (choice == "2" || choice == "subtract") {
        //     std::cout << "Enter two numbers: ";
        //     std::cin >> num1 >> num2;
        //     calc.subtract(num1, num2);
        // } else if (choice == "3" || choice == "multiply") {
        //     std::cout << "Enter two numbers: ";
        //     std::cin >> num1 >> num2;
        //     calc.multiply(num1, num2);
        // } else if (choice == "4" || choice == "divide") {
        //     std::cout << "Enter two numbers: ";
        //     std::cin >> num1 >> num2;
        //     calc.divide(num1, num2);
        // } else if (choice == "5" || choice == "show" || choice == "history") {
        //     calc.showHistory();
        // } else if (choice == "6" || choice == "save") {
        //     calc.saveHistoryToFile("history.txt");
        // }

        // // Clear the input buffer after each operation
        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Exiting the calculator.\n";
    return 0;
}
