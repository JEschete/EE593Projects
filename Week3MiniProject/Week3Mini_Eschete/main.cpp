/*
Name: Jude Eschete
Course: CPE593
Assignment: Week 3 Homework
Date: 02/17/2025

Statement of Originality:
All algorithmic functionality in this code was written without any outside assistance.
The only external tool used was ChatGPT, which assisted in ONLY generating the README file, code comments, 
this statement, and the wrapper menu allowing the user to select which problem to demonstrate.
No external code was used or referenced for implementing the algorithms themselves.
*/

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

class SymbolBalance {
private:
    // The raw input (which may include whitespace and comments)
    string inputStr;

public:
    // Method 1: Reads user input using getline.
    void parseInput() {
        cout << "Enter expression: ";
        getline(cin, inputStr);
    }

    // Method 2: Checks if all symbols are balanced.
    // It handles (), {}, [], and block comments /* */
    bool checkSyntax() {
        stack<string> st;
        int i = 0;
        while (i < inputStr.length()) {
            char ch = inputStr[i];
            // Check for start of block comment "/*"
            if (ch == '/' && i + 1 < inputStr.length() && inputStr[i + 1] == '*') {
                st.push("/*");
                i += 2;
                continue;
            }
            // Check for end of block comment "*/"
            else if (ch == '*' && i + 1 < inputStr.length() && inputStr[i + 1] == '/') {
                if (st.empty()) {
                    cout << "EmptyStack error: Found closing symbol \"*/\" with no matching opening symbol." << endl;
                    return false;
                }
                string top = st.top();
                st.pop();
                if (top != "/*") {
                    cout << "Mismatch Error: Current symbol \"*/\" does not match popped symbol \""
                        << top << "\"." << endl;
                    return false;
                }
                i += 2;
                continue;
            }
            // Check for opening symbols: ( { [
            else if (ch == '(' || ch == '{' || ch == '[') {
                st.push(string(1, ch));
            }
            // Check for closing symbols: ) } ]
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) {
                    cout << "EmptyStack error: Found closing symbol '" << ch
                        << "' with no matching opening symbol." << endl;
                    return false;
                }
                string top = st.top();
                st.pop();
                if ((ch == ')' && top != "(") ||
                    (ch == '}' && top != "{") ||
                    (ch == ']' && top != "[")) {
                    cout << "Mismatch Error: Current symbol '" << ch
                        << "' does not match popped symbol \"" << top << "\"." << endl;
                    return false;
                }
            }
            // For other characters, no action is needed.
            i++;
        }
        // If stack is not empty, some opening symbols were not closed.
        if (!st.empty()) {
            cout << "NonEmptyStack error: Unclosed symbol \"" << st.top()
                << "\" found at end of input." << endl;
            return false;
        }
        cout << "Symbol Balanced" << endl;
        return true;
    }

    // Method 3: Converts the (comment-free) infix expression to postfix notation.
    // This method assumes the expression is balanced.
    string postfixExpress() {
        // First, remove block comments from the raw input.
        string expr = removeComments(inputStr);
        // Remove any whitespace.
        string cleanExpr;
        for (char ch : expr) {
            if (!isspace(ch))
                cleanExpr.push_back(ch);
        }

        // Now convert infix to postfix.
        // We assume that operands are single alphanumeric characters,
        // and operators include: +, -, *, /
        string output;
        stack<char> opStack;

        for (char ch : cleanExpr) {
            // If the character is an operand, add it to output.
            if (isalnum(ch)) {
                output.push_back(ch);
            }
            // If an opening bracket is encountered, push it.
            else if (ch == '(' || ch == '{' || ch == '[') {
                opStack.push(ch);
            }
            // If a closing bracket is encountered, pop until the matching opening.
            else if (ch == ')' || ch == '}' || ch == ']') {
                while (!opStack.empty() && !isOpeningBracket(opStack.top())) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                // Pop the matching opening bracket.
                if (!opStack.empty() && isOpeningBracket(opStack.top()))
                    opStack.pop();
            }
            // If an operator is encountered, process operator precedence.
            else if (isOperator(ch)) {
                while (!opStack.empty() && isOperator(opStack.top()) &&
                    precedence(opStack.top()) >= precedence(ch)) {
                    output.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(ch);
            }
            // Any other characters are ignored.
        }
        // Pop any remaining operators.
        while (!opStack.empty()) {
            output.push_back(opStack.top());
            opStack.pop();
        }
        cout << "Postfix Expression: " << output << endl;
        return output;
    }

private:
    // Helper method: Removes block comments (/* ... */) from the string.
    string removeComments(const string& str) {
        string result;
        int i = 0;
        while (i < str.length()) {
            if (i + 1 < str.length() && str[i] == '/' && str[i + 1] == '*') {
                // Skip the comment block.
                i += 2;
                while (i + 1 < str.length() && !(str[i] == '*' && str[i + 1] == '/')) {
                    i++;
                }
                i += 2; // Skip the closing "*/"
            }
            else {
                result.push_back(str[i]);
                i++;
            }
        }
        return result;
    }

    // Returns true if ch is one of our operators.
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    // Returns the precedence of the operator.
    int precedence(char op) {
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return 0;
    }

    // Returns true if ch is an opening bracket.
    bool isOpeningBracket(char ch) {
        return (ch == '(' || ch == '{' || ch == '[');
    }
};

int main() {
    char choice;
    do {
        SymbolBalance sb;
        sb.parseInput();
        // Only convert to postfix if the syntax is balanced.
        if (sb.checkSyntax()) {
            sb.postfixExpress();
        }
        cout << "Would you like to try another expression? (y/n): ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from the input buffer.
    } while (choice != 'n' && choice != 'N');
    return 0;
}
