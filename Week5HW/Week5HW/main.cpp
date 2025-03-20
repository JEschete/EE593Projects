/*
Name: Jude Eschete
Course: CPE593
Assignment: Week 5 Homework
Date: 02/25/2025

Statement of Originality:
All algorithmic functionality in this code was written without any outside assistance.
The only external tool used was ChatGPT, which assisted in ONLY generating the README file, code comments, 
this statement, and the wrapper menu allowing the user to select which problem to demonstrate.
No external code was used or referenced for implementing the algorithms themselves.
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// =================== Heap Functions =====================

// Maintains the max-heap property for the subtree rooted at index i.
void maxHeapify(vector<int>& arr, int n, int i) {
    int largest = i;          // Initialize largest as root
    int left = 2 * i + 1;       // left child index
    int right = 2 * i + 2;      // right child index

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// Builds a max heap from an unsorted array.
void buildMaxHeap(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// Performs heapsort on the array (results in increasing order).
void heapSort(vector<int>& arr) {
    int n = arr.size();
    buildMaxHeap(arr);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// =================== Binary Search Tree (BST) =====================

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Inserts a key into the BST.
Node* insertBST(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else if (key > root->data)
        root->right = insertBST(root->right, key);
    return root;
}

// Helper: Collects in-order traversal values into a vector.
void inorderCollect(Node* root, vector<int>& result) {
    if (!root)
        return;
    inorderCollect(root->left, result);
    result.push_back(root->data);
    inorderCollect(root->right, result);
}

// Helper: Collects pre-order traversal values into a vector.
void preorderCollect(Node* root, vector<int>& result) {
    if (!root)
        return;
    result.push_back(root->data);
    preorderCollect(root->left, result);
    preorderCollect(root->right, result);
}

// Helper to find the node with minimum value in the BST.
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

// Deletes a node with the given key from the BST.
Node* deleteNode(Node* root, int key) {
    if (!root)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Frees all nodes in the BST.
void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

// =================== Utility Functions =====================

// Parses a string containing numbers separated by spaces or commas.
vector<int> parseInput(const string& input) {
    vector<int> numbers;
    string modified = input;
    for (auto& ch : modified) {
        if (ch == ',')
            ch = ' ';
    }
    istringstream iss(modified);
    int num;
    while (iss >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

// Prints a vector of integers with commas in between.
void printVector(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if (i != vec.size() - 1)
            cout << ", ";
    }
    cout << "\n";
}

// =================== Main Function with Menu =====================
int main() {
    int choice;
    Node* bstRoot = nullptr;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Build Max Heap\n";
        cout << "2. Heapsort\n";
        cout << "3. Build Binary Search Tree (In-order Traversal)\n";
        cout << "4. Delete a Value from BST (Pre-order Traversal)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline character from input buffer

        if (choice == 1) {
            cout << "Enter numbers (separated by commas or spaces): ";
            string line;
            getline(cin, line);
            vector<int> arr = parseInput(line);
            buildMaxHeap(arr);
            cout << "Max Heap: ";
            printVector(arr);
        }
        else if (choice == 2) {
            cout << "Enter numbers (separated by commas or spaces): ";
            string line;
            getline(cin, line);
            vector<int> arr = parseInput(line);
            heapSort(arr);
            cout << "Heapsort (in increasing order): ";
            printVector(arr);
        }
        else if (choice == 3) {
            if (bstRoot != nullptr) {
                freeTree(bstRoot);
                bstRoot = nullptr;
            }
            cout << "Enter numbers (distinct integers, separated by commas or spaces): ";
            string line;
            getline(cin, line);
            vector<int> numbers = parseInput(line);
            for (int num : numbers) {
                bstRoot = insertBST(bstRoot, num);
            }
            vector<int> inorderResult;
            inorderCollect(bstRoot, inorderResult);
            cout << "In-order Traversal of BST: ";
            printVector(inorderResult);
        }
        else if (choice == 4) {
            if (bstRoot == nullptr) {
                cout << "BST is empty. Build BST first using option 3.\n";
            }
            else {
                cout << "Enter value to delete: ";
                int val;
                cin >> val;
                cin.ignore();
                bstRoot = deleteNode(bstRoot, val);
                vector<int> preorderResult;
                preorderCollect(bstRoot, preorderResult);
                cout << "Pre-order Traversal of BST after deletion: ";
                printVector(preorderResult);
            }
        }
        else if (choice == 5) {
            cout << "Exiting program.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    if (bstRoot != nullptr)
        freeTree(bstRoot);

    return 0;
}
