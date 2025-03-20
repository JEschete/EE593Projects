#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Node structure for the binary tree.
struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Q1: Build a minimal height tree by selecting the middle element as the root.
Node* buildMinimalHeightTree(const vector<int>& arr, int start, int end) {
    if (start > end)
        return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildMinimalHeightTree(arr, start, mid - 1);
    root->right = buildMinimalHeightTree(arr, mid + 1, end);
    return root;
}

// Helper function to calculate tree height.
int getTreeHeight(Node* root) {
    if (!root)
        return 0;
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

// Q2: Validate if the tree is a BST using a recursive min/max approach.
bool validateBSTUtil(Node* root, int minVal, int maxVal) {
    if (!root)
        return true;
    if (root->data < minVal || root->data > maxVal)
        return false;
    return validateBSTUtil(root->left, minVal, root->data - 1) &&
        validateBSTUtil(root->right, root->data + 1, maxVal);
}

bool validateBST(Node* root) {
    return validateBSTUtil(root, INT_MIN, INT_MAX);
}

// Q3: In a BST, print all elements in the range [k1, k2] using an optimized in-order traversal.
void printRange(Node* root, int k1, int k2) {
    if (!root)
        return;
    if (root->data > k1)
        printRange(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << " ";
    if (root->data < k2)
        printRange(root->right, k1, k2);
}

// Q4: Find the first common ancestor of two nodes with values k1 and k2 in a binary tree.
Node* firstCommonAncestor(Node* root, int k1, int k2) {
    if (!root)
        return nullptr;
    if (root->data == k1 || root->data == k2)
        return root;
    Node* left = firstCommonAncestor(root->left, k1, k2);
    Node* right = firstCommonAncestor(root->right, k1, k2);
    if (left && right)
        return root;
    return left ? left : right;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter " << n << " unique integers (preferably in sorted order for BST properties):\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Build the minimal height tree.
    Node* root = buildMinimalHeightTree(arr, 0, n - 1);
    int height = getTreeHeight(root);
    cout << "Tree height: " << height << "\n";

    // Validate if the tree is a BST.
    if (validateBST(root)) {
        cout << "The tree is a binary search tree.\n";

        // Q3: Print elements within a given range.
        int k1, k2;
        cout << "Enter two keys for range query (k1 and k2, where k1 <= k2): ";
        cin >> k1 >> k2;
        cout << "Elements in the range [" << k1 << ", " << k2 << "]: ";
        printRange(root, k1, k2);
        cout << "\n";
    }
    else {
        cout << "The tree is not a binary search tree. Skipping range query.\n";
    }

    // Q4: Find and print the first common ancestor of two given nodes.
    int key1, key2;
    cout << "Enter two keys to find their first common ancestor: ";
    cin >> key1 >> key2;
    Node* ancestor = firstCommonAncestor(root, key1, key2);
    if (ancestor)
        cout << "First common ancestor of " << key1 << " and " << key2 << " is: " << ancestor->data << "\n";
    else
        cout << "One or both keys were not found in the tree.\n";

    return 0;
}
