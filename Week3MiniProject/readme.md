# SymbolBalance

SymbolBalance is a C++ console application that checks for balanced symbols in an expression and converts valid infix expressions to postfix form. It handles grouping symbols like parentheses, braces, brackets, and block comments (`/* */`). Designed for beginners, it covers input parsing, syntax validation, and postfix conversion.

## Features
- **Input Parsing:** Uses `getline(cin, inputStr)` to read entire expressions.
- **Symbol Validation:** Detects errors such as unmatched pairs, extra closing symbols, and mismatches.
- **Postfix Conversion:** Implements operator-precedence rules.
- **Interactive Looping:** Allows multiple inputs until the user exits.

## Repository Structure
```
Week3MiniProject/
├── Week3Mini_Eschete/
│   └── .vs/
│   └── Week3Mini.cac19916/x64/Debug/
├── Week3Mini_Eschete.sln
├── Week3Mini_Eschete.vcxproj
├── Week3Mini_Eschete.vcxproj.filters
├── Week3Mini_Eschete.vcxproj.user
├── main.cpp
└── readme.md
```

## Cloning the Repository
Clone the repository using:
```bash
git clone -b Eschete7179 https://github.com/jliu153/cpe593ws_2025Spring.git
```

## Building the Project in Visual Studio
1. **Open Visual Studio.**
2. **Load the Solution:** Open `Week3Mini_Eschete.sln` in the `Week3MiniProject` folder.
3. **Set Project Properties:** Confirm the correct C++ standard is applied.
4. **Compile the Code:** Use `Build > Build Solution` or `Ctrl+Shift+B`.
5. **Execute the Program:** Run with `F5` (with debugging) or `Ctrl+F5` (without debugging).

### Example Run
```plaintext
Enter expression: a+(b*c) /* comment */
Symbol Balanced
Postfix Expression: abc*+
Would you like to try another expression? (y/n):
```



