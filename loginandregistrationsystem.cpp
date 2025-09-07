#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

const string USER_DATA_FILE = "user_data.txt";  // File to store user credentials

// Function to register a new user
void registerUser() {
    string username, password, line;
    bool usernameExists = false;

    // Get the username and password
    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    // Check if username already exists
    ifstream infile(USER_DATA_FILE);
    while (getline(infile, line)) {
        stringstream ss(line);
        string storedUsername, storedPassword;
        ss >> storedUsername >> storedPassword;

        if (storedUsername == username) {
            usernameExists = true;
            break;
        }
    }
    infile.close();

    if (usernameExists) {
        cout << "Username already exists! Please choose another username." << endl;
        return;
    }

    // If the username does not exist, store the credentials in the file
    ofstream outfile(USER_DATA_FILE, ios::app); // Open in append mode
    if (outfile.is_open()) {
        outfile << username << " " << password << endl;
        outfile.close();
        cout << "Registration successful!" << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }
}

// Function to login an existing user
void loginUser() {
    string username, password, line;
    bool loginSuccess = false;

    // Get the username and password
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Check the user data file for matching credentials
    ifstream infile(USER_DATA_FILE);
    while (getline(infile, line)) {
        stringstream ss(line);
        string storedUsername, storedPassword;
        ss >> storedUsername >> storedPassword;

        if (storedUsername == username && storedPassword == password) {
            loginSuccess = true;
            break;
        }
    }
    infile.close();

    if (loginSuccess) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Invalid username or password. Please try again." << endl;
    }
}

// Main function to control program flow
int main() {
    int choice;
    while (true) {
        // Display the menu options
        cout << "\n*** Welcome to the Login and Registration System ***\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
