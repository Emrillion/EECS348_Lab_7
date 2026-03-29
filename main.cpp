#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix {
private:
  int data[SIZE][SIZE];  // 2D array for matrix data (using int for simplicity)

public:
  // 1. Read values from stdin into a matrix
  int readFromStdin() {
    // get the filepath
    string filePath = "matrix-data.txt";

    // Open the file using ifstream
    ifstream file(filePath);

    // confirm file opening
    if (!file.is_open()) {
        // print error message and return
        cerr << "Failed to open file: " << filePath << endl;

        return 1;
    }

    // Read values from the file into the matrix
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        file >> data[i][j];
      }
    }
    
    file.close();

    return 0;
  }

  // 2. Display a matrix
  void display() const{
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        result.data[i][j] = data[i][j] + other.data[i][j];
      }
    }
    return result;
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        result.data[i][j] = 0; // Initialize the result 
        for (int k = 0; k < SIZE; ++k) {
          result.data[i][j] += data[i][k] * other.data[k][j];
        }
      }
    }
    return result;
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const {
    int sum = 0;
    for (int i = 0; i < SIZE; ++i) {
      sum += data[i][i]; // Add the main diagonal element
    }
    return sum;
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) {
    for (int j = 0; j < SIZE; ++j) {
      int temp = data[row1][j];
      data[row1][j] = data[row2][j];
      data[row2][j] = temp;
    }
  }
};

int main() {
  // Get and display Matrix 1
  Matrix mat1;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  // Get and display Matrix 2
  Matrix mat2;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  // Do matrix addition
  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  // Do matrix multiplication
  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
