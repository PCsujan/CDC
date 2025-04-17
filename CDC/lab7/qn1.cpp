#include <iostream>
#include <cstring>

using namespace std;

char input[15], stack[15];
int inputPtr = 0, stackPtr = 0, length;
char temp[2], temp2[2];

void check();

int main() {
    cout << "GRAMMAR:\n";
    cout << "E -> E + E\nE -> E / E\nE -> E * E\nE -> a / b\n";
    cout << "Enter the input symbol: ";
    cin >> input;

    cout << "\n\t Stack Implementation Table\n";
    cout << "Stack\t\tInput Symbol\t\tAction\n";
    cout << "______\t\t____________\t\t______\n";
    cout << "\n $\t\t" << input << "$\t\t\t--";

    length = strlen(input);
    string action = "Shift ";

    for (int i = 0; i < length; i++) {
        stack[stackPtr] = input[inputPtr];
        stack[stackPtr + 1] = '\0';
        input[inputPtr] = ' ';
        inputPtr++;
        cout << "\n $" << stack << "\t\t" << input << "$\t\t\t" << action + stack[stackPtr];
        check();
        stackPtr++;
    }

    return 0;
}

void check() {
    bool flag = false;
    temp2[0] = stack[stackPtr];
    temp2[1] = '\0';

    if (strcmp(temp2, "a") == 0 || strcmp(temp2, "b") == 0) {
        stack[stackPtr] = 'E';
        cout << "\n $" << stack << "\t\t" << input << "$\t\t\tE->" << temp2;
        flag = true;
    }

    if (strcmp(temp2, "+") == 0 || strcmp(temp2, "*") == 0 || strcmp(temp2, "/") == 0) {
        flag = true;
    }

    if (strcmp(stack, "E+E") == 0 || strcmp(stack, "E/E") == 0 || strcmp(stack, "E*E") == 0) {
        strcpy(stack, "E");
        stackPtr = 0;
        cout << "\n $" << stack << "\t\t" << input << "$\t\t\tE->" << temp2;
        flag = true;
    }

    if (strcmp(stack, "E") == 0 && inputPtr == length) {
        cout << "\n $" << stack << "\t\t" << input << "$\t\t\tACCEPT";
        return;
    }

    if (!flag) {
        cout << "\n" << stack << "\t\t\t" << input << "\t\tREJECT";
        return;
    }
}

