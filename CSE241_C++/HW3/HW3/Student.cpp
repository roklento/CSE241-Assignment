#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PS3
{
    /**
     * This function is a constructor for the Student class
     */
    Student::Student()
    {
        name = "";
        id = 0;
        course_ref_size = 20; 
        course_reference = new Course[++(this->course_ref_size)];
    }
    
    /**
     * The constructor initializes the name and id of the student
     * 
     * @param student_name The name of the student
     * @param student_id The student's ID number
     */
    Student::Student(string student_name, int student_id)
    {
        name = student_name;
        id = student_id;
    }

    Student::~Student()
    {
    }

    /**
     * This function sets the name and id of a student
     */
    void Student::setStudent()
    {
        cout << "please enter a student name: ";
        cin >> name;
        
        cout << "please enter a student id: ";
        cin >> id;
    }

    /**
     * This function returns the name of the student
     * 
     * @return The name of the student.
     */
    string Student::getStudentName()
    {
        return name;
    }

    /**
     * This function returns the student's ID number.
     * 
     * @return The id of the student.
     */
    int Student::getID()
    {
        return id;
    }

    /**
     * This function returns the size of the course_ref array
     * 
     * @return The size of the course_ref array.
     */
    int Student::getCourseSize()
    {
        return course_ref_size;
    }
}