#pragma once
#include <vector>
#include "student.h"

using namespace std;

class Student;

class Roster {
private:
    vector<Student*> classRosterArray;  // Using a vector for dynamic sizing

public:
    Student* parse(string data);
    const vector<Student*>& getClassRosterArray() const;
    void add(string studentID, string firstName, string lastName, string emailAddress, int age,
        int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};