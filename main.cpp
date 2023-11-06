#include <iostream>
#include <string>
#include "Matrix.h"


int main() {
   int width = 10;
   int height = 10;
   Matrix matrix(width,height);
   Matrix matrix2(matrix);
   Matrix matrix3(std::move(matrix));
   Matrix matrix5(width,height);
   matrix5 = matrix2;
   Matrix matrix6(width,height);
   matrix6 = std::move(matrix3);
std::string s1 = "Hello";
std::string s2 = "world";
std::cout << s1;
s1.swap(s2);
std::cout << s1;
   return 0;
}

