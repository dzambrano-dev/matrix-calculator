//matrix.h
//Zambrano, Daniel

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

class Matrix{
    public:
    //defalut constructor
    Matrix();

    //constructor with dimensions
    Matrix(int rows, int cols);

    //function to input values into matrix
    void input();

    //function to display the matrix in row-column format
    void display() const;

    //function to return the transpose of the matrix
    Matrix transpose() const;

    //overloader addition operator
    Matrix operator+(const Matrix& rhs) const;

    //overloader subtraction operator
    Matrix operator-(const Matrix& rhs) const;

    //overloader multoiplication operator
    Matrix operator*(const Matrix& rhs) const;

private:
    int rows, cols; //number if rows and columns
    std::vector<std::vector<double>> data; //2D vetcor to stor matrix elements
};
#endif //MATRIX_H