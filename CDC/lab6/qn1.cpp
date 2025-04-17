#include <iostream>
#include <cstring>
#include <stack>
#include <cstdlib>

using namespace std;

int main() {
    char input[20], parsingTable[5][6][4] = {
        {"tb", " ", " ", "tb", " ", " "},
        {" ", "+tb", " ", " ", "n", "n"},
        {"fc", " ", " ", "fc", " ", " "},
        {" ", "n", "*fc", "n", "n", "n"},
        {"i", " ", " ", "(e)", " ", " "}
    };
    int tableSize[5][6] = {
        {2, 0, 0, 2, 0, 0},
        {0, 3, 0, 0, 1, 1},
        {2, 0, 0, 2, 0, 0},
        {0, 1, 3, 0, 1, 1},
        {1, 0, 0, 3, 0, 0}
    };

    cout << "Enter the input string: ";
    cin >> input;
    strcat(input, "$");

    int inputLen = strlen(input);
    stack<char> parseStack;
    parseStack.push('$');
    parseStack.push('e');

    int inputIndex = 0;
    cout << "Stack\t\tInput\n";
    cout << "_________________________\n";

    while (!parseStack.empty() && input[inputIndex] != '$') {
        char top = parseStack.top();
        char currentInput = input[inputIndex];

        if (top == currentInput) {
            parseStack.pop();
            inputIndex++;
        } else {
            int row, col;
            switch (top) {
                case 'e': row = 0; break;
                case 'b': row = 1; break;
                case 't': row = 2; break;
                case 'c': row = 3; break;
                case 'f': row = 4; break;
                default: cout << "\nERROR"; exit(0);
            }
            switch (currentInput) {
                case 'i': col = 0; break;
                case '+': col = 1; break;
                case '*': col = 2; break;
                case '(': col = 3; break;
                case ')': col = 4; break;
                case '$': col = 5; break;
                default: cout << "\nERROR"; exit(0);
            }

            if (parsingTable[row][col][0] == '\0') {
                cout << "\nERROR";
                exit(0);
            } else {
                parseStack.pop();
                if (parsingTable[row][col][0] != 'n') {
                    for (int k = tableSize[row][col] - 1; k >= 0; k--)
                        parseStack.push(parsingTable[row][col][k]);
                }
            }
        }

        // Display stack contents
        stack<char> tempStack = parseStack;
        string stackContent;
        while (!tempStack.empty()) {
            stackContent = tempStack.top() + stackContent;
            tempStack.pop();
        }
        cout << stackContent << "\t\t";

        // Display remaining input
        cout << (input + inputIndex) << "\n";
    }

    cout << "\nSUCCESS\n";
    return 0;
}

