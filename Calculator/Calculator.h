#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <vector>
#include <string>

class Calculator {
private:
    std::vector<std::string> history;  // Vector to store history of operations

public:
    void add(double a, double b);
    void subtract(double a, double b);
    void multiply(double a, double b);
    void divide(double a, double b);
    void showHistory() const;
    void saveHistoryToFile(const std::string& filename) const;
};

#endif
