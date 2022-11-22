#include "gate.h"

using namespace std;

Gate::Gate()
{}

/**
 * This function is a constructor for the Gate class.
 * 
 * @param name The name of the gate.
 * @param in1 The first input to the gate.
 * @param in2 The second input to the gate.
 */
Gate::Gate(string name,string in1,string in2)
{
    this->name = name;
    this->input1 = in1;
    this->input2 = in2;
}

Input::Input()
{}

/**
 * A constructor for the Input class.
 * 
 * @param name The name of the gate.
 * @param in1 The name of the input pin
 * @param in2 This is the second input to the gate.
 */
Input::Input(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The eval function returns the output of the input.
 * 
 * @return The output of the input.
 */
int Input::eval()
{
    return this->output;
}

Output::Output()
{}

/**
 * Output::Output(string name,string in1,string in2) : Gate(name,in1,in2)
 * {}
 * 
 * @param name The name of the gate.
 * @param in1 The name of the input pin 1
 * @param in2 The second input to the gate.
 */
Output::Output(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The function `eval()` returns the value of the output
 * 
 * @return The output of the gate.
 */
int Output::eval()
{
    return this->output;
}

And::And()
{}

/**
 * A constructor for the And class. It takes in the name of the gate, the name of the first input, and
 * the name of the second input.
 * 
 * @param name The name of the gate.
 * @param in1 The name of the first input
 * @param in2 The second input to the AND gate.
 */
And::And(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The function takes the address of the first and second input of the gate and returns the output of
 * the gate
 * 
 * @return The output of the gate.
 */
int And::eval()
{
    int in1 = this->in1->eval();	
    int in2 = this->in2->eval();
    this->output = in1 && in2;	
    return in1 && in2;
}

Or::Or()
{}

/**
 * A constructor for the Or class. It takes in the name of the gate, the name of the first input, and
 * the name of the second input.
 * 
 * @param name The name of the gate.
 * @param in1 The name of the first input
 * @param in2 The second input to the gate.
 */
Or::Or(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The function `eval()` takes the output of the two inputs and returns the output of the OR gate
 * 
 * @return The output of the OR gate.
 */
int Or::eval()
{
    int in1 = this->in1->eval();	
    int in2 = this->in2->eval();
    this->output = in1 || in2;	
    return in1 || in2;
}

Not::Not(){}

/**
 * A constructor for the Not class. It takes in the name of the gate, the first input, and the second
 * input.
 * 
 * @param name The name of the gate.
 * @param in1 The name of the input pin
 * @param in2 This is the second input to the gate.
 */
Not::Not(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The function `Not::eval()` evaluates the input and sets the output to the logical negation of the
 * input
 * 
 * @return The output of the not gate.
 */
int Not::eval()
{
    int in1 = this->in1->eval();
    this->output = !in1;	
	return !in1;
}

Flipflop::Flipflop()
{}

/**
 * A constructor for the Flipflop class. It takes in the name of the gate, the first input, and the second
 * input.
 * 
 * @param name The name of the gate.
 * @param in1 the input to the flipflop
 * @param in2 the second input to the gate
 */
Flipflop::Flipflop(string name,string in1,string in2) : Gate(name,in1,in2)
{}

/**
 * The function takes the input from the input pin and stores it in the memory. If the input is 0, the
 * output is the opposite of the memory. If the input is 1, the output is the same as the memory
 * 
 * @return The output of the flipflop.
 */
int Flipflop::eval()
{
    
    /* This is a flag that is used to check if the flipflop has been evaluated before. If it has been
    evaluated before, then the output is the memory. */
    if(flag == 1){
        return this->mem;
    }
    int in1 = this->in1->eval();
    int memory2 = this->mem;	
    flag  = 1;
    /* This is checking if the input is 0. If the input is 0, then the output is the opposite of the
    memory. */
    if(in1 == 0) 
    {
        if(memory2 == 0)
        {	
            this->mem = 0;
            this->output = this->mem;
            return this->mem;
        }
        else if(memory2 == 1) 
        {
            this->mem = 1;
           this->output = this->mem;
            return this->mem;			
        }
        else
        {
            return -1;
        }
    }					
    /* This is checking if the input is 1. If the input is 1, then the output is the same as the
    memory. */
    else if(in1 == 1)
    {		
        if(memory2 == 0)
        {	
            this->mem = 1;
            this->output = this->mem;
            return this->mem;
        }
        else if(memory2 == 1) 
        {
            this->mem = 0;
            this->output = this->mem;
            return this->mem;			
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

Decoder::Decoder()
{}

/**
 * A constructor for the Decoder class. It takes in the name of the gate, the name of the first input,
 * and the name of the second input.
 * 
 * @param name The name of the gate.
 * @param in1 the input to the decoder
 * @param in2 The second input to the gate.
 */
Decoder::Decoder(string name, string in1, string in2) : Gate(name,in1,in2)
{}

/**
 * If the input is 0,0, then output1(d1) is 1, if the input is 0,1, then output2(d2) is 1, if the input is 1,0,
 * then output3(d3) is 1, and if the input is 1,1, then output4(d4) is 1
 * 
 * @return The output of the decoder.
 */
int Decoder::eval()
{

    int in1 = this->in1->eval();

    int in2 = this->in2->eval();
    
    if(in1 == 0 && in2 == 0)
    {
        this->output1->output = 1;
        return this->output1->output;
    }
    else if(in1 == 0 && in2 == 1)
    {
        this->output2->output = 1;
        return this->output2->output;
    }
    else if(in1 == 1 && in2 == 0)
    {
        this->output3->output = 1;
        return this->output3->output;
    }
    else if(in1 == 1 && in2 == 1)
    {
        this->output4->output = 1;
        return this->output4->output;
    }
    return -1;
}
