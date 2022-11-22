#ifndef circuit_h
#define circuit_h

#include <fstream>
#include <cstdio>
#include "gate.h"

using namespace std;

/*Defining a class called circuit. It has a constructor, two functions, a vector of pointers to gates, and a counter.*/
class circuit
{
    public:
        circuit();
        void read();
        void result();
        vector<Gate*> gates;
        int counter = 0;
};

#endif