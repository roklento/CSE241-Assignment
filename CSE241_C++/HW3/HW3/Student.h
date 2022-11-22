#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
#include "Course.h"

using namespace std;

/*The above code is creating a class called Student. 
It has a constructor, a destructor, and a setStudent function. 
It also has a getStudentName function, a getID function, and a getCourseSize function.*/
namespace PS3
{   
    class Course;
    class Student
    {
        public:
            Student();
            Student(string, int);
            ~Student();
            void setStudent();
            string getStudentName();
            int getID();
            int getCourseSize();
            string name;
            int id;
            Course *course_reference;
            int course_ref_size;
    };
}
#endif