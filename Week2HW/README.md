# Week2_ProgrammingHW

This repository contains a C++ program that allows you to:
1. Check whether a string is a palindrome (ignores spaces and is case-insensitive).
2. Swap adjacent letters in a string, handling even-length and odd-length strings slightly differently.
3. Exit the program once you’re done.

Below you’ll find a detailed overview of how the program works, what it does, and how to load it into Visual Studio Community. There are also notes on the C++ compiler packages needed.

---

## Table of Contents
1. [Program Overview](#program-overview)  
2. [Features Explained](#features-explained)  
   - [Palindrome Checker](#palindrome-checker)  
   - [Letter Swapper](#letter-swapper)  
3. [Prerequisites](#prerequisites)  
4. [Loading into Visual Studio Community](#loading-into-visual-studio-community)  
5. [Running the Application](#running-the-application)  
6. [How the Code Works](#how-the-code-works)  
7. [License](#license)

---

## Program Overview

When you run the program, you’ll be presented with a simple menu:
- **Option 1:** Check if a string is a palindrome.  
- **Option 2:** Swap adjacent letters in a string.  
- **Option 3:** Exit the program.

The code demonstrates fundamental string manipulation techniques:
- **Palindrome Checking:** Uses two-pointer logic to compare letters from the start and end, ignoring spaces and case.
- **Letter Swapping:** Performs a swap of neighboring characters, with even-length and odd-length strings handled separately.

---

## Features Explained

### Palindrome Checker
1. Prompts you for a string.
2. Ignores any non-alphabetic characters (like spaces or punctuation) by moving pointers inward until valid letters are found.
3. Compares the characters at the start and end of the string in a case-insensitive manner.
4. Notifies you whether the string is a palindrome or not, and allows multiple checks.

### Letter Swapper
1. Prompts you for a word.
2. Checks the length of the word:
   - **Even length:** Swaps every pair of adjacent characters.
   - **Odd length:** Swaps every pair of adjacent characters but leaves the last character in place.
3. Displays the result of the swapping, with the option to process more words.

---

## Prerequisites

1. **Visual Studio Community (2019 or later)**  
   - During installation, ensure the **Desktop development with C++** workload is selected.  
   - This includes the MSVC (Microsoft Visual C++) toolset and CMake support if needed.

2. **C++ Compiler / Toolset**  
   - By installing the Desktop development with C++ workload, you’ll already have the compiler and necessary libraries on Windows.  

3. **Git (Optional)**  
   - If you wish to clone this repository directly, install Git from [https://git-scm.com/](https://git-scm.com/).

---

## Loading into Visual Studio Community

1. **Clone or Download**  
   - If you use Git, open a terminal and run:  
     ```bash
     git clone https://github.com/YourUsername/Week2_ProgrammingHW.git](https://github.com/jliu153/cpe593ws_2025Spring.git
     ```  
   - Alternatively, use the **Code** button on GitHub to download the ZIP file, then extract it to a folder of your choice.

2. **Open the Solution**  
   1. Launch Visual Studio Community.  
   2. Click on **File** → **Open** → **Project/Solution…**.  
   3. Navigate to the folder where you cloned or downloaded this repository.  
   4. Select the `Week2_ProgrammingHW.sln` file and click **Open**.

3. **Verify Project Structure**  
   - In the **Solution Explorer**, you should see:  
     - References and External Dependencies  
     - **Header Files**  
     - **Resource Files**  
     - **Source Files**, containing `HW2_Eschete.cpp`

---

## Running the Application

Once the solution is loaded successfully:
1. Make sure `HW2_Eschete.cpp` is selected as the startup file if necessary (by right-clicking on the file and selecting **Set as Startup Item**).
2. Press the green **Run** button (or press **F5** on your keyboard).  
3. In the **Output** or **Console** window, you will see the program’s menu.  
4. Follow the on-screen prompts to interact with the palindrome checker or letter swapper.  

You can re-run and test multiple inputs as prompted until you choose to exit.

---

## How the Code Works

1. **`main()` Function and Menu**  
   - Prompts you to choose between checking a palindrome, performing a letter swap, or exiting.
   - Uses a `do-while` loop to keep showing the menu until you select option **3**.

2. **`is_palindrome()` Function**  
   - Reads a string (`processed_word`) from the user.  
   - Uses a two-pointer approach: one pointer at the start, one at the end.  
   - Ignores non-alphabetic characters by moving each pointer inward until a valid character is found.  
   - Compares characters case-insensitively via `tolower()`.  
   - Prints a message indicating if the string is a palindrome.
   - Offers a prompt to check another word (repeats until user enters "n").

3. **`letter_swap()` Function**  
   - Reads a string (`processed_word`) from the user.  
   - Checks if the length is odd or even.  
   - Calls `odd_swap()` for odd lengths or `even_swap()` for even lengths.  
   - Each swap function processes pairs of characters and prints the transformed string.  
   - Allows the user to process more words (repeats until user enters "n").

4. **`odd_swap()` and `even_swap()`**  
   - These functions demonstrate an important distinction:  
     - **Odd length:** The last character remains unchanged.  
     - **Even length:** Every character has a partner to swap with.  
   - Both functions print intermediate output, showing the processing steps and final swapped string.

---
