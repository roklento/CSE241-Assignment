#ifndef SchoolManagerSystem_h
#define SchoolManagerSystem_h

#include <iostream>
#include <string>
#include "Course.h"
#include "Student.h"

using namespace std;

namespace PS3
{
    class Course;
    class Student;
    //A class that is used to manage the school system.
    class SchoolManagerSystem
    {
        public:
            SchoolManagerSystem();
            ~SchoolManagerSystem();
            int menu();
            void add_student();
            Student select_student();
            void delete_student(string,int);
            void add_selected_student_to_a_course(Student);
            void drop_selected_student_from_a_course(Student);
            void add_course();
            Course select_course();
            void delete_course(string,string);
            void list_students_registered_to_the_selected_course(Course);
            void printListAllStudent();
            void printListAllCourse();

        private:
            Student *students;
            Course *courses;
            int student_size;
            int course_size;
    };
}

#endif