#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include"functions.h"
#include<string>
#include<math.h>



#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>



float stDev (const int data[],const int mean,const int arraySize);


float CIplus (const int mean,const int stDev, const int arraySize);

float CIminus (const int mean,const int stDev, const int arraySize);

float mean (const int data[],const int arraySize);

double rand_normal(double mean, double stddev);


#endif // FUNCTIONS_H_INCLUDED
