#include "circuit.h"

using namespace std;
/**
 * It creates a new circuit object and calls the result() function
 */
circuit::circuit()
{
    result();
}

/**
 * The function reads the circuit.txt file and creates the gates and assigns the inputs and outputs of
 * the gates
 */
void circuit::read()
{
    string type_name;
    string gate_name;
    
    ifstream fp1;
    int i;
    fp1.open("circuit.txt", ios::in);
    while(!fp1.eof())
    {	
        fp1 >> type_name;
		if(type_name == "INPUT")/* if type_name is "INPUT"*/
        {	
			/* Reading the input file and creating the input gates. */
            do 
            {	
                fp1 >> gate_name;
                Input* Input = new ::Input(gate_name,"","");
                gates.push_back(Input);
                counter++;
			}while (fp1.get() == ' ');
		}
        else if(type_name == "OUTPUT")/* if type_name is "OUTPUT"*/
        {
            /* Reading the output gates and creating the output gates. */
            do 
            {	
                fp1 >> gate_name;
                Output* Output = new ::Output(gate_name,"","");
                gates.push_back(Output);
			}while (fp1.get() == ' ');
        }
		else if(type_name == "AND")/* if type_name is "AND"*/
        {	
            /* Reading the circuit.txt file and creating the gates and assigning the inputs and outputs
            of the gates. */
            string temp_name,temp_input1,temp_input2;
            fp1 >>  temp_name>>temp_input1>>temp_input2;
            And *And = new ::And(temp_name,temp_input1,temp_input2);
            gates.push_back(And);
        
            /* Assigning the address of the input gates to the input pointers of the gate. */
            i = gates.size();
			for(int j = 0; j < i; j++)
            {	
				if(gates[i-1]->input1 == gates[j]->name)
                {
					gates[i-1]->in1 = gates[j];
				}
				if(gates[i-1]->input2 == gates[j]->name)
                {
					gates[i-1]->in2 = gates[j];
				}
			}
		}
		else if(type_name == "OR")/* if type_name is "OR"*/
        {	
			/* Reading the circuit.txt file and creating the gates and assigning the inputs and outputs of the
            gates. */
            string temp_name,temp_input1,temp_input2;

            fp1 >>  temp_name>>temp_input1>>temp_input2;
            Or* Or = new ::Or(temp_name,temp_input1,temp_input2);
            gates.push_back(Or);

            /* Assigning the address of the input gates to the input pointers of the gate. */
            i = gates.size();
			for(int j = 0; j < i; j++)
            {	
				if(gates[i-1]->input1 == gates[j]->name)
                {
					gates[i-1]->in1 = gates[j];
				}
				if(gates[i-1]->input2 == gates[j]->name)
                {
					gates[i-1]->in2 = gates[j];
				}
			}
		}
		else if(type_name == "NOT")/* if type_name is "NOT"*/
        {	
			/* Reading the circuit.txt file and creating the gates and assigning the inputs and outputs of the
            gates. */
            string temp_name,temp_input1;

            fp1 >>  temp_name>>temp_input1;
            Not* Not = new ::Not(temp_name,temp_input1,"");
            gates.push_back(Not);

           /* Assigning the address of the input gates to the input pointers of the gate. */
            i = gates.size();
			for(int j = 0; j < i; j++)
            {	
				if(gates[i-1]->input1 == gates[j]->name)
                {
					gates[i-1]->in1 = gates[j];
				}
			}
		}
		else if(type_name == "FLIPFLOP")/* if type_name is "FLIPFLOP"*/
        {	
           
            /* Reading the circuit.txt file and creating the gates and assigning the inputs and outputs
            of the gates. */
            string temp_name,temp_input1;

            fp1 >>  temp_name >> temp_input1;
            Flipflop* Flipflop = new ::Flipflop(temp_name,temp_input1,"");
            gates.push_back(Flipflop);

            /* Assigning the address of the input gates to the input pointers of the gate. */
            i = gates.size();
			for(int j = 0; j < i; j++)
            {	
				if(gates[i-1]->input1 == gates[j]->name)
                {
					gates[i-1]->in1 = gates[j];
				}
			}

		}
        else if(type_name == "DECODER")
        {
            /* Reading the circuit.txt file and creating the gates and assigning the inputs and outputs
            of the gates. */
            string temp_d1,temp_d2,temp_d3,temp_d4,temp_input1,temp_input2;

            fp1 >> temp_d1 >> temp_d2 >> temp_d3 >> temp_d4 >> temp_input1 >> temp_input2;
            Decoder* Decoder = new ::Decoder("",temp_input1,temp_input2);
            gates.push_back(Decoder);

            /* Assigning the address of the input gates to the input pointers of the gate. */
            i = gates.size();
			for(int j = 0; j < i; j++)
            {	
				if(gates[i-1]->input1 == gates[j]->name)
                {
					gates[i-1]->in1 = gates[j];
				}
				if(gates[i-1]->input2 == gates[j]->name)
                {
					gates[i-1]->in2 = gates[j];
				}
			}
            /* Assigning the address of the output gates to the output pointers of the decoder. */
            ::Decoder* decod = (::Decoder *) gates[i-1];
            i = counter;
            decod->output1 = gates[i++];
            decod->output2 = gates[i++];
            decod->output3 = gates[i++];
            decod->output4 = gates[i++];
        }
	}
    fp1.close();
}

/**
 * It reads the input file and evaluates the circuit
 */
void circuit::result()
{
    int result;

    FILE *fp2 = fopen("input.txt","r");

    read();

    gates.erase(gates.begin()+gates.size()-1);

        /* Reading the input file and evaluating the circuit. */
        while(!feof(fp2))
        {	
            /* Reading the input file and assigning the input values to the input gates. */
            for(int i = 0; i < counter; i++)
            {	
                fscanf(fp2, "%d ", &gates[i]->output);	
            }
            /* Evaluating the circuit. */
            result = gates[gates.size()-1]->eval();
            /* Resetting the flag of the flipflop gates to 0. */
            for(int i = 0; i < gates.size(); i++)
            {
                if(typeid(*gates[i]) == typeid(::Flipflop))
                {
                    ::Flipflop* Flipflop = (::Flipflop*)gates[i];
                    Flipflop->flag = 0;
                }
            }
            /* Printing the output of the decoder. */
            cout << gates[counter]->output << " " << gates[counter+1]->output << " "<< gates[counter+2]->output << " " <<gates[counter+3]->output << endl;
            /* Resetting the output of the decoder to 0. */
            for(int i = counter; i < counter+4; i++)
            {   
                gates[i]->output = 0; 
            }
        }
    fclose(fp2);
}
