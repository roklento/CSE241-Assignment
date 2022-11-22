#include <iostream>
#include <vector>
#ifndef SparseMatrix_h
#define SparseMatrix_h

class SparseMatrix
{/**
 * The constructor creates an empty sparse vector. The overloaded operators add, subtract, multiplication and negate a
 * sparse matrix. The overloaded assignment operator copies a sparse matrix. The overloaded output
 * operator prints a sparse matrix. The trasnpose function is doing the transpose of the matrix. The check_errors 
 * function takes filename and returns int
 * 
 * 
 * @param  
 * 
 * @return Nothing is being returned.
 */
public:
    SparseMatrix(){};
    SparseMatrix(const std::string);
    SparseMatrix operator +(const SparseMatrix &)const;
    SparseMatrix operator -(const SparseMatrix &)const;
    SparseMatrix operator -();
    SparseMatrix operator =(const SparseMatrix &){return *this;};
    SparseMatrix operator *(const SparseMatrix &)const;
    friend std::ostream& operator <<(std::ostream &, SparseMatrix&);
    SparseMatrix& transpose();
    int check_errors(const std::ifstream*);

/* A private member of the class. */
private:
    int row_index;
    int index;
    double data;
    std::vector <std::vector<double>> vec;
};

#endif