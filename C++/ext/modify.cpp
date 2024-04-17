//#include "header1.h"

#ifndef H_1
#define H_1
#include "globals.cpp"
#endif

extern int my_global;
void modify() {
   my_global = 42;
}
