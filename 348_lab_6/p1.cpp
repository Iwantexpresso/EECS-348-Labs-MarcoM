#include <iostream>
#include <fstream>

const int tempS = 10; // Temporary matrix max size

// Function to read a square matrix from the input file stream
void readMatrix(int matrix[tempS][tempS], int size, std::ifstream& input) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (input >> matrix[i][j]) {
                // Successfully read an integer from the input
            } else {
                std::cerr << "Error reading matrix element at position (" << i << "," << j << ")." << std::endl;
                // Error Code Exit
            }
        }
    }
}

//  matrix addition Function
void matrixAddition(int result[tempS][tempS], const int matrix1[tempS][tempS], const int matrix2[tempS][tempS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

//  matrix multiplication Function
void matrixMultiplication(int result[tempS][tempS], const int matrix1[tempS][tempS], const int matrix2[tempS][tempS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

//  matrix subtraction Function
void matrixSubtraction(int result[tempS][tempS], const int matrix1[tempS][tempS], const int matrix2[tempS][tempS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Matrix printing Function
void printMatrix(const int matrix[tempS][tempS], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1; // Error Code Exit
    }

    int matrixSize;
    if (!(inputFile >> matrixSize)) {
        std::cerr << "Error reading the matrix size from the input file." << std::endl;
        return 1; // Error Code Exit
    }

    int matA[tempS][tempS];
    int matB[tempS][tempS];

    // Read matA and matB from the input file
    readMatrix(matA, matrixSize, inputFile);
    readMatrix(matB, matrixSize, inputFile);

    // Declare matrices for storing results
    int resultAddition[tempS][tempS];
    int resultMultiplication[tempS][tempS];
    int resultSubtraction[tempS][tempS];

    // performs all operations
    matrixAddition(resultAddition, matA, matB, matrixSize);
    matrixMultiplication(resultMultiplication, matA, matB, matrixSize);
    matrixSubtraction(resultSubtraction, matA, matB, matrixSize);

    std::cout << "Matrix Addition Result:" << std::endl;
    printMatrix(resultAddition, matrixSize);

    std::cout << "Matrix Multiplication Result:" << std::endl;
    printMatrix(resultMultiplication, matrixSize);

    std::cout << "Matrix Subtraction Result:" << std::endl;
    printMatrix(resultSubtraction, matrixSize);

    inputFile.close(); 
    return 0;
}