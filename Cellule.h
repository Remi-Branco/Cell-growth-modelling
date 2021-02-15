#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

#include"functions.h"
#include<string>
#include<math.h>

#include <stdlib.h>
#include <time.h>



class Cellule
{
public:
    //constructeur
    Cellule();
    Cellule(Cellule const& autreCellule); //constructeir de copie utilisé pour les divisions cellulaires

    double getSize() const;
    double getCDK() const;
    void grow();


private:

    //void growSize();
    //void growCDK();

    double m_size;//cell size
    //double m_thresholdSize;//for cell size
    double m_growthRate;//cell growth rate

    double m_CDK;//CDK activity
    double m_thresholdCDK;// for CDK activity
    double m_pCDK;//CDK production rate
    double m_deltaT;
    double m_divisionRatio;


    void divide();


};


#endif // CELLULE_H_INCLUDED
