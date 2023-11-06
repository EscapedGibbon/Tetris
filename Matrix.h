//
// Created by Maxim on 19.09.23.
//
#include <iostream>
#ifndef TETRIS_MATRIX_H
#define TETRIS_MATRIX_H


class Matrix {
private:

   int width;
   int height;
   char* data;
   struct Proxy{
      char* ptr;
      Proxy(char* matrixPtr):ptr(matrixPtr){};
      char& operator[](const int& column){
         return *(ptr+column);
      }
   };
public:
   char getValue(int column, int row);
   void setValue(int column, int row,char newValue);
   void setValueByIndex(int index,char newValue);
   Matrix(const int& w = 12,const int& h = 22);
   Matrix(const Matrix& matrix);
   Matrix(Matrix&& matrix);
   ~Matrix();
   void operator = (Matrix& matrix);
   Proxy operator[](const int& row);
   void operator=(Matrix&& matrix);
   void swap(Matrix& otherMatrix);

};



#endif //TETRIS_MATRIX_H
