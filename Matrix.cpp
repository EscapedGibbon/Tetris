//
// Created by Maxim on 19.09.23.
//

#include "Matrix.h"

Matrix::Matrix(const int& w ,const int& h):width(w),height(h),data(new char[width*height]) {
   std::cout<< "Create";
   memset(data,'.',width*height);

}
Matrix::Matrix(const Matrix& matrix):width(matrix.width), height(matrix.height),data(new char[height*width]) {
   std::cout<< "Copy";
   memcpy(data,matrix.data,height*width);
}
Matrix::Matrix(Matrix&& matrix):width(matrix.width), height(matrix.height),data(matrix.data) {
   std::cout<< "Move";
   matrix.width = 0;
   matrix.height = 0;
   matrix.data = nullptr;

}
Matrix::~Matrix() {
   delete[] this->data;
}


char Matrix::getValue(int column, int row) {
   int index = row*this->width+column;
   return *(data+index);
}

void Matrix::setValue(int column, int row,char newValue) {
   int index = row*this->width+column;
   *(data+index)=newValue;
}

Matrix::Proxy Matrix::operator[](const int& row){
   Proxy proxy((data+row*width));
   return proxy;
}

void Matrix::operator=(Matrix& matrix){
   Matrix tmp(matrix);
   std::cout << "Assign";
   swap(tmp);


}

void Matrix::swap(Matrix& otherMatrix){
   std::swap(this->data,otherMatrix.data);
   std::swap(this->width, otherMatrix.width);
   std::swap(this->height, otherMatrix.height);
}

void Matrix::operator=(Matrix&& matrix){
   std::cout << " Move&Assign";
   swap(matrix);

}


