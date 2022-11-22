#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"

using namespace std;

namespace PS3
{
    /**
     * This function is a constructor for the Course class
     */
    Course::Course()
    {
        name = "";
        code = "";
        student_ref_size = 0;
        student_reference = new Student[this->student_ref_size];
        student_ref_size++;
    }

    /**
     * This function is a constructor for the Course class. It takes two strings as parameters and
     * assigns them to the name and code variables
     * 
     * @param course_name The name of the course.
     * @param course_code The course code of the course.
     */
    Course::Course(string course_name, string course_code)
    {
        name = course_name;
        code = course_code; 
    }

    Course::~Course()
    {
    }

    /**
     * This function sets the course code and name
     */
    void Course::setCourse()
    {
        cout << "Please enter a course code: ";
        cin >> code;
        cout << "Please enter a course name: ";
        cin >> name;
        
    }

    /**
     * This function returns the name of the course
     * 
     * @return The name of the course.
     */
    string Course::getCourseName()
    {
        return name;
    }

    /**
     * This function returns the course code
     * 
     * @return The code of the course.
     */
    string Course::getCode()
    {
        return code;
    }

    /**
     * This function returns the size of the student_ref array
     * 
     * @return The size of the student_ref array.
     */
    int Course::getStudentSize()
    {
        return student_ref_size;
    }
}