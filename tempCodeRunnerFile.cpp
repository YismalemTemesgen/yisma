#include <iostream>
#include <string>

using namespace std;

struct Department {
    string name;
    string shortName;
};

struct Course {
    string name;
    string code;
};

struct Student {
    string id;
    string firstName;
    string lastName;
    Department department;
    Course *courses;
    float *scores;
};

int main() {
    Student *students;
    Course *courses;
    Department department;
    int numOfCourses, numOfStudents;

    // Fetching necessary information from the user
    cout << "How many students do you wish to register\n";
    cin >> numOfStudents;
    cin.ignore();
    
    cout << "What is the name of your department\n";
    getline(cin, department.name);
    
    cout << "What is the short name for "" << department.name << "": \n";
    getline(cin, department.shortName);
    
    cout << "How many courses are there in "" << department.name << "" department: \n";
    cin >> numOfCourses;
    cin.ignore();

    students = new Student[numOfStudents];
    courses = new Course[numOfCourses];

    // Entering course information
    for (int i = 0; i < numOfCourses; i++) {
        cout << "Enter the name of the " << (i + 1) << " course:\n";
        getline(cin, courses[i].name);
        cout << "Enter the code for "" << courses[i].name << "":\n";
        getline(cin, courses[i].code);
    }

    // Fetching each student's information
    for (int i = 0; i < numOfStudents; i++) {
        cout << "Enter the id of the " << (i + 1) << " Student:\n";
        getline(cin, students[i].id);
        
        cout << "Enter the first name of the " << (i + 1) << " Student:\n";
        getline(cin, students[i].firstName);
        
        cout << "Enter the last name of the " << (i + 1) << " Student:\n";
        getline(cin, students[i].lastName);
        
        students[i].department = department;
        students[i].courses = courses;
        students[i].scores = new float[numOfCourses];
        
        // Fetching the score of current student
        for (int j = 0; j < numOfCourses; j++) {
            cout << "Enter " << students[i].firstName << "'s "" << courses[j].name << "" score:\n";
            cin >> students[i].scores[j];
        }
        cin.ignore();
    }

    // Print student information in reverse order
    cout << "\nStudent information in reverse order:\n";
    for (int i = numOfStudents - 1; i >= 0; i--) {
        cout << "Student ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << "\n";
        cout << "Department: " << students[i].department.name << " (" << students[i].department.shortName << ")\n";
        
        for (int j = 0; j < numOfCourses; j++) {
            cout << "Course: " << students[i].courses[j].name 
                 << ", Code: " << students[i].courses[j].code 
                 << ", Score: " << students[i].scores[j] << "\n";
        }
        cout << endl; // Print a blank line between students
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < numOfStudents; i++) {
        delete[] students[i].scores; // Free scores array for each student
    }
    delete[] students; // Free students array
    delete[] courses; // Free courses array

    return 0;
}
