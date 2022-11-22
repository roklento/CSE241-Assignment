#include <iostream>
#include <string>
#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"

using namespace std;
using namespace PS3;

int main()
{
    SchoolManagerSystem School;
    int check = 1;
    while(check != 0)
    {
        check = School.menu();
    }
    return 0;
}