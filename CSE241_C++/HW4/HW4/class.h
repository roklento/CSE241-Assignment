#ifndef class_h
#define class_h

#include <iostream>
#include <string>

using namespace std;

/*This is the class Robot. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class Robot
{
    public:
        Robot();
        Robot(string,int,int);
        virtual string getType() = 0;
        virtual int getStrength() = 0;
        virtual int getHitpoint() = 0;
        int getDamage();
        string type;
        int strength;
        int hitpoint;
};

/*This is a class that is inheriting from the Robot class. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class humanic : public Robot
{
    public:
        humanic();
        humanic(string,int,int);
        string getType();
        int getStrength();
        int getHitpoint();
        int getDamage();
        string type;
        int strength;
        int hitpoint;

};

/*This is a class that is inheriting from the Robot class. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class roomba : public Robot
{
    public:
        roomba();
        roomba(string,int,int);
        string getType();
        int getStrength();
        int getHitpoint();
        int getDamage();
        string type;
        int strength;
        int hitpoint;
};

/*This is a class that is inheriting from the Robot class. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class bulldozer : public Robot
{
    public:
        bulldozer();
        bulldozer(string,int,int);
        string getType();
        int getStrength();
        int getHitpoint();
        int getDamage();
        string type;
        int strength;
        int hitpoint;
};

/*This is a class that is inheriting from the humanic class. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class optimusprime : public humanic
{
    public:
        optimusprime();
        optimusprime(string,int,int);
        string getType();
        int getStrength();
        int getHitpoint();
        int getDamage();
        string type;
        int strength;
        int hitpoint;
};

/*This is a class that is inheriting from the humanic class. It has a constructor, a constructor with parameters, a getType function, a getDamage function, and three variables.*/
class robocop : public humanic
{
     public:
        robocop();
        robocop(string,int,int);
        string getType();
        int getStrength();
        int getHitpoint();
        int getDamage();
        string type;
        int strength;
        int hitpoint;
};
#endif