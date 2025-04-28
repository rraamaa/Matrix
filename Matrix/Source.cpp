#include <iostream>

using namespace std;


class Matrix {
public:
    // Default constructor
    Matrix() : data(nullptr), rows(0), cols(0) {}

    // Parameterized constructor
    Matrix(int r, int c, int initialValue = 0) {
        allocateMemory(r, c);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = initialValue;
            }
        }
    }

    // Copy constructor
    Matrix(const Matrix& other) {
        allocateMemory(other.rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) { // Check for self-assignment
            deallocateMemory();
            allocateMemory(other.rows, other.cols);
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }

    // Destructor
    ~Matrix() {
        deallocateMemory();
    }

    // Addition of two matrices
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
           cerr << "Matrices dimensions do not match for addition" << endl;
            exit(1);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Subtraction of two matrices
    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrices dimensions do not match for subtraction" << endl;
            exit(1);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    // Multiplication of two matrices
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "Matrices dimensions do not match for multiplication" << endl;
            exit(1);
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Overloaded << operator to print the matrix
    friend ostream& operator<<(ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; ++i) {
            for (int j = 0; j < mat.cols; ++j) {
                os << mat.data[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

private:
    int** data;
    int rows, cols;

    // Helper function to allocate memory
    void allocateMemory(int r, int c) {
        rows = r;
        cols = c;
        data = new int* [rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Helper function to deallocate memory
    void deallocateMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
            rows = 0;
            cols = 0;
        }
    }
};

int main() {
    Matrix mat1(2, 3, 1);
    Matrix mat2(2, 3, 2);
    Matrix mat3 = mat1 + mat2;
    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 2:\n" << mat2;
    cout << "Matrix 3 (Addition):\n" << mat3;

    Matrix mat4(3, 2, 3);
    Matrix mat5 = mat1 * mat4;
    cout << "Matrix 1:\n" << mat1;
    cout << "Matrix 4:\n" << mat4;
    cout << "Matrix 5 (Multiplication):\n" << mat5;

    return 0;
}
