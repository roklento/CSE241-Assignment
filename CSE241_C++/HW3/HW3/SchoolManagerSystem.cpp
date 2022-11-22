#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"

using namespace std;

namespace PS3
{
    /**
     * This function is the constructor of the class SchoolManagerSystem.
     */
    SchoolManagerSystem::SchoolManagerSystem()
    {
        student_size = 0;
        course_size = 0;
        students = new Student[this->student_size];
        courses = new Course[this->course_size];
    }

    /**
     * The destructor for the SchoolManagerSystem class
     */
    SchoolManagerSystem::~SchoolManagerSystem()
    {
        if(students != NULL)
        {
            delete[] students;
        }

        if(courses != NULL)
        {
            delete[] courses;
        }
    }

    /**
     * This function creates a new array of students, copies the old array into the new array, deletes
     * the old array, and then adds a new student to the new array
     */
    void SchoolManagerSystem::add_student()
    {
        Student *newArray = new Student[this->student_size + 1];
        
        for(int i = 0; i < this->student_size; i++)
        {
            newArray[i] = this->students[i];
        }
        delete[] students;
        this->students = newArray;

        newArray[this->student_size++].setStudent(); 
    }

 /**
  * This function prompts the user to enter a student name and id, and then returns a student object
  * with the name and id
  * 
  * @return A student object
  */
    Student SchoolManagerSystem::select_student()
    {
        Student temp;
        string str;
        int num;

        cout << "Please enter a registered student name: ";
        cin >> str;
        cout << "Please enter a registered student id: ";
        cin >> num;

        temp.name = str;
        
        temp.id = num;

        return temp;
    }


    /**
     * This function deletes a student from the student array
     * 
     * @param A The name of the student you want to delete.
     * @param B The student's ID
     * 
     * @return a pointer to a Student object.
     */
    void SchoolManagerSystem::delete_student(string A, int B)
    {
        Student *result = NULL;
        
        int pos = -1;

        for(int i = 0; (i < student_size) && (pos == -1); i++)
        {
            if((this->students[i].name == A) && (this->students[i].id == B))
            {
                pos = i;
            }
        }

        if(pos == -1)
        {
            return;
        }

        if(student_size > 1)
        {
            result = new Student[student_size - 1];
        }

        for(int i = 0,j = 0; i < student_size; i++)
        {
            if(i != pos)
            {
                result[j++] = this->students[i];
            }
        }
        student_size--;
        delete[] students;
        this->students = result;
    }

    /**
     * This function adds a course to the course array
     */
    void SchoolManagerSystem::add_course()
    {
        Course *newArray = new Course[this->course_size + 1];
        
        for(int i = 0; i < this->course_size; i++)
        {
            newArray[i] = this->courses[i];
        }
        delete[] courses;
        this->courses = newArray;

        newArray[this->course_size++].setCourse(); 

    }

    /**
     * It deletes a course from the system
     * 
     * @param A The name of the course
     * @param B The course code
     * 
     * @return the course object.
     */
    void SchoolManagerSystem::delete_course(string A,string B)
    {
        Course *result = NULL;
        
        int pos = -1;

        for(int i = 0; (i < course_size) && (pos == -1); i++)
        {
            if((this->courses[i].name == A) && (this->courses[i].code == B))
            {
                pos = i;
            }
        }

        if(pos == -1)
        {
            return;
        }

        if(course_size > 1)
        {
            result = new Course[course_size - 1];
        }

        for(int i = 0,j = 0; i < course_size; i++)
        {
            if(i != pos)
            {
                result[j++] = this->courses[i];
            }
        }
        course_size--;
        delete[] courses;
        this->courses = result;
        }

    /**
     * This function prints out all the students' name and id
     */
    void SchoolManagerSystem::printListAllStudent()
    {
        for(int i = 0; i < this->student_size; i++)
        {
            cout << students[i].name << " " << students[i].id << endl;
        }
    }

/**
 * This function prints all the courses in the system
 */
    void SchoolManagerSystem::printListAllCourse()
    {
        for(int i = 0; i < this->course_size; i++)
        {
            cout << courses[i].code << " " << courses[i].name << endl;
        }
    }

    /**
     * This function is used to add a course to a student's course list
     * 
     * @param A The student that is being added to a course.
     */
    void SchoolManagerSystem::add_selected_student_to_a_course(Student A)
    {
        int flag = 0;
        int num_arr;
        /* Checking if the student is already in the class. */
        for(int i = 0; i < this->student_size; i++)
        {
            if((students[i].name == A.name) && (students[i].id == A.id))
            {
                flag = 1;
                num_arr = i;
                
            }
        }
        /* The above code is printing out the courses that the student has not taken. */
        for(int i = 0; i < this->course_size; i++)      
        {   
            if(flag == 1)
            {
                if((courses[i].name != students[num_arr].course_reference[i].name) && (courses[i].code != students[num_arr].course_reference[i].code))
                {
                    cout << i << " " << courses[i].code << " " << courses[i].name << endl;
                } 
            } 
        }
        int choice;
        cout << "please choose a course: ";
        cin >> choice;
        students[num_arr].course_reference[choice].name = courses[choice].name;
        students[num_arr].course_reference[choice].code = courses[choice].code;
        /* The above code is printing out the courses that the student has not taken. */
        for(int i = 0; i < this->course_size; i++)      
        {   
            if(flag == 1)
            {
                if((courses[i].name != students[num_arr].course_reference[i].name) && (courses[i].code != students[num_arr].course_reference[i].code))
                {
                    cout << i << " " << courses[i].code << " " << courses[i].name << endl;
                } 
            } 
        }
    }

    /**
     * This function is used to drop a student from a course
     * 
     * @param B Student object
     */
    void SchoolManagerSystem::drop_selected_student_from_a_course(Student B)
    {
        int flag = 0;
        int num_arr;
        /* Checking if the student is already in the class. */
        for(int i = 0; i < this->student_size; i++)
        {
            if((students[i].name == B.name) && (students[i].id == B.id))
            {
                flag = 1;
                num_arr = i;
                
            }
        }
        /* The above code is printing the courses that the student is enrolled in. */
        for(int i = 0; i < this->course_size; i++)      
        {   
            if(flag == 1)
            {
                if((courses[i].name == students[num_arr].course_reference[i].name) && (courses[i].code == students[num_arr].course_reference[i].code))
                {
                    cout << i << " " << courses[i].code << " " << courses[i].name << endl;
                } 
            }
        }
        int choice;
        cout << "Please choose a course: ";
        cin >> choice;
        students[num_arr].course_reference[choice].name = "";
        students[num_arr].course_reference[choice].code = "";

    }
    /**
     * This function allows the user to select a course from the list of registered courses
     * 
     * @return A course object
     */
    Course SchoolManagerSystem::select_course()
    {
        Course temp;
        string str;
        string code;

        cout << "Please enter a registered course code: ";
        cin >> code;
        cout << "Please enter a registered course name: ";
        cin >> str;

        temp.name = str;
        
        temp.code = code;

        return temp;
    }

 /**
  * This function lists the students registered to the selected course
  * 
  * @param B The course that the user wants to see the students registered to.
  */
    void SchoolManagerSystem::list_students_registered_to_the_selected_course(Course B)
    {   
        int flag = 0;
        int num_arr;
        /* Checking if the course name and code are the same as the course name and code of the course
        that is being passed in. If they are the same, it sets the flag to 1 and sets the num_arr to
        the index of the course. */
        for(int i = 0; i < this->course_size; i++)
        {
            if((courses[i].name == B.name) && (courses[i].code == B.code))
            {
                flag = 1;
                num_arr = i;
                
            }
        }

       /* The above code is printing the students who are enrolled in a particular course. */
        for(int i = 0; i < this->student_size; i++)      
        {   
            for(int j = 0; j < this->course_size; j++)
            {
                if(flag == 1)
                {
                    /* Printing the students who are enrolled in a particular course. */
                    if((courses[num_arr].name == students[i].course_reference[j].name) && (courses[num_arr].code == students[i].course_reference[j].code))
                    {
                        cout << i << " " << students[i].name << " " << students[i].id << endl;
                    } 
                }
            }
        }

    }
   /**
    * This function is the main menu of the program
    * 
    * @return an integer.
    */
    int SchoolManagerSystem::menu()
    {
        int choice;
        /* The above code is a menu for the program. */
        do
        {
            cout << "Main_Menu" << endl;
            cout << "0 exit" << endl;
            cout << "1 student" << endl;
            cout << "2 course" << endl;
            cout << "3 list_all_students" << endl;
            cout << "4 list_all_courses" << endl;
            cin >> choice;
            if(choice == 0)
            {
                break;
            }
            else if(choice == 1)
            {
                int choice2;
                do
                {
                    
                    cout << "0 up" << endl;
                    cout << "1 add_student" << endl;
                    cout << "2 select_student" << endl;
                    cin >> choice2;
                    if(choice2 == 0)
                    {
                        break;
                    }
                    else if(choice2 == 1)
                    {
                        add_student();
                    }
                    else if(choice2 == 2)
                    {
                        Student temp2 = select_student();
                        int choice3;
                        do
                        {
                            cout << "0 up" << endl;
                            cout << "1 delete_student" << endl;
                            cout << "2 add_selected_student_to_a_course" << endl;
                            cout << "3 drop_selected_student_from_a_course" << endl;
                            cin >> choice3;
                            if(choice3 == 0)
                            {
                                break;
                            }
                            else if(choice3 == 1)
                            {
                                string buffer = temp2.name;
                                int buffer_num = temp2.id;
                                delete_student(buffer,buffer_num);
                                printListAllStudent();
                            }
                            else if(choice3 == 2)
                            {
                                add_selected_student_to_a_course(temp2);
                            }
                            else if(choice3 == 3)
                            {
                                drop_selected_student_from_a_course(temp2);
                            }
                        }while(choice3 < 0 || choice3 > 3);
                    }

                }while(choice2 < 0 || choice2 > 2);
            }
            else if(choice == 2)
            {
                int choice4;
                do
                {
                    cout << "0 up" << endl;
                    cout << "1 add_course" << endl;
                    cout << "2 select_course" << endl;
                    cin >> choice4;
                    if(choice4 == 0)
                    {
                        break;
                    }
                    else if(choice4 == 1)
                    {
                        add_course();
                    }
                    else if(choice4 == 2)
                    {
                        Course temp = select_course();
                        int choice5;
                        do
                        {
                            cout << "0 up" << endl;
                            cout << "1 delete_course" << endl;
                            cout << "2 list_students_registered_to_the_selected_course" << endl;
                            cin >> choice5;
                            if(choice5 == 0)
                            {
                                break;
                            }
                            else if(choice5 == 1)
                            {
                                /* Deleting a course from the course list. */
                                string buffer = temp.name;
                                string buffer_code = temp.code;
                                delete_course(buffer,buffer_code);
                            }
                            else if(choice == 2)
                            {
                                list_students_registered_to_the_selected_course(temp);
                            }
                        } while (choice5 < 0 || choice5 > 2);
                        
                    }

                }while(choice < 0 || choice >2);
                
            }
            else if(choice == 3)
            {
                printListAllStudent();
            }
            else if(choice == 4)
            {
                printListAllCourse();
            }

        } while (choice > 4 || choice < 0);
        return choice;
    }
}

