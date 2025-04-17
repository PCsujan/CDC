#include <iostream>
#include <string>

int main() {
    std::string com;
    bool isComment = false;

    std::cout << "Enter comment: ";
    std::cin >> com; // Read the input comment

    if (com[0] == '/') { // Check if the first character is '/'
        if (com[1] == '/') {
            std::cout << "It is a comment" << std::endl;
            isComment = true;
        } else if (com[1] == '*') {
            for (size_t i = 2; i < com.length() - 1; i++) { // Loop through the string
                if (com[i] == '*' && com[i + 1] == '/') {
                    std::cout << "It is a comment" << std::endl;
                    isComment = true;
                    break;
                }
            }
            if (!isComment) {
                std::cout << "It is not a comment" << std::endl;
            }
        } else {
            std::cout << "It is not a comment" << std::endl;
        }
    } 

    return 0;
}

