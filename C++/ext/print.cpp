//#include "header1.h"
#include <iostream>
#ifndef H_1
#define H_1
#include "globals.cpp"
#endif


extern int my_global;
void print() {
   std::cout << my_global << '\n';
}
