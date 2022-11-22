#ifndef gate_h
#define gate_h

#include <string>
#include <iostream>
#include <vector>

using namespace std;
/*This is the base class for all the Gates. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Gate
{
    public:
        Gate(); 
        Gate(string,string,string);
        virtual int eval() = 0;
        string name;
        string input1;
        string input2;
        int output;
        Gate *in1;
        Gate *in2; 
          
};

/*This is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Input : public Gate
{
    public:
        Input();
        Input(string,string,string);
        int eval();

};

/*this is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Output : public Gate
{
    public:
        Output();
        Output(string,string,string);
        int eval();
};

/*This is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class And : public Gate
{
    public:
        And();
        And(string,string,string);
        int eval();
};

/*This is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Or : public Gate
{
    public:
        Or();
        Or(string,string,string);
        int eval();
};

/*This is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Not : public Gate
{
    public:
        Not();
        Not(string,string,string);
        int eval();
};

/*This is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Flipflop : public Gate
{
    public:
        Flipflop();
        Flipflop(string,string,string);
        int eval();
        int mem = 0;
        int flag =0;
};

/*this is a class that is derived from the base class Gate. It has a constructor that takes in the name, input1 and input2 of the Gate.
It also has a virtual function called eval that is used to evaluate the output of the Gate. It also has a pointer to the input Gates.*/
class Decoder : public Gate
{
    public:
        Decoder();
        Decoder(string,string,string);
        int eval();
        Gate *output1;
        Gate *output2;
        Gate *output3;
        Gate *output4;
};

#endif