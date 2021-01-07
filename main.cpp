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
void multiplyMatrixByScalar();
void multiplyMatrixByMatrix();
void findTheDeterminant();
void divideMatrixByScalar();
void findTheInverseMatrix();
void matrixTransposition();
void inputAgainIfLowerThanOne();


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
  cin >> operationNumber;
  if (operationNumber > 6 || operationNumber < 0)
  {
    cout << "Not valid operation number!";
    return 0;
  }
  chooseOperation(operationNumber);

  return 0;
}

void inputAgainIfLowerThanOne(int &number)
{
  cout << "Input must be one or greater!\nInput again: ";
  cin >> number;
  cout << endl;
}

void multiplyMatrixByScalar()
{
  int scalar, matrixRows, matrixCols;
  cout << "Input the scalar: ";
  cin >> scalar;
  cout << endl;
  cout << "Input the matrix rows: ";
  cin >> matrixRows;
  cout << endl;
  while (matrixRows < 1)
  {
    inputAgainIfLowerThanOne(matrixRows);
  }
  cout << "Input the matrix columns: ";
  cin >> matrixCols;
  cout << endl;
  while (matrixCols < 1)
  {
    inputAgainIfLowerThanOne(matrixCols);
  }
  
}

void multiplyMatrixByMatrix()
{
}

void findTheDeterminant()
{
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
  if (operationNumber == 1)
  {
    multiplyMatrixByScalar();
  }
  else if (operationNumber == 2)
  {
    multiplyMatrixByMatrix();
  }
  else if (operationNumber == 3)
  {
    findTheDeterminant();
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
