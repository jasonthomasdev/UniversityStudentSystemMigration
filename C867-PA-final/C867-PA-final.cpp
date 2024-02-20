#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "roster.h"

int main()
{
    // Print out required details
    cout << "Course Title: Scripting and Programming Applications\n";
    cout << "Programming Language: C++\n";
    cout << "WGU Student ID: 011014761\n";
    cout << "Name: Jason Thomas\n";
    cout << "---------------------------------------\n";

    // Create instance of Roster class
    Roster classRoster;

    // Data to be parsed
    const string studentData[] = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jason,Thomas,jth2680@wgu.edu,38,30,35,40,SOFTWARE"  
    };

    // Add each student to classRoster
    for (const string& data : studentData) {
        Student* student = classRoster.parse(data);
        classRoster.add(student->getStudentID(), student->getFirstName(), student->getLastName(),
            student->getEmailAddress(), student->getAge(),
            student->getDaysToComplete()[0], student->getDaysToComplete()[1], student->getDaysToComplete()[2],
            student->getDegreeProgram());
        delete student;  // clear temporary object
    }

    // Pseudo code conversion
    classRoster.printAll();
    classRoster.printInvalidEmails();

    // Loop through classRosterArray and for each element
    for (Student* student : classRoster.getClassRosterArray()) {
        classRoster.printAverageDaysInCourse(student->getStudentID());
    }

    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}