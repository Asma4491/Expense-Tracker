# Expense-Tracker
This is a simple command-line Expense Tracker program written in C++. The program allows users to record expenses, display all recorded expenses, and summarize the total expenses. The expenses are stored in a text file called expenses.txt.

## Features
1. **Enter an expense**: Prompts the user to enter an expense description and amount, then appends it to the file along with the current date and time.
2. **Display all expenses**: Reads and displays all recorded expenses from the file.
3. **Summarize total expenses**: Calculates and displays the total amount of all recorded expenses.
4. **Exit**: Exits the program.

## Requirements
1. A C++ compiler (such as g++).

## Compilation
To compile the program, use the following command in the terminal:
```g++ expense_tracker.cpp -o expense_tracker```

This will generate an executable file named expense_tracker.

## Running the Program
To run the program, use the following command in the terminal:

```./expense_tracker```

# Code Explanation

## Libraries Used
**iostream:** For standard input and output operations.
**fstream:** For file handling operations.
**iomanip:** For formatting output.
**ctime:** For handling date and time.
**sstream:** For string stream operations.
**string:** For string operations.

## Functions
1. **getCurrentDateTime():** Returns the current date and time as a string.
2. **isValidAmount(const string &amountStr):** Validates that the amount is a valid numeric value and non-negative.
3. **appendExpense(const string &description, const string &amountStr):** Appends an expense to the file.
4. **displayExpenses():** Displays all recorded expenses from the file.
5. **summarizeExpenses():** Summarizes the total amount of all recorded expenses.

## Main Function
The main function provides a menu-driven interface for the user to interact with the program. It continuously displays the menu until the user chooses to exit.

```cpp
int main() {
  while (true) {
    cout << endl << "Expense Tracker Menu:\n"; // Added line space before menu
    cout << "1. Enter an expense\n";
    cout << "2. Display all expenses\n";
    cout << "3. Summarize total expenses\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
    int option;
    cin >> option;
    if (option == 1) {
      cin.ignore(); // clear the input buffer
      string description;
      string amountStr;
      cout << "Enter expense description: ";
      getline(cin, description);
      cout << "Enter expense amount: ";
      getline(cin, amountStr);
      if (isValidAmount(amountStr)) {
        appendExpense(description, amountStr);
        cout << "Expense recorded successfully.\n";
      } else {
        cout << "Invalid amount entered. Please try again.\n";
      }
    } else if (option == 2) {
      displayExpenses();
    } else if (option == 3) {
      summarizeExpenses();
    } else if (option == 4) {
      break;
    } else {
      cout << "Invalid option. Please try again.\n";
    }
  }
  cout << "Exiting Expense Tracker..." << endl; // Print exiting message after loop
  return 0;
}
```
# Usage
1. Enter an expense:
   -Select option 1 from the menu.
   -Enter the expense description.
   -Enter the expense amount.
   -The expense is recorded in the expenses.txt file along with the current date and time.

2. Display all expenses:
   -Select option 2 from the menu.
   -All recorded expenses will be displayed.

3. Summarize total expenses:
   -Select option 3 from the menu.
   -The total amount of all recorded expenses will be displayed.
4. Exit:
   -Select option 4 from the menu to exit the program.
