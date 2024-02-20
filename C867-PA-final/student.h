#pragma once
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;

public:
    // Constructor
    Student(string id, string fName, string lName, string email, int ageVal, int days[3], DegreeProgram degree) :
        studentID(id), firstName(fName), lastName(lName), emailAddress(email), age(ageVal), degreeProgram(degree)
    {
        for (int i = 0; i < 3; i++) {
            daysToComplete[i] = days[i];
        }
    }

    // Accessors (getters)
    string getStudentID() { return studentID; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getEmailAddress() { return emailAddress; }
    int getAge() { return age; }
    int* getDaysToComplete() { return daysToComplete; }
    DegreeProgram getDegreeProgram() { return degreeProgram; }

    // Mutators (setters)
    void setStudentID(string id) { studentID = id; }
    void setFirstName(string fName) { firstName = fName; }
    void setLastName(string lName) { lastName = lName; }
    void setEmailAddress(string email) { emailAddress = email; }
    void setAge(int ageVal) { age = ageVal; }
    void setDaysToComplete(int days[3]) {
        for (int i = 0; i < 3; i++) {
            daysToComplete[i] = days[i];
        }
    }
    void setDegreeProgram(DegreeProgram degree) { degreeProgram = degree; }

    // print() function
    void print() {
        string degreeStr;
        switch (degreeProgram) {
        case SECURITY: degreeStr = "SECURITY"; break;
        case NETWORK: degreeStr = "NETWORK"; break;
        case SOFTWARE: degreeStr = "SOFTWARE"; break;
        }
        cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tAge: " << age
            << "\tdaysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}"
            << "\tDegree Program: " << degreeStr << endl;
    }
};
