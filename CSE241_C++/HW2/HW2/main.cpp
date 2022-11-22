#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "SparseVector.h"
#include "SparseMatrix.h"

using namespace std;

int main()
{
    /* This is opening a file called output.txt and truncating it. */
    ofstream outfile;
    outfile.open("output.txt", ios::out | ios::trunc);
    
    /* This is creating two vectors from the files input.txt and input2.txt. */
    SparseVector a1("input.txt");
    SparseVector a2("input2.txt");

    /* This is printing the vectors to the output file. */
    outfile << "vector input a1:" << endl << a1 << endl << endl;
    outfile << "vector input a2:" << endl << a2 << endl << endl;

    /* This is adding the two vectors together and storing the result in a3. */
    SparseVector a3 = a1 + a2;
    outfile << "vector output a1 + a2:" << endl << a3 << endl << endl;

    /* This is creating a new vector called a4 and setting it equal to the result of a1 - a2. */
    SparseVector a4 = a1 - a2;
    outfile <<  "vector output a1 - a2:" << endl << a4 << endl << endl;

    /* This is printing the dot product of a1 and a2 to the output file. */
    outfile << "dot product a1,a2: " << dot(a1,a2) << endl << endl;

    /* This is negating the vector a1. */
    -a1;
    outfile << "vector output -a1:"<< endl << a1 << endl << endl;
    


    /* This is creating two matrices from the files m1.txt and m2.txt. */
    SparseMatrix m1("m1.txt");
    SparseMatrix m2("m2.txt");

    /* This is printing the matrix m1 and m2 to the output file. */
    outfile << "matrix input m1:" << endl << m1 << endl;
    outfile << "matrix input m2:" << endl << m2 << endl;

    /* This is adding the two matrices m1 and m2 together and storing the result in m3. */
    SparseMatrix m3 = m1 + m2;
    outfile << "matrix output m1 + m2:"<< endl << m3 << endl;

    /* This is creating a new matrix called m4 and setting it equal to the result of m1 - m2. */
    SparseMatrix m4 = m1 - m2;
    outfile << "matrix output m1 - m2:"<< endl << m4 << endl;

    /* This is creating a new matrix called m5 and setting it equal to the result of m1 * m2. */
    SparseMatrix m5 = m1 * m2;
    outfile << "matrix output m1 * m2:"<< endl << m5 << endl;

    /* This is negating the matrix m1. */
    -m1;
    outfile << "matrix output -m1:"<< endl << m1 << endl;

    /* This is printing the transpose of m1 to the output file. */
    outfile  << "trasnpose m1:"<< endl <<m1.transpose() << endl;
    
    return 0;
}
