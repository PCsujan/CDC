#include <iostream>
#include <string>

int count_operators(const std::string &expression) {
    int count = 0;
    for (char ch : expression) { // Loop through each character in the string
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                count++;
                break;
            default:
                break;
        }
    }
    return count;
}

int main() {
    std::string expression;

    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression); // Read the entire input as a string

    int count = count_operators(expression);
    std::cout << "The number of operators in the given expression is " << count << std::endl;

    return 0;
}

