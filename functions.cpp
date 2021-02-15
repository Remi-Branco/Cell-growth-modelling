#include "functions.h"


using namespace std;


float stDev (const int data[],const int mean,const int arraySize)
{

    //cout<< "there are " <<arraySize<<" tirages.."<<endl;
    float sum = 0.0, standardDeviation = 0.0 ;
    for (int i =0; i< arraySize; i++)
    {
        standardDeviation += pow(data[i] - mean,2);
    }
    return sqrt(standardDeviation/arraySize);

}

float CIplus (const int mean,const int stDev, const int arraySize)
{

    //cout<< "there are " <<arraySize<<" tirages.."<<endl;
    float CI = 0.0 ;
    return mean + 2.576*stDev/sqrt(arraySize);

}
float CIminus (const int mean,const int stDev, const int arraySize)
{

    //cout<< "there are " <<arraySize<<" tirages.."<<endl;
    float CI = 0.0 ;
    return mean - 2.576*stDev/sqrt(arraySize);

}


float mean (const int data[],const int arraySize)
{
    //cout << "arraySize = "<<arraySize<<endl;

    int sum = 0;
    for (int i = 0 ; i< arraySize; i++)
    {
        sum+=data[i];
        //cout << "data[i]"<<" -> "<<data[i]<<endl;
    }

    return sum/arraySize;
}


//returns a pseudorandom number following normal distribution
double rand_normal(double mean, double stddev)
{
    //Box muller method
    static double n2 = 0.0;
    static int n2_cached = 0;
    if (!n2_cached)
    {
        double x, y, r;
        do
        {
            x = 2.0*rand()/RAND_MAX - 1;
            y = 2.0*rand()/RAND_MAX - 1;

            r = x*x + y*y;
        }
        while (r == 0.0 || r > 1.0);
        {
            double d = sqrt(-2.0*log(r)/r);
            double n1 = x*d;
            n2 = y*d;
            double result = n1*stddev + mean;
            n2_cached = 1;
            return result;
        }
    }
    else
    {
        n2_cached = 0;
        return n2*stddev + mean;
    }
}
