#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

// Function to generate assembly-like instructions
string generateAssembly(string op, string arg1, string arg2, string result) {
    string assemblyCode = "";
    
    if (op == "+") {
        assemblyCode += "MOV R0, " + arg1 + "\n";
        assemblyCode += "ADD R0, " + arg2 + "\n";
        assemblyCode += "MOV " + result + ", R0\n";
    } 
    else if (op == "-") {
        assemblyCode += "MOV R0, " + arg1 + "\n";
        assemblyCode += "SUB R0, " + arg2 + "\n";
        assemblyCode += "MOV " + result + ", R0\n";
    } 
    else if (op == "*") {
        assemblyCode += "MOV R0, " + arg1 + "\n";
        assemblyCode += "MUL R0, " + arg2 + "\n";
        assemblyCode += "MOV " + result + ", R0\n";
    } 
    else if (op == "/") {
        assemblyCode += "MOV R0, " + arg1 + "\n";
        assemblyCode += "DIV R0, " + arg2 + "\n";
        assemblyCode += "MOV " + result + ", R0\n";
    } 
    else if (op == "=") {
        assemblyCode += "MOV R0, " + arg1 + "\n";
        assemblyCode += "MOV " + result + ", R0\n";
    } 
    else {
        assemblyCode += "INVALID OPERATION\n";
    }
    
    return assemblyCode;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string op, arg1, arg2, result;
    while (inputFile >> op >> arg1 >> arg2 >> result) {
        string assemblyCode = generateAssembly(op, arg1, arg2, result);
        outputFile << assemblyCode << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Machine code successfully written to output.txt" << endl;
    
    return 0;
}
