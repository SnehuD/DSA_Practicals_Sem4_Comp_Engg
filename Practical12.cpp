/*Company maintains employee information as employee ID, name, designation and
salary. Allow user to add, delete information of employee. Display information of
particular employee. If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. Use index sequential file to
maintain the data.*/

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Employee {
    int empID;
    char name[50];
    char designation[50];
    float salary;
};

// Function to add employee information
void addEmployee() {
    ofstream file("employee.dat", ios::binary | ios::app);

    Employee emp;
    cout << "Enter employee ID: ";
    cin >> emp.empID;
    cout << "Enter employee name: ";
    cin.ignore();
    cin.getline(emp.name, 50);
    cout << "Enter employee designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter employee salary: ";
    cin >> emp.salary;

    file.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
    file.close();

    cout << "Employee information added successfully!" << endl;
}

// Function to delete employee information
void deleteEmployee() {
    ifstream file("employee.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);

    int empID;
    cout << "Enter employee ID to delete: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID != empID) {
            tempFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found) {
        cout << "Employee information deleted successfully!" << endl;
    } else {
        cout << "Employee not found!" << endl;
    }
}

// Function to display employee information
void displayEmployee() {
    ifstream file("employee.dat", ios::binary);

    int empID;
    cout << "Enter employee ID to display: ";
    cin >> empID;

    Employee emp;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID == empID) {
            cout << "Employee ID: " << emp.empID << endl;
            cout << "Name: " << emp.name << endl;
            cout << "Designation: " << emp.designation << endl;
            cout << "Salary: " << emp.salary << endl;
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Employee not found!" << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "1. Add employee\n";
        cout << "2. Delete employee\n";
        cout << "3. Display employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
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
/* Indexed Sequential Access Method (ISAM) is an advanced file organization technique that combines the benefits of sequential access and indexed access to provide efficient data retrieval and storage.

In ISAM, the file is divided into fixed-length blocks or pages, and each block is assigned a unique index key value. These index key values are stored in an index file, along with their corresponding block addresses. The index file serves as a guide to quickly locate the desired data blocks in the sequential file.

Advantages of ISAM:
1. Efficient Retrieval: ISAM allows for fast and direct access to specific data blocks through the index file, making retrieval operations efficient even for large files.
2. Sequential Access: ISAM maintains the sequential order of data within each block, making it suitable for applications that require sequential processing of records.
3. Indexing: The use of indexes enables efficient search operations, as the index file provides a way to locate specific data blocks based on the index key values.
4. Space Efficiency: ISAM minimizes storage overhead by organizing data into fixed-length blocks and maintaining indexes separately, optimizing storage space usage.

Disadvantages of ISAM:
1. Insertion and Deletion Overhead: Inserting or deleting records in ISAM requires updating the index file and potentially redistributing data blocks, which can result in additional overhead and slower performance compared to simple sequential file organization.
2. Limited Flexibility: ISAM is not well-suited for frequent record insertions or deletions, as these operations can disrupt the sequential order and require reorganization of data blocks.
3. Index Maintenance: The index file needs to be constantly updated to reflect changes in the data file, which adds complexity and overhead to the file management process.

ISAM offers a balance between efficient indexed access and sequential processing, making it suitable for applications that require fast retrieval based 
on specific criteria while still benefiting from sequential data processing within each block. 
However, its limitations in handling frequent insertions and deletions and the additional overhead of maintaining indexes 
should be considered when choosing an appropriate file organization method. */

//-----SnehuD-----

