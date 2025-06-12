//matrix.cpp
//Zambrnao, daniel

#include "Matrix.h"
void Matrix::display() const {
    for (const auto& row : data) {
        for (double value : row) {
            std::cout << value << "\t";
        }
        std::cout << "\n";
    }
}
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);  // Flip dimensions

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }

    return result;
}

//defalut constructor
Matrix::Matrix() : rows(0), cols(0) {}

//constructor with dimensions, initilaizes all elemenst to 0
Matrix::Matrix(int r , int c) :rows(r), cols(c), data (r, std::vector<double>(c,0)){}


//function to input matrix values from the user
void Matrix::input(){
    for (int i=0 ; i< rows; ++i){
        std::cout << "Row" << i+1 << ":\n";
        for (int j = 0; j < cols; ++j){
            std::cout << "  Enter value for [" << i << "]["<<j <<"]: ";
            std::cin >> data[i][j];
        }
    }
}
//matrix addition
Matrix Matrix::operator+(const Matrix& rhs) const {
    Matrix result(rows,cols);
    
    for(int i=0; i < rows; ++i){
        for (int j=0; j<cols; ++j){
            result.data[i][j]=data [i][j] + rhs.data[i][j];
        }
    }
    return result;
}
//matrix subtraction
Matrix Matrix::operator-(const Matrix& rhs)const{
    Matrix result(rows,cols);

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; ++j){
            result.data[i][j]=data[i][j]-rhs.data[i][j];
        }
    }
    return result;
}

//matrix mulipulation
Matrix Matrix::operator*(const Matrix& rhs) const{
    Matrix result(rows,rhs.cols); //rows of A * cols of B

    for (int i=0; i< rows; ++i){
        for (int j =0; j<rhs.cols; ++j){
            for (int k=0; k<cols; ++k){
                result.data[i][j] += data[i][k] *rhs.data[k][j];
            }
        }
    }
    return result;
}