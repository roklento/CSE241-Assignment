#include <iostream>
#include <string>
#include "class.h"

using namespace std;

/**
 * The constructor initializes the type, strength, and hitpoint variables to "bulldozer", 10, and 10,
 * respectively.
 */
Robot::Robot()
{
    type = "Robot";
    strength = 10;
    hitpoint = 200;
}
/**
 * The Robot constructor function takes three parameters, a string, an int, and an int, and sets the
 * Robot's type, strength, and hitpoint to the values of the parameters
 * 
 * @param newType The type of robot.
 * @param newStrength The strength of the robot.
 * @param newHitpoint The hitpoint of the robot.
 */
Robot::Robot(string newType, int newStrength, int newHitpoint)
{
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the robot.
 * 
 * @return The type of the robot.
 */
/*string Robot::getType()
{
    return type;
}*/
/**
 * This function returns a random number between 1 and the robot's strength
 * 
 * @return The damage that the robot will do.
 */
int Robot::getDamage()
{
    int damage;

    damage = (rand() % this->strength) + 1;
    if(this->getType() == "optimusprime")
    {
        if(rand() % 10 == 0)
        {
            damage += 50;
            if((rand() % 20 == 0) || (rand() % 20 == 1) || (rand() % 20 == 2))
            {
                damage *= 2;
            }
        }
        cout << this->getType() << " attacks for " << damage << " points!" << endl;
    }
    else if(this->getType() == "robocop")
    {
        if(rand() % 10 == 0)
        {
            damage += 50;
            
        }
        cout << this->getType() << " attacks for " << damage << " points!" << endl;
    }

    else if(this->getType() == "roomba")
    {
        damage *= 2;
        cout << this->getType() << " attacks for " << damage << " points!" << endl;
    }
    else if(this->getType() == "bulldozer")
    {
        cout << this->getType() << " attacks for " << damage << " points!" << endl;
    }
    return damage;
}

/**
 * The humanic constructor initializes the type, strength, and hitpoint variables to "robocop", 10, and
 * 10, respectively
 */
humanic::humanic()
{
    type = "robocop";
    strength = 10;
    hitpoint = 100;
}
/**
 * The humanic constructor initializes the type, strength, and hitpoint of a humanic object
 * 
 * @param newType The type of humanic.
 * @param newStrength The strength of the humanic
 * @param newHitpoint The hitpoint of the humanic
 */
humanic::humanic(string newType, int newStrength, int newHitpoint)
{
    type = newType;
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the humanic object.
 * 
 * @return The type of the humanic.
 */
string humanic::getType()
{
    return type;
}
int humanic::getStrength()
{
    return strength;
}
int humanic::getHitpoint()
{
    return hitpoint;
}

/**
 * If the random number generator returns a 0, then the damage is increased by 50. This event happens with a %10 chance.
 * @return The damage is being returned.
 */
int humanic::getDamage()
{
    /*if(rand() % 10 == 0)
    {
        damage += 50;
        return damage;
    }*/
    return this->getDamage();
}
/**
 * A constructor for the roomba class.
 */
roomba::roomba()
{
    type = "roomba";
    strength = 10;
    hitpoint = 100;
}
/**
 * The constructor function for the roomba class
 * 
 * @param newType This is the type of roomba.
 * @param newStrength The strength of the roomba.
 * @param newHitpoint The hitpoint of the roomba
 */
roomba::roomba(string newType, int newStrength, int newHitpoint)
{
    type = newType;
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the roomba
 * 
 * @return The type of the roomba.
 */
string roomba::getType()
{
    return type;
}
/**
 * The getDamage function takes in an integer by reference and multiplies it by 2. It then prints out
 * the type of the robot and the damage it does. It then returns the damage
 * @return The damage is being returned.
 */
int roomba::getStrength()
{
    return strength;
}
int roomba::getHitpoint()
{
    return hitpoint;
}
int roomba::getDamage()
{
    /*damage *= 2;
    cout << this->getType() << " attacks for " << damage << " points!" << endl;*/
   return this->getDamage();
}


/**
 * The bulldozer constructor sets the type to bulldozer, the strength to 10, and the hitpoint to 10
 */
bulldozer::bulldozer()
{
    type = "bulldozer";
    strength = 10;
    hitpoint = 100;
}
/**
 * The bulldozer constructor function initializes the bulldozer object's type, strength, and hitpoint
 * variables
 * 
 * @param newType The type of the bulldozer.
 * @param newStrength The strength of the bulldozer.
 * @param newHitpoint The hitpoint of the bulldozer.
 */
bulldozer::bulldozer(string newType, int newStrength, int newHitpoint)
{
    type = newType;
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the bulldozer
 * 
 * @return The type of the bulldozer.
 */
string bulldozer::getType()
{
    return type;
}
int bulldozer::getHitpoint()
{
    return hitpoint;
}

int bulldozer::getStrength()
{
    return strength;
}
/**
 * The getDamage function takes an integer by reference and returns an integer
 * @return The damage that the bulldozer is doing.
 */
int bulldozer::getDamage()
{
    /*cout << this->getType() << " attacks for " << damage << " points!" << endl;*/
    return this->getDamage();
}

/**
 * The constructor for the class optimusprime sets the type to "optimusprime", the strength to 10, and
 * the hitpoint to 10.
 */
optimusprime::optimusprime()
{
    type = "optimusprime";
    strength = 10;
    hitpoint = 100;
}
/**
 * The constructor function is used to initialize the values of the object's data members.
 * 
 * @param newType This is the type of the robot.
 * @param newStrength The strength of the robot.
 * @param newHitpoint The hitpoint of the robot.
 */
optimusprime::optimusprime(string newType, int newStrength, int newHitpoint)
{
    type = newType;
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the object
 * 
 * @return The type of the object.
 */
string optimusprime::getType()
{
    return type;
}
int optimusprime::getHitpoint()
{
    return hitpoint;
}
int optimusprime::getStrength()
{
    return strength;
}
/**
 * If the random number is 0, 1, or 2, then the damage is doubled. This event happens with a %15 chance.
 * 
 * @return The damage is being returned.
 */
int optimusprime::getDamage()
{
    return this->getDamage();
}


/**
 * The robocop constructor initializes the type, strength, and hitpoint variables to the values
 * "robocop", 10, and 10, respectively
 */
robocop::robocop()
{
    type = "robocop";
    strength = 10;
    hitpoint = 100;
}
/**
 * The constructor function for the robocop class
 * 
 * @param newType This is the type of robot.
 * @param newStrength The strength of the robot.
 * @param newHitpoint The hitpoint of the new robot.
 */
robocop::robocop(string newType, int newStrength, int newHitpoint)
{
    type = newType;
    strength = newStrength;
    hitpoint = newHitpoint;
}
/**
 * This function returns the type of the robot.
 * 
 * @return The type of the robot.
 */
string robocop::getType()
{
    return type;
}
int robocop::getHitpoint()
{
    return hitpoint;
}

int robocop::getStrength()
{
    return strength;
}
/**
 * The getDamage function takes an integer as a parameter and returns an integer
 * @return The damage that the robocop is doing.
 */
int robocop::getDamage()
{
    return this->getDamage();
}