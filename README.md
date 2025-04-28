# Matrix
This code implements a Matrix class in C++ that supports basic matrix operations such as addition, subtraction, and multiplication. The class uses dynamic memory allocation for efficient storage and management of matrix elements. Below is a breakdown of the functionality:

Features of the Code
1. Matrix Initialization:
   a. Default constructor: Initializes an empty matrix.
   b. Parameterized constructor: Creates a matrix with specified dimensions and fills it with an initial value.
   c. Copy constructor: Creates a deep copy of another matrix.
   d. Assignment operator: Ensures deep copying during assignment to avoid shallow copy issues.

2. Memory Management:
   a. Dynamically allocates memory for the matrix using helper functions (allocateMemory and deallocateMemory).
   b. Ensures proper cleanup in the destructor to prevent memory leaks.

3. Matrix Operations:
   a. Addition (operator+): Adds two matrices of the same dimensions.
   b. Subtraction (operator-): Subtracts one matrix from another of the same dimensions.
   c. Multiplication (operator*): Multiplies two matrices, provided the number of columns in the first matrix matches the number of rows in the second.

4. I/O Handling:
   a. Overloaded << operator: Prints the matrix in a readable format.

5. Error Handling:
   a. Validates dimensions for matrix operations and displays an error message if the dimensions do not match.

Code Execution
1. Matrix Addition:
   * mat1 and mat2 are two matrices with dimensions 2x3 initialized with values 1 and 2, respectively.
   * Their addition results in mat3, which contains the sum of corresponding elements of mat1 and mat2.

2. Matrix Multiplication:
   * mat1 is multiplied with mat4 (a 3x2 matrix initialized with value 3).
   * The result is stored in mat5 with dimensions 2x2.
