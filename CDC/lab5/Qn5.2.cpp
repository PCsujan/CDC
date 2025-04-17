#include <iostream>
#include <vector>
#include <set>
#include <cctype>
using namespace std;

int n;
vector<string> productions;

void follow(set<char>& result, char c);
void first(set<char>& result, char c);
void addToResultSet(set<char>& result, char val);

int main() {
    cout << "Enter the number of productions: ";
    cin >> n;

    productions.resize(n);
    cout << "Enter " << n << " productions.\n"
         << "Production with multiple terms should be given as separate productions.\n";

    for (int i = 0; i < n; i++) {
        cin >> productions[i];
    }

    char c;
    cout << "Find FOLLOW of: ";
    cin >> c;

    set<char> result;
    follow(result, c);

    cout << "FOLLOW(" << c << ") = { ";
    for (char ch : result) {
        cout << ch << " ";
    }
    cout << "}\n";

    return 0;
}

void follow(set<char>& result, char c) {
    if (productions[0][0] == c) {
        addToResultSet(result, '$'); // Start symbol has '$' in FOLLOW set
    }

    for (const string& prod : productions) {
        for (size_t j = 2; j < prod.size(); j++) {
            if (prod[j] == c) {
                set<char> temp;
                if (j + 1 < prod.size()) {
                    first(temp, prod[j + 1]);
                }
                if (j + 1 == prod.size() && c != prod[0]) {
                    follow(temp, prod[0]);
                }
                result.insert(temp.begin(), temp.end());
            }
        }
    }
}

void first(set<char>& result, char c) {
    if (!isupper(c) && c != '#') {
        addToResultSet(result, c);
        return;
    }

    for (const string& prod : productions) {
        if (prod[0] == c) {
            if (prod[2] == '#' && c != prod[0]) {
                follow(result, prod[0]);
            } else if (!isupper(prod[2]) && prod[2] != '#') {
                addToResultSet(result, prod[2]);
            } else {
                first(result, prod[2]);
            }
        }
    }
}

void addToResultSet(set<char>& result, char val) {
    result.insert(val);
}

