#include <iostream>

// basic calculator

int main() {
    double num1, num2;
    char operation;
    char continueCalc;

    do {
        // Input two numbers from the user
        std::cout << "Enter first number: ";
        std::cin >> num1;

        std::cout << "Enter an operator (+, -, *, /): ";
        std::cin >> operation;

        std::cout << "Enter second number: ";
        std::cin >> num2;

        // Perform the operation and display the result
        switch (operation) {
            case '+':
                std::cout << "Result: " << num1 + num2 << std::endl;
                break;
            case '-':
                std::cout << "Result: " << num1 - num2 << std::endl;
                break;
            case '*':
                std::cout << "Result: " << num1 * num2 << std::endl;
                break;
            case '/':
                if (num2 != 0) {
                    std::cout << "Result: " << num1 / num2 << std::endl;
                } else {
                    std::cout << "Error: Division by zero is undefined." << std::endl;
                }
                break;
            default:
                std::cout << "Error: Invalid operator." << std::endl;
                break;
        }

        // Ask user if they want to perform another calculation
        std::cout << "Do you want to perform another calculation? (y/n): ";
        std::cin >> continueCalc;

    } while (continueCalc == 'y' || continueCalc == 'Y');

    std::cout << "Thank you for using the calculator!" << std::endl;

    return 0;
}
