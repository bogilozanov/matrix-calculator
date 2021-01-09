/**
*  
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Bogdan Lozanov
* @idnumber 62592
* @compiler GCC
*
* <main file>
*
*/

#include <iostream>
#include <fstream>
using namespace std;

void chooseOperation(int &operationNumber);
void multiplyMatrixByScalar(int &rows, int &cols, int &scalar, double **matrix);
void multiplyMatrixByMatrix(int &rows, int &cols, int &secondRows, int &secondCols, double **matrix, double **secondMatrix);
void findTheDeterminant(int &rows, double **matrix);
void divideMatrixByScalar();
void findTheInverseMatrix();
void matrixTransposition();
void inputValueGreaterThanZero(int &number);
double **inputMatrix(int &rows, int &cols);
void printMatrix(double **matrix, int &rows, int &cols);
void inputValueBetween2and4(int &number);

int main()
{
  int operationNumber;
  fstream textFile("main_functions.txt", fstream::in);

  if (!textFile.is_open())
  {
    cout << "Could't open the text file";
    return 0;
  }
  cout << "Choose an operation you want to use!" << endl;
  cout << textFile.rdbuf();
  cout << "Operation: ";
  cin >> operationNumber;
  cout << endl;
  if (operationNumber > 6 || operationNumber < 0)
  {
    cout << "Not valid operation number!";
    return 0;
  }
  chooseOperation(operationNumber);
  textFile.close();
  return 0;
}

// Input matrix values
double **inputMatrix(int &rows, int &cols)
{
  double **matrix;
  double number;
  matrix = new double *[rows];

  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new double[cols];

    for (int j = 0; j < cols; j++)
    {
      cin >> number;
      matrix[i][j] = number;
    }
  }
  return matrix;
}

// Prints a matrix
void printMatrix(double **matrix, int &rows, int &cols)
{
  cout << endl;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

// Input numbers for cols and rows
void inputValueGreaterThanZero(int &number)
{
  cin >> number;
  while (number < 1)
  {
    cout << "Value must be one or greater!\nInput again: ";
    cin >> number;
    cout << endl;
  }
  cout << endl;
}

// Input number for determinat size
void inputValueBetween2and4(int &number)
{
  cin >> number;
  while (number < 2 || number > 4)
  {
    cout << "Value not in the range!\nInput again: ";
    cin >> number;
    cout << endl;
  }
  cout << endl;
}

void multiplyMatrixByScalar(int &rows, int &cols, int &scalar, double **matrix)
{
  cout << "Input scalar: ";
  cin >> scalar;
  cout << endl;
  cout << "Input matrix rows: ";
  inputValueGreaterThanZero(rows);
  cout << "Input matrix columns: ";
  inputValueGreaterThanZero(cols);
  cout << "Input matrix values:\n";
  matrix = inputMatrix(rows, cols);

  // multiplication logic
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      matrix[i][j] *= scalar;
    }
  }

  printMatrix(matrix, rows, cols);

  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void multiplyMatrixByMatrix(int &rows, int &cols, int &secondRows, int &secondCols, double **matrix, double **secondMatrix)
{
  double **multiplicationProduct;

  cout << "Input first matrix rows: ";
  inputValueGreaterThanZero(rows);
  cout << "Input first matrix columns and second matrix rows: ";
  inputValueGreaterThanZero(cols);
  secondRows = cols;
  cout << "Input second matrix columns: ";
  inputValueGreaterThanZero(secondCols);
  cout << "Input first matrix values:\n";
  matrix = inputMatrix(rows, cols);
  cout << "Input second matrix values:\n";
  secondMatrix = inputMatrix(secondRows, secondCols);

  // initializing the multiplication product matrix
  multiplicationProduct = new double *[rows];
  for (int i = 0; i < rows; i++)
  {
    multiplicationProduct[i] = new double[secondCols];

    for (int j = 0; j < secondCols; j++)
    {
      matrix[i][j] = 0;
    }
  }

  // multiplication logic
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < secondCols; j++)
    {
      for (int k = 0; k < cols; k++)
      {
        multiplicationProduct[i][j] += matrix[i][k] * secondMatrix[k][j];
      }
    }
  }

  printMatrix(multiplicationProduct, rows, secondCols);

  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
    delete[] multiplicationProduct[i];
  }
  delete[] matrix;
  delete[] multiplicationProduct;

  for (int i = 0; i < secondRows; i++)
  {
    delete[] secondMatrix[i];
  }
  delete[] secondMatrix;
}

void findTheDeterminant(int &rows, double **matrix)
{
  cout << "Input matrix size. Value can be 2, 3 or 4 ";
  inputValueBetween2and4(rows);
  cout << "Input matrix values:\n";
  matrix = inputMatrix(rows, rows);

  // Finding determinant logic. TODO implement smarter if there is time.
  if (rows == 2)
  {
    cout << matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
  }
  else if (rows == 3)
  {
    cout << matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
  }
  else if (rows == 4)
  {
    cout << matrix[0][0] * matrix[1][1] * matrix[2][2] * matrix[3][3] + matrix[0][1] * matrix[1][2] * matrix[2][3] * matrix[3][0] + matrix[0][2] * matrix[1][3] * matrix[2][0] * matrix[3][1] + matrix[0][3] * matrix[1][0] * matrix[2][1] * matrix[3][2] - matrix[0][3] * matrix[1][2] * matrix[2][1] * matrix[3][0] - matrix[0][2] * matrix[1][1] * matrix[2][0] * matrix[3][3] - matrix[0][1] * matrix[1][0] * matrix[2][3] * matrix[3][2] - matrix[0][0] * matrix[1][3] * matrix[2][2] * matrix[3][1];
  }

  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void divideMatrixByScalar()
{
}

void findTheInverseMatrix()
{
}

void matrixTransposition()
{
}

void chooseOperation(int &operationNumber)
{
  int rows, cols, scalar, secondRows, secondCols;
  double **matrix;
  double **secondMatrix;

  if (operationNumber == 1)
  {
    multiplyMatrixByScalar(rows, cols, scalar, matrix);
  }
  else if (operationNumber == 2)
  {
    multiplyMatrixByMatrix(rows, cols, secondRows, secondCols, matrix, secondMatrix);
  }
  else if (operationNumber == 3)
  {
    findTheDeterminant(rows, matrix);
  }
  else if (operationNumber == 4)
  {
    divideMatrixByScalar();
  }
  else if (operationNumber == 5)
  {
    findTheInverseMatrix();
  }
  else if (operationNumber == 6)
  {
    matrixTransposition();
  }
}
