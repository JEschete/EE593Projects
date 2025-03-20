# Heap and Binary Search Tree Implementation

## Overview

This C++ program provides implementations of fundamental data structures and algorithms, including:

- **Heap (Max-Heap & Heapsort)**
- **Binary Search Tree (BST) with Insert, Delete, and Traversals**
- **Menu-driven interface for user interaction**

## Features

1. **Build Max Heap** - Constructs a max heap from user input and displays it.
2. **Heapsort** - Sorts user input using heapsort and displays the result.
3. **Build a Binary Search Tree (BST)** - Allows users to insert values into a BST and outputs an in-order traversal.
4. **Delete a Value from BST** - Removes a value from the BST and outputs a pre-order traversal.
5. **Exit** - Terminates the program.

## Prerequisites

- Visual Studio (Only Visual Studio is supported)
- C++ Compiler (MSVC recommended)

## Installation & Usage

1. **Clone the repository:**
   ```sh
   git clone https://github.com/jliu153/cpe593ws_2025Spring.git
   ```
2. **Navigate to the correct branch:**
   ```sh
   cd cpe593ws_2025Spring
   git checkout Eschete7179
   ```

## Loading the Project into Visual Studio

1. **Open Visual Studio**
2. **Load the Solution File:**
   - Click on `File` → `Open` → `Project/Solution...`
   - Navigate to the project folder and select `Week5HW.sln`.
3. **Build the Project:**
   - In the `Solution Explorer`, right-click `Week5HW`.
   - Select `Build` to compile the program.
4. **Run the Program:**
   - Press `Ctrl + F5` to run the application without debugging.
   - Follow the menu prompts to interact with the program.

## Project Structure

```
Week5HW/
│── .vs/Week5HW/             # Visual Studio project settings
│── Week5HW.sln              # Visual Studio solution file
│── Week5HW.vcxproj          # Visual Studio project file
│── Week5HW.vcxproj.filters  # Project filters
│── Week5HW.vcxproj.user     # User-specific project settings
│── main.cpp                 # Source code file
│── .gitignore               # Git ignore file
```

## How to Use

1. **Run the program.**
2. **Follow the menu prompts:**
   - Enter numbers separated by spaces or commas when prompted.
   - Choose the desired operation by selecting a menu option.
3. **Exit the program by selecting option 5.**

## Code Structure

### Heap Functions

- `maxHeapify()` - Ensures the max-heap property is maintained.
- `buildMaxHeap()` - Constructs a max heap from an unsorted array.
- `heapSort()` - Sorts an array using heapsort.

### Binary Search Tree (BST) Functions

- `insertBST()` - Inserts a new value into the BST.
- `deleteNode()` - Removes a specified value from the BST.
- `inorderCollect()` - Retrieves an in-order traversal of the BST.
- `preorderCollect()` - Retrieves a pre-order traversal of the BST.
- `findMin()` - Finds the node with the smallest value in the BST.
- `freeTree()` - Frees memory used by the BST.

### Utility Functions

- `parseInput()` - Parses user input into an integer vector.
- `printVector()` - Prints a vector of numbers, formatted with commas.

## Example Usage

### Heap Example:

```
Enter numbers (separated by commas or spaces): 5, 3, 8, 1, 2
Max Heap: 8, 3, 5, 1, 2
```

### BST Example:

```
Enter numbers: 10, 5, 15, 3, 7, 12, 18
In-order Traversal of BST: 3, 5, 7, 10, 12, 15, 18
```

## Support

For any issues, use the repository's issue tracker: [GitHub Issues](https://github.com/jliu153/cpe593ws_2025Spring/issues).

