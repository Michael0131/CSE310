#include <iostream>
#include "Calculator.h"

int main() {
    Calculator calc;
    bool running = true;
    int choice;
    double num1, num2;

    while (running) {
        std::cout << "Calculator Menu:\n";
        std::cout << "1. Add\n";
        std::cout << "2. Subtract\n";
        std::cout << "3. Multiply\n";
        std::cout << "4. Divide\n";
        std::cout << "5. Show History\n";
        std::cout << "6. Save History\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice >= 1 && choice <= 4) {
            std::cout << "Enter two numbers: ";
            std::cin >> num1 >> num2;

            try {
                switch (choice) {
                    case 1: calc.add(num1, num2); break;
                    case 2: calc.subtract(num1, num2); break;
                    case 3: calc.multiply(num1, num2); break;
                    case 4: calc.divide(num1, num2); break;
                }
            } catch (const std::invalid_argument& e) {
                std::cerr << e.what() << std::endl;
            }
        } else if (choice == 5) {
            calc.showHistory();
        } else if (choice == 6) {
            calc.saveHistoryToFile("history.txt");
        } else if (choice == 7) {
            running = false;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
