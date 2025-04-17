#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outputFile("intermediate_code.txt");

    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Given expression: X = a + b - c * d / e
    outputFile << "t1 = c * d" << endl;
    outputFile << "t2 = t1 / e" << endl;
    outputFile << "t3 = a + b" << endl;
    outputFile << "t4 = t3 - t2" << endl;
    outputFile << "X = t4" << endl;

    outputFile.close();

    cout << "Intermediate code successfully written to intermediate_code.txt" << endl;
    
    return 0;
}
