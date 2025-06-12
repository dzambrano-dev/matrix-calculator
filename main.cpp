//main.cpp
//Zambrano, Daniel

#include <iostream>
#include "Matrix.h"

void displayMenu();

int main(){
    int choice;
    
    do{
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice ==0){
            std::cout << "\nExiting Program.\n";
            break;
        }
        int rows1, cols1, rows2, cols2;

        //user seletcts dimensions for Matric A
        std::cout << "\nEnter rows and columns for Matrix A: ";
        std::cin >> rows1 >> cols1;
        std::cout << "Enter values for Matrix A: \n";
        Matrix A(rows1, cols1);
        A.input();

        Matrix B;
        if (choice ==1 || choice ==2 || choice ==3){
            //user can select dimensions for Matric B only if needed
            std::cout << "\nEnter rows and colums for Matrix B: ";
            std::cin >> rows2 >> cols2;
            B = Matrix(rows2, cols2);
            std::cout << "Enter values for Matrix B:\n";
            B.input();
        }
        switch (choice){
            case 1: //addition
            if (rows1 == rows2 && cols1 == cols2){
                Matrix result = A+B;
                std::cout << "\nSum of A+B:\n";
                result.display();
            } else {
                std::cout << "Error: Dimensions must match for addition.\n";
            }
            break;

            case 2: //subtarction
            if (rows1 == rows2 && cols1 == cols2){
                Matrix result = A-B;
                std::cout << "\nDifference of A-B:\n";
                result.display();
            } else {
                std::cout << "Error: Dimensions must match for subtraction.\n";
            }
            break;

        case 3: //multiplication
            if (cols1==rows2){
                Matrix result = A*B;
                std::cout << "\nProduct of A*B:\n";
                result.display();
            } else{
                std::cout << "Error: Columns of A must match rows of B.\n";
            }
            break;

        case 4: //transpose
        std::cout << "\nTranspose of Matrix A:\n";
        A.transpose().display();
        break;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
        std::cout << "\n";
    } while (true);
    return 0;
}
void displayMenu(){
    std::cout <<"       Matrix Calculator       \n";
    std::cout << "[1] Add Matrices\n";
    std::cout << "[2] Subtract Matrices\n";
    std::cout << "[3] Multiply Matrices\n";
    std::cout << "[4] Transpose Matrix A\n";
    std::cout << "[0] Exit\n";
}