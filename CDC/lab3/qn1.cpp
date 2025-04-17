#include <iostream>
#include <cctype>
#include <string>

int main() {
    std::string a; // Using std::string for the identifier
    bool flag = true; // Boolean flag to track validity

    std::cout << "Enter an identifier: ";
    std::cin >> a; // Read the input identifier

    // Check the first character
    if (isalpha(a[0]) || a[0] == '_') {
        flag = true;
    } else {
        flag = false;
    }

    // Check the remaining characters
    for (size_t i = 1; i < a.length(); i++) {
        if (!isdigit(a[i]) && !isalpha(a[i]) && a[i] != '_') {
            flag = false;
            break;
        }
    }

    // Output the result
    if (flag) {
        std::cout << "Valid identifier" << std::endl;
    } else {
        std::cout << "Not a valid identifier" << std::endl;
    }

    return 0;
}

