#ifndef Course_h
#define Course_h

#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

/*The above code is creating a class called Course.
It has a constructor, a destructor, and a setCourse function. 
It also has a getCourseName function, a getCode function, and a getStudentSize function. 
It also has a string called name, a string called code, a Student pointer called student_reference, and an int called student_ref_size.*/
namespace PS3
{
    class Student;
    class Course
    {
        public:
            Course();
            Course(string, string);
            ~Course();
            void setCourse();
            string getCourseName();
            string getCode();
            int getStudentSize();
            string name;
            string code;
            Student *student_reference;
            int student_ref_size;
    };
}
#endif