#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>
#include "roster.h"

// Parse student data and create a Student object
Student* Roster::parse(string data) {
    vector<string> fields;
    stringstream ss(data);
    string token;

    while (getline(ss, token, ',')) {
        fields.push_back(token);
    }

    // Convert string degree to enum DegreeProgram
    DegreeProgram degree;
    if (fields[8] == "SECURITY") {
        degree = SECURITY;
    }
    else if (fields[8] == "NETWORK") {
        degree = NETWORK;
    }
    else if (fields[8] == "SOFTWARE") {
        degree = SOFTWARE;
    }
    else {
        // Unknown degree type. Handle accordingly.
        cerr << "Unknown degree type: " << fields[8] << endl;
        return nullptr;
    }

    int days[3] = { stoi(fields[5]), stoi(fields[6]), stoi(fields[7]) };

    return new Student(fields[0], fields[1], fields[2], fields[3], stoi(fields[4]), days, degree);
}

const vector<Student*>& Roster::getClassRosterArray() const {
    return classRosterArray;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
    int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    Student* student = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeprogram);
    classRosterArray.push_back(student);
}

void Roster::remove(string studentID) {
    for (size_t i = 0; i < classRosterArray.size(); i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray.erase(classRosterArray.begin() + i);
            return;
        }
    }
    cout << "Error: Student with ID " << studentID << " not found." << endl;
}

void Roster::printAll() {
    for (Student* student : classRosterArray) {
        student->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    for (Student* student : classRosterArray) {
        if (student->getStudentID() == studentID) {
            int* days = student->getDaysToComplete();
            cout << "Average days in course for student " << studentID << ": "
                << round((days[0] + days[1] + days[2]) / 3.0) << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (Student* student : classRosterArray) {
        string email = student->getEmailAddress();
        if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
            cout << "Invalid email for student " << student->getStudentID() << ": " << email << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (Student* student : classRosterArray) {
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
}

Roster::~Roster() {
    for (Student* student : classRosterArray) {
        delete student;
    }
}
