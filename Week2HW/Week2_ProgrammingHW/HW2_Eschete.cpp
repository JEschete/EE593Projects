/*
Name: Jude Eschete
Course: CPE593
Assignment: Week 2 Homework
Date: 02/03/2025

Statement of Originality:
All algorithmic functionality in this code was written without any outside assistance.
The only external tool used was ChatGPT, which assisted in ONLY generating the README file, code comments, 
this statement, and the wrapper menu allowing the user to select which problem to demonstrate.
No external code was used or referenced for implementing the algorithms themselves.
*/


#include <iostream>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::tolower;
using std::isalpha;

//------------------------------------------------------------------------------
// Node class to represent each element in the linked list.
class Node {
public:
    char data;    // Holds a character.
    Node* next;   // Points to the next node in the list.

    Node(char value) : data(value), next(nullptr) {}
};

//------------------------------------------------------------------------------
// LinkedList class: Implements a singly linked list with methods for adding
// characters, checking for palindromes (using a reversed copy) and swapping
// adjacent nodes.
class LinkedList {
private:
    Node* head;   // Pointer to the first node.
    Node* tail;   // Pointer to the last node.

public:
    // Constructor: Initializes an empty list.
    LinkedList() : head(nullptr), tail(nullptr) {}

    // Destructor: Frees all nodes.
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // add: Inserts a new node with the given character at the end of the list.
    void add(char value) {
        Node* newNode = new Node(value);
        if (!head) {  // If the list is empty, newNode becomes head and tail.
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // isPalindrome: Returns true if the list (ignoring case) is a palindrome.
    // It does this by building a reversed copy and comparing node by node.
    bool isPalindrome() {
        Node* reversedHead = reverseList();
        Node* originalCurrent = head;
        Node* reversedCurrent = reversedHead;
        bool result = true;

        // Compare each corresponding node (ignoring case)
        while (originalCurrent && reversedCurrent) {
            if (tolower(originalCurrent->data) != tolower(reversedCurrent->data)) {
                result = false;
                break;
            }
            originalCurrent = originalCurrent->next;
            reversedCurrent = reversedCurrent->next;
        }

        cleanUp(reversedHead);
        return result;
    }

    // swapAdjacent: Swaps the data of every two adjacent nodes.
    // If the list has an odd number of nodes, the last node remains unchanged.
    void swapAdjacent() {
        Node* current = head;
        while (current && current->next) {
            // Swap the values stored in the current node and its neighbor.
            char temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            current = current->next->next;
        }
    }

    // toString: Converts the linked list back into a string (by concatenating
    // the characters in order).
    string toString() const {
        string result;
        Node* current = head;
        while (current) {
            result.push_back(current->data);
            current = current->next;
        }
        return result;
    }

private:
    // reverseList: Creates and returns a new linked list (as a head pointer)
    // which is the reverse of the current list. Note: this method allocates new
    // nodes.
    Node* reverseList() const {
        Node* prev = nullptr;
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->data);
            newNode->next = prev;
            prev = newNode;
            current = current->next;
        }
        return prev;
    }

    // cleanUp: Deletes all nodes in a linked list given its head pointer.
    void cleanUp(Node* nodeHead) const {
        Node* current = nodeHead;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

//------------------------------------------------------------------------------
// Function: checkPalindrome
// Description:
//   Prompts the user for a string and uses a linked list (built only from letter
//   characters) to check if the input is a palindrome (ignoring case and spaces).
//   Repeats as long as the user desires.
void checkPalindrome() {
    string input;
    string response;

    do {
        cout << "\nEnter a string to test if it is a palindrome. Spaces and non-letter characters will be ignored:" << endl;
        getline(cin, input);

        // Build the linked list with only letter characters.
        LinkedList list;
        for (char c : input) {
            if (isalpha(c)) {
                list.add(c);
            }
        }

        bool palin = list.isPalindrome();
        cout << endl;
        cout << input << (palin ? " is a palindrome." : " is not a palindrome.") << endl;
        cout << endl;

        // Ask if the user wants to test another string.
        do {
            cout << "Would you like to test another word? (y/n): ";
            getline(cin, response);
            if (response != "y" && response != "n") {
                cout << "Please only enter 'y' or 'n'." << endl;
            }
        } while (response != "y" && response != "n");

    } while (response == "y");
}

//------------------------------------------------------------------------------
// Function: processLetterSwap
// Description:
//   Prompts the user for a word, builds a linked list from every character,
//   swaps adjacent nodes, and then prints the processed word. In words of odd
//   length, the last character remains unchanged.
//   Repeats as long as the user desires.
void processLetterSwap() {
    string input;
    string response;

    do {
        cout << "\nPlease enter a word to be processed." << endl;
        cout << "Odd letter words will not swap the last letter." << endl;
        getline(cin, input);

        // Build the linked list using every character.
        LinkedList list;
        for (char c : input) {
            list.add(c);
        }

        cout << "Processing: " << input << endl;
        list.swapAdjacent();
        string swapped = list.toString();
        cout << "Swapped word: " << swapped << endl;
        cout << endl;

        // Ask if the user wants to process another word.
        do {
            cout << "Would you like to process another word? (y/n): ";
            getline(cin, response);
            if (response != "y" && response != "n") {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        } while (response != "y" && response != "n");

    } while (response == "y");
}

//------------------------------------------------------------------------------
// Main function: Displays the menu, processes user selection, and loops until
// the user chooses to exit.
int main() {
    string choice;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Check if a string is a palindrome" << endl;
        cout << "2. Swap adjacent letters in a string" << endl;
        cout << "3. Exit program" << endl;
        cout << "Select an option (1, 2, or 3): " << endl;
        getline(cin, choice);
        cout << endl;

        if (choice == "1") {
            checkPalindrome();
        }
        else if (choice == "2") {
            processLetterSwap();
        }
        else if (choice == "3") {
            cout << "Exiting program. Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }

    } while (choice != "3");

    return 0;
}
