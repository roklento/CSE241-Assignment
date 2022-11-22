#include <iostream>
#include <vector>
#ifndef SparseVector_h
#define SparseVector_h

class SparseVector
{
/**
 * The constructor creates an empty sparse vector. The overloaded operators add, subtract, and negate a
 * sparse vector. The overloaded assignment operator copies a sparse vector. The overloaded output
 * operator prints a sparse vector. The dot product function takes two sparse vectors and returns their
 * dot product
 * 
 * @param  
 * 
 * @return Nothing is being returned.
 */
public:
    SparseVector(){};
    SparseVector(const std::string );
    SparseVector operator +(const SparseVector &)const;
    SparseVector operator -(const SparseVector &)const;
    SparseVector operator -();
    SparseVector operator =(const SparseVector &){return *this;};
    friend std::ostream& operator <<(std::ostream &, SparseVector&);
    friend double dot(const SparseVector, const SparseVector);
/* A private member of the class. */
private:
    int index;
    double data;
    std::vector <double> vec;
};

#endif
