/*Department maintains a student information. The file contains roll number, name,
division and address. Allow user to add, delete information of student. Display
information of particular employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student details. Use
sequential file to main the data. */
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char* FILE_NAME = "students.dat";
const char* TEMP_FILE_NAME = "temp.dat";

struct Student {
    int rollNumber;
    char name[50];
    char division[10];
    char address[100];
};

// Function to add student information
void addStudent() {
    ofstream file(FILE_NAME, ios::binary | ios::app);

    Student student;
    cout << "Enter roll number: ";
    cin >> student.rollNumber;
    cout << "Enter name: ";
    cin.ignore();
    cin.getline(student.name, 50);
    cout << "Enter division: ";
    cin >> student.division;
    cout << "Enter address: ";
    cin.ignore();
    cin.getline(student.address, 100);

    file.write(reinterpret_cast<char*>(&student), sizeof(Student));
    file.close();

    cout << "Student information added successfully!" << endl;
}

// Function to delete student information
void deleteStudent() {
    ifstream file(FILE_NAME, ios::binary);
    ofstream tempFile(TEMP_FILE_NAME, ios::binary);

    int rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber != rollNumber) {
            tempFile.write(reinterpret_cast<char*>(&student), sizeof(Student));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove(FILE_NAME);
    rename(TEMP_FILE_NAME, FILE_NAME);

    if (found) {
        cout << "Student information deleted successfully!" << endl;
    } else {
        cout << "Student not found!" << endl;
    }
}

// Function to display student information
void displayStudent() {
    ifstream file(FILE_NAME, ios::binary);

    int rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;

    Student student;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&student), sizeof(Student))) {
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Student not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Display student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

/* iostream Library:
The iostream library in C++ provides input and output functionalities through the standard streams: cin, cout, cerr, and clog. It includes the necessary classes and functions for reading from and writing to the console, files, and other input/output devices.

Data Types:
The iostream library supports various data types for input and output operations, including:

1. int: Represents integer values.
2. float: Represents floating-point values with single precision.
3. double: Represents floating-point values with double precision.
4. char: Represents single characters.
5. string: Represents a sequence of characters.
6. bool: Represents boolean values (true or false).

Opening File and Mode Flags:
To work with files, the iostream library provides functionality to open files with specific modes using the ofstream and ifstream classes. The mode flags specify the intended file operations. Some commonly used mode flags include:

1. ios::in: Open the file for reading.
2. ios::out: Open the file for writing.
3. ios::app: Append to an existing file.
4. ios::trunc: Truncate an existing file if it exists.
5. ios::binary: Open the file in binary mode.
6. ios::ate: Set the initial position of the file pointer to the end of the file.

Return Value and Meaning:
The functions in the iostream library often return a value indicating the success or failure of the operation. Some commonly used return values and their meanings include:

1. cin >> value: Returns a reference to the input stream (cin). It is typically used for chained input operations.
2. cout << value: Returns a reference to the output stream (cout). It is typically used for chained output operations.
3. ifstream::open: Returns a boolean value (true or false). It indicates whether the file was successfully opened or not.
4. ofstream::open: Returns a boolean value (true or false). It indicates whether the file was successfully created or not.
5. getline: Returns the input stream (cin) after extracting the line of characters from the input.

These return values can be used for error handling or to check the status of input/output operations.

Overall, the iostream library provides a comprehensive set of functionalities for input and output 
operations in C++. It offers data types, file handling capabilities, and stream-based input/output 
operations to interact with various devices and files. */

//-----SnehuD-----
