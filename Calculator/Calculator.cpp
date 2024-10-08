#include "Calculator.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

void Calculator::add(double a, double b) {
    double result = a + b;
    std::cout << "Result: " << result << std::endl;
    history.push_back(std::to_string(a) + " + " + std::to_string(b) + " = " + std::to_string(result));
}

void Calculator::subtract(double a, double b) {
    double result = a - b;
    std::cout << "Result: " << result << std::endl;
    history.push_back(std::to_string(a) + " - " + std::to_string(b) + " = " + std::to_string(result));
}

void Calculator::multiply(double a, double b) {
    double result = a * b;
    std::cout << "Result: " << result << std::endl;
    history.push_back(std::to_string(a) + " * " + std::to_string(b) + " = " + std::to_string(result));
}

void Calculator::divide(double a, double b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    double result = a / b;
    std::cout << "Result: " << result << std::endl;
    history.push_back(std::to_string(a) + " / " + std::to_string(b) + " = " + std::to_string(result));
}

void Calculator::showHistory() const {
    std::cout << "History of operations:" << std::endl;
    for (const auto& entry : history) {
        std::cout << entry << std::endl;
    }
}

void Calculator::saveHistoryToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : history) {
            file << entry << std::endl;
        }
        file.close();
        std::cout << "History saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}
