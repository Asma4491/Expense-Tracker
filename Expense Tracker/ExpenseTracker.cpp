#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <string>

using namespace std;

// Function to get current date and time as a string
string getCurrentDateTime() {
  time_t now = time(0);
  tm *ltm = localtime(&now);
  stringstream ss;
  ss << 1900 + ltm->tm_year << "-"
     << setfill('0') << setw(2) << 1 + ltm->tm_mon << "-"
     << setfill('0') << setw(2) << ltm->tm_mday << " "
     << setfill('0') << setw(2) << ltm->tm_hour << ":"
     << setfill('0') << setw(2) << ltm->tm_min << ":"
     << setfill('0') << setw(2) << ltm->tm_sec;
  return ss.str();
}

// Function to validate that the amount is a valid numeric value and non-negative
bool isValidAmount(const string &amountStr) {
  try {
    double amount = stod(amountStr);
    return amount >= 0;
  } catch (...) {
    return false;
  }
}

// Function to append an expense to the file
void appendExpense(const string &description, const string &amountStr) {
  ofstream file("expenses.txt", ios::app); // Open file in append mode
  if (!file.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }
  file << description << ", " << amountStr << ", " << getCurrentDateTime() << endl;
  file.close();
}

// Function to display all recorded expenses
void displayExpenses() {
  ifstream file("expenses.txt");
  if (!file.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }
  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }
  file.close();
}

// Function to summarize total expenses
void summarizeExpenses() {
  ifstream file("expenses.txt");
  if (!file.is_open()) {
    cerr << "Error opening file!" << endl;
    return;
  }
  string line;
  double total = 0;
  while (getline(file, line)) {
    istringstream iss(line);
    string description, amountStr, dateTime;
    getline(iss, description, ',');
    getline(iss, amountStr, ',');
    getline(iss, dateTime);
    total += stod(amountStr);
  }
  file.close();
  cout << "Total expenses: $" << total << endl;
}

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