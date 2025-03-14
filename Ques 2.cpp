#include <iostream>
#include <limits>  // For checking invalid input

using namespace std;

// Function to perform addition
double add(double x, double y) {
    return x + y;
}

// Function to perform subtraction
double subtract(double x, double y) {
    return x - y;
}

// Function to perform multiplication
double multiply(double x, double y) {
    return x * y;
}

// Function to perform division
double divide(double x, double y) {
    if (y == 0) {
        cout << "Error! Division by zero is not allowed." << endl;
        return numeric_limits<double>::infinity();  // Return infinity as a signal of an error
    }
    return x / y;
}

// Function to validate user input and ensure they enter a number
double getNumberInput(const string& prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cout << "Invalid input! Please enter a valid number: ";
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
    }
    return num;
}

// Main function to run the calculator
void calculator() {
    double num1, num2;
    int operation;

    while (true) {
        // Displaying the menu
        cout << "\n==================== Calculator ====================" << endl;
        cout << "Select an operation:" << endl;
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Exit" << endl;

        // Get the operation choice from the user
        cout << "Enter your choice (1/2/3/4/5): ";
        while (!(cin >> operation) || operation < 1 || operation > 5) {
            cout << "Invalid choice! Please enter a valid operation (1-5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (operation == 5) {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;  // Exit the program
        }

        // Get the two numbers from the user
        num1 = getNumberInput("Enter first number: ");
        num2 = getNumberInput("Enter second number: ");

        // Perform the operation based on user choice
        switch (operation) {
            case 1:
                cout << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
                break;
            case 2:
                cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
                break;
            case 4:
                // If division, check if the denominator is zero
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
                } else {
                    cout << "Cannot divide by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid operation!" << endl;
        }

        // Ask if the user wants to perform another operation
        char choice;
        cout << "\nDo you want to perform another operation? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }
    }
}

int main() {
    // Start the calculator program
    calculator();
    return 0;
}
