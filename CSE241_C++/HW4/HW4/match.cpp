#include <iostream>
#include <string>
#include "class.h"
#include "match.h"

using namespace std;

void match(Robot* r1, Robot* r2)
{
    int damage_r1;
    int damage_r2;
    int count = 1;

    /* Setting the hitpoint and strength of the robots to the hitpoint and strength of the robots. */
    r1->hitpoint = r1->getHitpoint();
    r2->hitpoint = r2->getHitpoint();
    r1->strength = r1->getStrength();
    r2->strength = r2->getStrength();

    cout << "--------Robot war is Starting---------" << endl;
    cout << "First robot type:" << r1->getType()
    << endl <<"First robot Hitpoint:" << r1->getHitpoint()
    << endl << "First robot Strength:" << r1->getStrength()<< endl;

    cout << "Second robot type:" << r2->getType()
    << endl <<"Second robot Hitpoint:" << r2->getHitpoint()
    << endl << "Second robot Strength:" << r2->getStrength()<< endl << endl;

    /* This is the main part of the match function. It is a while loop that runs until one of the
    robots hitpoints is 0. */
    while(r1->hitpoint > 0 && r2->hitpoint > 0)
    {
        /* It prints out the round number, then it calculates the
        damage that the first robot does to the second robot. Then it prints out the second robots
        hitpoint. */
        cout << "Round: " << count++ << endl;
        damage_r1 = r1->getDamage();
        r2->hitpoint -= damage_r1;
        cout << r2->getType() << " hitpoint: "<<r2->hitpoint << endl;

        /* It prints out the round number, then it calculates the
        damage that the second robot does to the first robot. Then it prints out the first robots
        hitpoint. */
        damage_r2 = r2->getDamage();
        r1->hitpoint -= damage_r2;
        cout << r1->getType() <<" hitpoint: "<<r1->hitpoint << endl;

        cout << endl;

    }

    /* Checking if both robots hitpoints are 0. If they are, it checks which robot has the
    higher hitpoint. If the first robot has the higher hitpoint, it prints out that the first robot
    won. If the second robot has the higher hitpoint, it prints out that the second robot won. */
    if(r1->hitpoint <= 0 && r2->hitpoint <= 0)
    {
        if(r1->hitpoint > r2->hitpoint)
        {
            cout <<"-------"<< r1->getType() << " won" <<"---------"<< endl << endl;
        }
        else
        {
            cout <<"-------"<< r2->getType() << " won" <<"---------"<< endl << endl;
        }
    }

    /* Checking if the first robots hitpoint is less than or equal to 0. If it is, it prints out that
    the second robot won. */
    else if(r1->hitpoint <= 0)
    {
        cout <<"-------"<< r2->getType() << " won" <<"---------"<< endl << endl;
    }

    /* Checking if the second robots hitpoint is less than or equal to 0. If it is, it prints out that
    the first robot won. */
    else if(r2->hitpoint <= 0)
    {
        cout <<"-------"<< r1->getType() << " won" <<"---------"<< endl << endl;
    }
}   