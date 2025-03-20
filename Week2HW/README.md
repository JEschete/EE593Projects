
# Week2_ProgrammingHW

This repository contains a C++ program that demonstrates custom pointer-based operations using a self-defined linked list data structure. The program allows you to:

1. Check whether an input string is a palindrome (ignoring spaces, punctuation, and case).
2. Swap adjacent letters in a string (handling even-length and odd-length strings appropriately).
3. Exit the program once you’re finished.

The solution meets the assignment requirements by implementing my own `Node` and `LinkedList` classes and managing memory and pointers directly rather than relying on built-in APIs.

---

## Table of Contents

1. [Program Overview](#program-overview)  
2. [Features Explained](#features-explained)  
   - [Custom Linked List and Pointer-Based Methods](#custom-linked-list-and-pointer-based-methods)  
   - [Palindrome Checker](#palindrome-checker)  
   - [Letter Swapper](#letter-swapper)  
3. [Prerequisites](#prerequisites)  
4. [Loading into Visual Studio Community](#loading-into-visual-studio-community)  
5. [Compiling and Running the Application](#compiling-and-running-the-application)  
6. [How the Code Works](#how-the-code-works)  
---

## Program Overview

When you run the program, you are presented with a simple menu:

- **Option 1:** Check if a string is a palindrome.  
- **Option 2:** Swap adjacent letters in a string.  
- **Option 3:** Exit the program.

The code demonstrates fundamental techniques in string manipulation by using custom data structures and pointer operations. It builds its own linked list to manage characters from the input, rather than using the C++ Standard Library’s container classes.

---

## Features Explained

### Custom Linked List and Pointer-Based Methods
- **Custom Data Structures:**  
  The program defines a `Node` class to store individual characters and a `LinkedList` class that manages these nodes.  
- **Pointer Manipulation:**  
  All operations—including adding nodes, reversing the list for the palindrome check, and swapping adjacent nodes—are performed by directly manipulating pointers.  
- **Memory Management:**  
  The program includes a destructor and helper functions to ensure that dynamically allocated memory is properly freed.

### Palindrome Checker
- **Input Processing:**  
  The program prompts for a string and constructs a linked list containing only the alphabetic characters (ignoring spaces and punctuation).  
- **Case-Insensitive Comparison:**  
  The palindrome check is done by creating a reversed copy of the list using pointer-based operations and comparing node by node in a case-insensitive manner.  
- **User Interaction:**  
  After displaying whether the string is a palindrome, the user is given the option to test another string.

### Letter Swapper
- **Input Processing:**  
  The program prompts for a word and builds a linked list from every character in the string.  
- **Swapping Logic:**  
  The swapping operation traverses the linked list and swaps the data of every pair of adjacent nodes. In the case of an odd-length string, the final character remains unchanged.  
- **User Interaction:**  
  The result is displayed, and the user can choose to process additional words.

---

## Prerequisites

1. **Visual Studio Community (2019 or later)**  
   - Ensure you have installed the **Desktop development with C++** workload.  
   - This includes the MSVC (Microsoft Visual C++) toolset and CMake support if needed.

2. **C++ Compiler / Toolset**  
   - With the Desktop development workload installed, the necessary compiler and libraries will be available on Windows.

3. **Git**  
   - To clone the repository, install Git from [https://git-scm.com/](https://git-scm.com/).

---

## Loading into Visual Studio Community

1. **Clone the Repository and Checkout the Correct Branch:**  
   - Open a terminal (or Git Bash) and run the following commands:
     ```bash
     git clone https://github.com/jliu153/cpe593ws_2025Spring.git
     cd cpe593ws_2025Spring
     git checkout Eschete7179
     ```
2. **Locate the Project Files:**  
   - The solution and project files are located in the folder **Week2HW** within the repository.

3. **Open the Solution:**  
   1. Launch Visual Studio Community.  
   2. Click on **File** → **Open** → **Project/Solution…**.  
   3. Navigate to the `cpe593ws_2025Spring/Week2HW` folder.  
   4. Select the solution file (e.g., `Week2HW.sln`) and click **Open**.

4. **Verify Project Structure:**  
   - In the **Solution Explorer**, you should see the project files, including the source files for the program.

---

## Compiling and Running the Application

### Using Visual Studio Community:
1. **Set the Startup File (if necessary):**  
   - Right-click on the main source file (e.g., `week2_dynamicArrays.cpp`) in the Solution Explorer and select **Set as Startup Item**.
2. **Build and Run:**  
   - Press the green **Run** button or press **F5**.  
   - The Console window will open with the program’s menu. Follow the on-screen prompts to interact with the palindrome checker or letter swapper.

---

## How the Code Works

1. **Main Function and Menu:**  
   - The `main()` function displays a menu that allows you to choose between checking for a palindrome, swapping adjacent letters, or exiting the program.  
   - A loop ensures that the menu is repeatedly shown until the user decides to exit.

2. **Palindrome Check:**  
   - The program filters the input to remove non-alphabetic characters and builds a custom linked list.  
   - It then creates a reversed copy of the linked list by dynamically allocating new nodes and reversing pointer links.  
   - A node-by-node comparison (ignoring case) determines whether the string is a palindrome.

3. **Letter Swapping:**  
   - The entire input word is added to the linked list.
   - The program traverses the list and swaps the data in every pair of adjacent nodes.  
   - If the list has an odd number of nodes, the final node remains unchanged.

4. **Memory Management:**  
   - Custom destructors and helper functions ensure that all dynamically allocated memory is released when no longer needed.

5. **User Interaction:**  
   - After each operation (palindrome checking or letter swapping), the user is prompted whether to process another input, ensuring an interactive and user-friendly experience.

## This README.md was generated with the assistance of ChatGPT o3-mini-high. Manual Edits were made for correctness. 
