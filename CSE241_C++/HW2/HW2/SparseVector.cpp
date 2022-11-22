#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SparseVector.h"

const int VecMaxSize = 100;

/**
 * Reads in a file and stores the data in a vector
 * 
 * @param filename the name of the file to read from
 */
SparseVector::SparseVector(const std::string filename)
{
    char c;

    /* This is opening the file and storing the file stream in a variable. */
    std::ifstream cinfromfile;
    cinfromfile.open(filename);
    
    /* Initializing the vector to all zeros. */
    vec.assign(VecMaxSize,0);
    
    /* This is reading in the file and storing the data in the vector. */
    while(1)
    {
        cinfromfile >> index >> c >> data;
        if(cinfromfile.eof())
        {
            break;
        }
        vec.at(index) = data;
    }
}

/**
 * This function adds two sparse vectors together
 * 
 * @param vec1 The first vector to be added.
 * 
 * @return The sum of the two vectors.
 */
SparseVector SparseVector::operator+ (const SparseVector &vec1)const
{
    /* This is initializing the vector to all zeros. */
    SparseVector temp_vec;
    temp_vec.vec.assign(VecMaxSize,0);

    for(int i = 0; i < VecMaxSize; i++)
    {
        /* This is checking to see if the two vectors have a value at the same index. If they do, then
        the value is added together. */
        if ((this->vec.at(i) !=0) && (vec1.vec.at(i) != 0))
        {
            temp_vec.vec.at(i) = this->vec.at(i) + vec1.vec.at(i);
        }
        /* This is checking to see if the first vector has a value at the same index as the second
        vector. If it does, then the value is added to the second vector. */
        else if ((this->vec.at(i) == 0) && (vec1.vec.at(i) != 0))
        {
            temp_vec.vec.at(i) = vec1.vec.at(i);
        }
        /* This is checking to see if the first vector has a value at the same index as the second
                vector. If it does, then the value is added to the second vector. */
        else if((this->vec.at(i) != 0) && (vec1.vec.at(i) == 0))
        {
            temp_vec.vec.at(i) = this->vec.at(i);
        }
    }
    return temp_vec;
}
/**
 * This function subtracts the vector vec1 from the vector vec2 and returns the result in a new vector
 * 
 * @param vec1 The vector to subtract from this vector.
 * 
 * @return The vector that is the result of the subtraction of the two vectors.
 */
SparseVector SparseVector::operator -(const SparseVector &vec1)const
{
    /* This is initializing the vector to all zeros. */
    SparseVector temp_vec;
    temp_vec.vec.assign(VecMaxSize,0);

    for(int i = 0; i < VecMaxSize; i++)
    {
       /* This is checking to see if the two vectors have a value at the same index. If they do, then
       the value is subtracted together. */
        if ((this->vec.at(i) !=0) && (vec1.vec.at(i) != 0))
        {
            temp_vec.vec.at(i) = this->vec.at(i) - vec1.vec.at(i);
        }
        /* This is checking to see if the first vector has a value at the same index as the second
        vector. If it does, then the value is added to the second vector. */
        else if ((this->vec.at(i) == 0) && (vec1.vec.at(i) != 0))
        {
            temp_vec.vec.at(i) = vec1.vec.at(i);
        }
        /* This is checking to see if the first vector has a value at the same index as the second
        vector. If it does, then the value is added to the second vector. */
        else if((this->vec.at(i) != 0) && (vec1.vec.at(i) == 0))
        {
            temp_vec.vec.at(i) = this->vec.at(i);
        }
    }
    return temp_vec;
}
/**
 * This function multiplies all the elements in the vector by -1
 * 
 * @return The vector itself.
 */
SparseVector SparseVector::operator -()
{
    for(int i = 0; i < VecMaxSize; i++)
    {
        this->vec.at(i) *= -1;
    }
    return *this;
}
std::ostream& operator <<(std::ostream &os, SparseVector &sparseM)
{
    for(int i = 0; i < VecMaxSize; i++)
    {
        if(sparseM.vec.at(i) != 0)
        {
            os << i << ":" << sparseM.vec.at(i) << " ";
        }
    }
    return os;
}
/**
 * Given two sparse vectors, return the dot product of the two vectors
 * 
 * @param v1 The first vector
 * @param v2 the vector to be multiplied with v1
 * 
 * @return The dot product of the two vectors.
 */
double dot(const SparseVector v1, const SparseVector v2)
{
    double dot_result = 0;
    for(int i = 0; i < VecMaxSize; i++)
    {
        dot_result += v1.vec.at(i)*v2.vec.at(i);
    }
    return dot_result;
}