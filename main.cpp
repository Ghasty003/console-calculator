#include <iostream>
using namespace std;

class Calculator {
private:
    string operation;
    string answer;
    int firstNumber;
    int secondNumber;

    void promptUser() {
        cout << "Enter the first number:";
        cin >> firstNumber;

        cout << "Enter the second number:";
        cin >> secondNumber;

        cout << "Enter the operation (+, -, *, /):";
        cin >> operation;
    }

    int invalidOperation() {
        cout << "Invalid operation." << endl;

        return 0;
    }

    int calculate(string operate) {
        return operate == "*" ?
               firstNumber * secondNumber : operate == "/" ?
               firstNumber / secondNumber : operate == "+" ?
               firstNumber + secondNumber : operate == "-" ? firstNumber - secondNumber : invalidOperation();
    }

    void continueOperation(string ans) {
        cout << "Do you want to perform another operation? (Y/N):";

        cin >> answer;

        if (answer == "Y") {
            promptUser();
            return;
        }

        cout << "Thanks for using console calculator!";
    }

public:

    void start() {
        this->promptUser();
        cout << this->calculate(operation) << endl;
        this->continueOperation(answer);
    }

    Calculator() {
        cout << "Welcome to simple calculator" << endl;
    }
};


int main() {

    Calculator calculator = *new Calculator();

    calculator.start();

    return 0;
}
