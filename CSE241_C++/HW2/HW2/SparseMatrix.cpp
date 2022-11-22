#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "SparseMatrix.h"

const int VecMaxSize = 100;

/**
 * Reads a file and stores the data in a vector of vectors
 * 
 * @param filename the name of the file that contains the matrix
 */
SparseMatrix::SparseMatrix(const std::string filename)
{
    /* Storing the data in a string. */
    /* Storing the line in a string. */
    /* Storing the index in a string. */
    std::string line;
    std::string temp_index;
    std::string temp_data;
    /* Opening the file and storing the file stream in a variable called f. */
    std::ifstream f (filename);
    
    /* It creates a vector of vectors. */
    for(int i = 0; i < VecMaxSize; i++)
    {
        vec.push_back(std::vector<double>());
        /* This is creating a vector of zeros. */
        for(int j = 0; j < VecMaxSize; j++)
        {
            vec[i].push_back(0);
        }
    }

    /* Checking if the file is open. If it is open, it will read the file line by line. */
    if(f.is_open())
    {
        while(1)
        {
            std::getline(f, line);
            /* This is checking if the file is empty or if it has failed. If it is empty or has failed,
            it will break the loop. */
            if (SparseMatrix::check_errors(&f))
            {
                break;
            }
            /* This is converting the first character of the line to an integer. */
            row_index = (int)line[0];
            row_index -= 48;

            /* This is checking the length of the line. */
            int size = line.length();

            /* A for loop that will read the file line by line. */
            for(int j = 0, i = 2; i < size; i++)
            {
                /* Reading the line and storing the index in a string. */
                while(line[i] != ':')
                {
                    /* This is checking if the line is empty. If it is empty, it will break the loop. */
                    if(i >= size)
                        break;
                    /* Adding the character to the string temp_index. */
                    temp_index += line[i];
                    i++;
                    j++;
                }
                i++;
                j = 0;
                while(line[i] != ' ')
                {
                    if(i >= size)
                        break;
                   /* Adding the character to the string temp_data. */
                    temp_data += line[i];
                    i++;
                    j++;
                }
                
                /* Storing the index and the data in a string and then converting it to an integer and
                a double. */
                index = stoi(temp_index);
                data = stod(temp_data);
              
                this->vec[row_index][index] = data;
                
                /* Clearing the string temp_data and temp_index. */
                temp_data = {};
                temp_index = {};
                j = 0;
            } 
        } 
    }
}
/**
 * This function adds two sparse matrices together
 * 
 * @param vec1 The vector to be added to the current vector.
 * 
 * @return The sum of the two vectors.
 */
SparseMatrix SparseMatrix::operator+ (const SparseMatrix &vec1)const
{
    /* Creating a vector of vectors. */
    SparseMatrix temp_vec;

    for(int i = 0; i < VecMaxSize; i++)
    {
        temp_vec.vec.push_back(std::vector<double>());
        for(int j = 0; j < VecMaxSize; j++)
        {
            temp_vec.vec[i].push_back(0);
        }
    }

    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            /* This is checking if the two vectors are not equal to zero. If they are not equal to
            zero,
            it will add the two vectors together. */
            if ((this->vec[i][j] !=0) && (vec1.vec[i][j] != 0))
            {
                temp_vec.vec[i][j] = this->vec[i][j] + vec1.vec[i][j];
            }
            /* This is checking if the current vector is equal to zero and the other vector is not
            equal to zero.
                    If it is equal to zero and the other vector is not equal to zero, it will add
            the other vector
                    to the current vector. */
            else if ((this->vec[i][j] == 0) && (vec1.vec[i][j] != 0))
            {
                temp_vec.vec[i][j] = vec1.vec[i][j];
            }
           /* This is checking if the current vector is not equal to zero and the other vector is equal
           to zero.
                   If it is not equal to zero and the other vector is equal to zero, it will add the
           current vector
                   to the other vector. */
            else if((this->vec[i][j] != 0) && (vec1.vec[i][j] == 0))
            {
                temp_vec.vec[i][j] = this->vec[i][j];
            }
        }
    }
    return temp_vec;
}
/**
 * This function subtracts the vector vec1 from the vector vec
 * 
 * @param vec1 The vector you want to subtract from this vector.
 * 
 * @return The result of the subtraction of the two vectors.
 */
SparseMatrix SparseMatrix::operator- (const SparseMatrix &vec1)const
{
    /* Creating a vector of vectors. */
    SparseMatrix temp_vec;

    for(int i = 0; i < VecMaxSize; i++)
    {
        temp_vec.vec.push_back(std::vector<double>());
        for(int j = 0; j < VecMaxSize; j++)
        {
            temp_vec.vec[i].push_back(0);
        }
    }

    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            /* This is checking if the current vector is not equal to zero and the other vector is not
            equal to zero.
                    If it is not equal to zero and the other vector is not equal to zero, it will
            subtract the other vector
                    from the current vector. */
            if ((this->vec[i][j] !=0) && (vec1.vec[i][j] != 0))
            {
                temp_vec.vec[i][j] = this->vec[i][j] - vec1.vec[i][j];
            }
            /* This is checking if the current vector is equal to zero and the other vector is not
            equal to zero.
                    If it is equal to zero and the other vector is not equal to zero, it will add
            the other vector
                    to the current vector. */
            else if ((this->vec[i][j] == 0) && (vec1.vec[i][j] != 0))
            {
                temp_vec.vec[i][j] = vec1.vec[i][j];
            }
            /* This is checking if the current vector is not equal to zero and the other vector is
            equal to zero.
                    If it is not equal to zero and the other vector is equal to zero, it will add
            the current vector
                    to the other vector. */
            else if((this->vec[i][j] != 0) && (vec1.vec[i][j] == 0))
            {
                temp_vec.vec[i][j] = this->vec[i][j];
            }
        }
    }
    return temp_vec;

}

/**
 * This function multiplies every element in the matrix by -1
 * 
 * @return The object itself.
 */
SparseMatrix SparseMatrix::operator -()
{
    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            this->vec[i][j] *= -1;
        }
    }
    return *this;
}

/**
 * If the file is empty, the function returns 0. If the file is not empty, but has failed, it returns
 * 1. If the file has an error, it returns 1
 * 
 * @param f the file stream
 * 
 * @return a value of type int.
 */
int SparseMatrix::check_errors(const std::ifstream* f)
{
    int stop = 0;
    /* This is checking if the file is empty. If it is empty, it will break the loop. */
    if (f->eof())
    {
        stop = 0;
    }
    /* This is checking if the file has failed. If it has failed, it will break the loop. */
    if (f->fail())
    {
        stop = 1;
    }
    /* This is checking if the file has failed. If it has failed, it will break the loop. */
    if (f->bad())
    {
        stop = 1;
    }
    return stop;
}

/**
 * This function multiplies two sparse matrices together
 * 
 * @param vec1 The first vector
 * 
 * @return The product of the two vectors.
 */
SparseMatrix SparseMatrix::operator *(const SparseMatrix &vec1)const
{
    /* Creating a vector of vectors. */
    SparseMatrix temp_vec;

    for(int i = 0; i < VecMaxSize; i++)
    {
        temp_vec.vec.push_back(std::vector<double>());
        for(int j = 0; j < VecMaxSize; j++)
        {
            temp_vec.vec[i].push_back(0);
        }
    }

    /* This is doing the multiplication of the two vectors. */
    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            for(int k = 0; k < VecMaxSize; k++)
            {
                temp_vec.vec[i][j] += this->vec[i][k] * vec1.vec[k][j];
            }
        }
    }
    return temp_vec;
}

std::ostream& operator <<(std::ostream &os, SparseMatrix &sparseM)
{
    int flag = 0;

    for(int i = 0; i < VecMaxSize; i++)
    {   
        for(int j = 0; j < VecMaxSize; j++)
        {
            
            /* This is checking if the value is not equal to zero. If it is not equal to zero, it will
                    print the value. */
            if(sparseM.vec[i][j] != 0)
            {
                /* This is checking if the flag is equal to zero. If it is equal to zero, it will print
                the row
                        index and set the flag to one. */
                if(flag == 0)
                {
                    os << i << " ";
                    flag = 1;
                }
                os << j <<  ":" << sparseM.vec[i][j] << " ";
            }
        }
        /* This is checking if the flag is equal to one. If it is equal to one, it will print a new
        line. */
        if(flag == 1)
        {
            os << std::endl;
        }
        flag = 0;
    }
    return os;
}
SparseMatrix& SparseMatrix::transpose()
{
   /* Creating a vector of vectors. */
    SparseMatrix temp_vec;

    for(int i = 0; i < VecMaxSize; i++)
    {
        temp_vec.vec.push_back(std::vector<double>());
        for(int j = 0; j < VecMaxSize; j++)
        {
            temp_vec.vec[i].push_back(0);
        }
    }
    
    /* This is doing the transpose of the matrix. */
    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            
            temp_vec.vec[j][i] = this->vec[i][j]; 
        }
    }
    for(int i = 0; i < VecMaxSize; i++)
    {
        for(int j = 0; j < VecMaxSize; j++)
        {
            
            this->vec[i][j] = temp_vec.vec[i][j]; 
        }
    }
    return *this;
}
