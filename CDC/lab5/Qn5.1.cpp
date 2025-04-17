 #include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <set>
using namespace std;

int numOfProductions;
vector<string> productionSet;

void FIRST(set<char>& result, char c);
void addToResultSet(set<char>& result, char val);

int main() {
    cout << "How many number of productions?: ";
    cin >> numOfProductions;

    productionSet.resize(numOfProductions);
    for (int i = 0; i < numOfProductions; i++) {
        cout << "Enter production Number " << i + 1 << ": ";
        cin >> productionSet[i];
    }

    char choice;
    do {
        char c;
        set<char> result;

        cout << "\nFind the FIRST of: ";
        cin >> c;

        FIRST(result, c); // Compute FIRST; Result is stored in 'result' set

        cout << "\nFIRST(" << c << ") = { ";
        for (const char& ch : result) {
            cout << ch << " ";
        }
        cout << "}\n";

        cout << "Press 'y' to continue: ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void FIRST(set<char>& result, char c) {
    if (!isupper(c)) { // If X is terminal, FIRST(X) = {X}
        addToResultSet(result, c);
        return;
    }

    for (const string& production : productionSet) {
        if (production[0] == c) { // Find productions with X as LHS
            if (production[2] == '$') { // epsilon production
                addToResultSet(result, '$');
            } else {
                set<char> subResult;
                bool foundEpsilon;

                for (size_t j = 2; j < production.size(); j++) {
                    foundEpsilon = false;
                    subResult.clear();

                    FIRST(subResult, production[j]);
                    result.insert(subResult.begin(), subResult.end());

                    if (subResult.find('$') != subResult.end()) { // Check for epsilon
                        foundEpsilon = true;
                    }

                    if (!foundEpsilon) {
                        break; // No epsilon, no need to check next element
                    }
                }
            }
        }
    }
}

void addToResultSet(set<char>& result, char val) {
    result.insert(val); // Use set's built-in uniqueness
}

