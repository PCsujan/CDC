#include <iostream>
#include <string>

int transition(int state, char input) {
    if (state == 0 && input == 'a') return 1;
    if (state == 1 && input == 'b') return 2;
    if (state == 2 && input == 'b') return 3;
    if (state == 3 && input == 'a') return 4;
    return -1; 
}

int main() {
    int currentState = 0;
     std::string inputString ;
    std::cout<<"Enter the string: ";
    
    std::cin>>inputString;

    for (char c : inputString) {
        currentState = transition(currentState, c);

        if (currentState == -1) {
            std::cout << "String is not accepted." << std::endl;
            return 0;
        }
    }

    if (currentState == 4) {
        std::cout << "String is accepted." << std::endl;
    } else {
        std::cout << "String is not accepted." << std::endl;
    }

    return 0;
}

