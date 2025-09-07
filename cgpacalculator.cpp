#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to calculate CGPA
double calculateCGPA(const vector<double>& gradePoints) {
    double sum = 0.0;
    for (double grade : gradePoints) {
        sum += grade;
    }
    return sum / gradePoints.size();
}

int main() {
    int numSubjects;
    
    // Ask the user for the number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;
    
    // Handle invalid number of subjects input
    if (numSubjects <= 0) {
        cout << "The number of subjects must be greater than 0!" << endl;
        return 1;
    }
    
    // Vector to store grade points for each subject
    vector<double> gradePoints(numSubjects);

    // Input the grade points for each subject
    for (int i = 0; i < numSubjects; ++i) {
        double grade;
        
        // Loop until user enters a valid grade point (between 0 and 10)
        while (true) {
            cout << "Enter grade point for subject " << i + 1 << " (0 - 10): ";
            cin >> grade;
            
            // Check for invalid input
            if (cin.fail() || grade < 0.0 || grade > 10.0) {
                cout << "Invalid grade point! Please enter a grade between 0 and 10." << endl;
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore bad input
            } else {
                gradePoints[i] = grade;
                break;
            }
        }
    }

    // Calculate and display the CGPA
    double cgpa = calculateCGPA(gradePoints);
    cout << "\nYour CGPA is: " << cgpa << endl;

    // Optional: Provide feedback on CGPA
    if (cgpa >= 9.0) {
        cout << "Excellent!" << endl;
    } else if (cgpa >= 7.0) {
        cout << "Good!" << endl;
    } else if (cgpa >= 5.0) {
        cout << "Fair!" << endl;
    } else {
        cout << "Needs Improvement!" << endl;
    }

    return 0;
}
