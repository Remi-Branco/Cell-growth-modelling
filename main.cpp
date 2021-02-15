#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include "functions.h"
#include"Cellule.h"


using namespace std;


int main()
{

    string const nomFichier("Results.csv");

    ofstream monFichier(nomFichier.c_str());
    if(monFichier)
    {
        monFichier << "cell#,t,Cell size,cdk,\n"<<endl;
    }

    srand(time(0)); //initialize random seed


    int nombreCellules = 100;
    double moyenne(0),standardDeviation(0);

    for (int cell = 1; cell<=nombreCellules ;cell++){

    Cellule cellule;

    double sizeCell,cdkCell;

    if(monFichier)
    {
        int t =0;
        do
        {
            cellule.grow();
            sizeCell = cellule.getSize();
            cdkCell = cellule.getCDK();
            //if (t == 119){
            monFichier << cell << "," << t << "," << sizeCell <<"," << cdkCell << endl;
            //}
            t++;
        }
        while (t<120);

    }

    }
    return 0;
}
