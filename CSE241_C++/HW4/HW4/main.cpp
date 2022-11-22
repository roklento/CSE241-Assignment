#include <iostream>
#include <string>
#include <time.h>
#include "class.h"
#include "match.h"

using namespace std;

int main()
{
    srand(time(NULL));


    /* Creating a pointer to a robot object and then creating a new object of the type of the pointer. */
    Robot *r1 = new optimusprime("optimusprime",15,210);
    Robot *r2 = new robocop("robocop",16,200);
    Robot *r3 = new roomba("roomba",18,160);
    Robot *r4 = new bulldozer("bulldozer",15,300);
    Robot *r5 = new optimusprime("optimusprime",18,200);
    Robot *r6 = new robocop("robocop",17,220);
    Robot *r7 = new roomba("roomba",15,150);
    Robot *r8 = new bulldozer("bulldozer",15,300);

    /* Calling the function match. */
    match(r1,r2);
    match(r2,r1);
    match(r1,r3);
    match(r3,r1);
    match(r1,r4);
    match(r4,r1);
    match(r1,r5);

    match(r2,r3);
    match(r3,r2);
    match(r2,r4);
    match(r4,r2);
    match(r2,r6);

    match(r3,r4);
    match(r4,r3);
    match(r3,r7);
    match(r4,r8);


    













































    /* Initializing the object obj1 with the name "optimusprime", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj1 to the type, strength, and
    hitpoint of the object obj1. */
    /*optimusprime obj1("optimusprime",5,100);
    obj1.humanic::type = obj1.getType();
    obj1.humanic::strength = obj1.strength;
    obj1.humanic::hitpoint = obj1.hitpoint;
    obj1.Robot::type = obj1.getType();
    obj1.Robot::strength = obj1.strength;
    obj1.Robot::hitpoint = obj1.hitpoint;

    /* Initializing the object obj2 with the name "robocop", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj2 to the type, strength, and
    hitpoint of the object obj2. */
   /* robocop obj2("robocop",5,100);
    obj2.humanic::type = obj2.getType();
    obj2.humanic::strength = obj2.strength;
    obj2.humanic::hitpoint = obj2.hitpoint;
    obj2.Robot::type = obj2.getType();
    obj2.Robot::strength = obj2.strength;
    obj2.Robot::hitpoint = obj2.hitpoint;

    /* Printing out the type, strength, and hitpoint of the objects obj1 and obj2. It is also calling
    the function match. */
   /* cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj1.getType() << " strength: " << obj1.strength << " hitpoint: " << obj1.hitpoint  <<endl;
    cout<<"type: "<<obj2.getType() << " strength: " << obj2.strength << " hitpoint: " << obj2.hitpoint  <<endl;
    cout << endl;
    match(obj1,obj2);



    /* Initializing the object obj3 with the name "optimusprime", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj3 to the type, strength, and
    hitpoint of the object obj3. */
   /*optimusprime obj3("optimusprime",5,100);
    obj3.humanic::type = obj3.getType();
    obj3.humanic::strength = obj3.strength;
    obj3.humanic::hitpoint = obj3.hitpoint;
    obj3.Robot::type = obj3.getType();
    obj3.Robot::strength = obj3.strength;
    obj3.Robot::hitpoint = obj3.hitpoint;

    /* Initializing the object obj4 with the name "roomba", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj4 to the type, strength, and
    hitpoint of the object obj4. */
    /*roomba obj4("roomba",5,100);
    obj4.Robot::type = obj4.getType();
    obj4.Robot::strength = obj4.strength;
    obj4.Robot::hitpoint = obj4.hitpoint;

    /* Printing out the type, strength, and hitpoint of the objects obj3 and obj4. It is also calling
    the function match. */
   /* cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj3.getType() << " strength: " << obj3.strength << " hitpoint: " << obj3.hitpoint  <<endl;
    cout<<"type: "<<obj4.getType() << " strength: " << obj4.strength << " hitpoint: " << obj4.hitpoint  <<endl;
    cout << endl;
    match(obj3,obj4);



    /* Initializing the object obj5 with the name "optimusprime", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj5 to the type, strength, and
    hitpoint of the object obj5. */
   /* optimusprime obj5("optimusprime",5,100);
    /obj5.humanic::type = obj5.getType();
    obj5.humanic::strength = obj5.strength;
    obj5.humanic::hitpoint = obj5.hitpoint;
    obj5.Robot::type = obj5.getType();
    obj5.Robot::strength = obj5.strength;
    obj5.Robot::hitpoint = obj5.hitpoint;
*/
    /* Initializing the object obj6 with the name "bulldozer", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj6 to the type, strength, and
    hitpoint of the object obj6. */
   /* bulldozer obj6("bulldozer",5,100);
    obj6.Robot::type = obj6.getType();
    obj6.Robot::strength = obj6.strength;
    obj6.Robot::hitpoint = obj6.hitpoint;*/

    /* Printing out the type, strength, and hitpoint of the objects obj5 and obj6. It is also calling
    the function match. */
    /*cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj5.getType() << " strength: " << obj5.strength << " hitpoint: " << obj5.hitpoint <<endl;
    cout<<"type: "<<obj6.getType() << " strength: " << obj6.strength << " hitpoint: " << obj6.hitpoint <<endl;
    cout << endl;
    match(obj5,obj6);*/



    /* Initializing the object obj7 with the name "robocop", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj7 to the type, strength, and
    hitpoint of the object obj7. */
   /* robocop obj7("robocop",5,100);
    obj7.humanic::type = obj7.getType();
    obj7.humanic::strength = obj7.strength;
    obj7.humanic::hitpoint = obj7.hitpoint;
    obj7.Robot::type = obj7.getType();
    obj7.Robot::strength = obj7.strength;
    obj7.Robot::hitpoint = obj7.hitpoint;*/

   /* Initializing the object obj8 with the name "roomba", strength 5, and hitpoint 100. It is
   also setting the type, strength, and hitpoint of the object obj8 to the type, strength, and
   hitpoint of the object obj8. */
   /* roomba obj8("roomba",5,100);
    obj8.Robot::type = obj8.getType();
    obj8.Robot::strength = obj8.strength;
    obj8.Robot::hitpoint = obj8.hitpoint;*/

   /* Printing out the type, strength, and hitpoint of the objects obj7 and obj8. It is also calling
    the function match. */
   /* cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj7.getType() << " strength: " << obj7.strength << " hitpoint: " << obj7.hitpoint  <<endl;
    cout<<"type: "<<obj8.getType() << " strength: " << obj8.strength << " hitpoint: " << obj8.hitpoint  <<endl;
    cout << endl;
    match(obj7,obj8);*/



  /* Initializing the object obj9 with the name "robocop", strength 5, and hitpoint 100. It is
    also setting the type, strength, and hitpoint of the object obj9 to the type, strength, and
    hitpoint of the object obj9. */
   /* robocop obj9("robocop",5,100);
    obj9.humanic::type = obj9.getType();
    obj9.humanic::strength = obj9.strength;
    obj9.humanic::hitpoint = obj9.hitpoint;
    obj9.Robot::type = obj9.getType();
    obj9.Robot::strength = obj9.strength;
    obj9.Robot::hitpoint = obj9.hitpoint;*/

    /* Initializing the object obj10 with the name "bulldozer", strength 5, and hitpoint 100. It is
        also setting the type, strength, and hitpoint of the object obj10 to the type, strength, and
        hitpoint of the object obj10. */
    /*bulldozer obj10("bulldozer",5,100);
    obj10.Robot::type = obj10.getType();
    obj10.Robot::strength = obj10.strength;
    obj10.Robot::hitpoint = obj10.hitpoint;*/

    /* Printing out the type, strength, and hitpoint of the objects obj9 and obj10. It is also calling
        the function match. */
    /*cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj9.getType() << " strength: " << obj9.strength << " hitpoint: " << obj9.hitpoint  <<endl;
    cout<<"type: "<<obj10.getType() << " strength: " << obj10.strength << " hitpoint: " << obj10.hitpoint  <<endl;
    cout << endl;
    match(obj9, obj10);*/



    /* Initializing the object obj11 with the name "roomba", strength 5, and hitpoint 100. It is
        also setting the type, strength, and hitpoint of the object obj11 to the type, strength, and
        hitpoint of the object obj11. */
    /*roomba obj11("roomba",5,100);
    obj11.Robot::type = obj11.getType();
    obj11.Robot::strength = obj11.strength;
    obj11.Robot::hitpoint = obj11.hitpoint;*/

    /* Initializing the object obj12 with the name "bulldozer", strength 5, and hitpoint 100. It is
        also setting the type, strength, and hitpoint of the object obj12 to the type, strength,and
        hitpoint of the object obj12. */
    /*bulldozer obj12("bulldozer",5,100);
    obj12.Robot::type = obj12.getType();
    obj12.Robot::strength = obj12.strength;
    obj12.Robot::hitpoint = obj12.hitpoint;*/

    /* Printing out the type, strength, and hitpoint of the objects obj11 and obj12. It is also calling
    the function match. */
    /*cout << "----------------------ROBOT WARS----------------------" << endl;
    cout<<"type: "<<obj11.getType() << " strength: " << obj11.strength << " hitpoint: " << obj11.hitpoint <<endl;
    cout<<"type: "<<obj12.getType() << " strength: " << obj12.strength << " hitpoint: " << obj12.hitpoint <<endl;
    cout << endl;
    match(obj11,obj12);
    */
    return 0;
}
