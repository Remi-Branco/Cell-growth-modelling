#include"Cellule.h"


using namespace std;

//constructeur
Cellule::Cellule()
{
    //m_size = rand_normal(5 , 0.5);//initialises the cell size with random number following normal distribution average = 10 stD = 1
    //m_thresholdSize = rand_normal(10 , 0.1) ; // max size reached before division
    m_size = 0.01*(100+(rand()%(400)));
    //m_thresholdSize = rand_normal(4,0.4);
    m_deltaT =1;
    m_growthRate = rand_normal(0.05 , 0.005);
    //m_growthRate = 0.05;
    m_thresholdCDK = rand_normal(5200.0,32.0);

    m_pCDK = 57 ; //different from supp table Jones 2017
    m_CDK = m_size*m_pCDK; // eq (3);
    m_divisionRatio = rand_normal(50 , 10);
    //m_divisionRatio = rand_normal(0.5 , 0.0737);// between 0 and 1 !! Different to paper

}

Cellule::Cellule(Cellule const& autreCellule)
{
    m_size *= (autreCellule.m_size*(m_divisionRatio/100)) ; //la cellule copiee fait le complement de la taille de la cellule mere
    m_growthRate = rand_normal(0.05 , 0.005); //on reinitialise random
    m_thresholdCDK = rand_normal(5200.0,32.0);//on reinitialise random
    m_pCDK = autreCellule.m_pCDK ;
    m_CDK = m_size*m_pCDK;
    m_divisionRatio = rand_normal(50 , 10);//on reinitialise random
    m_deltaT=autreCellule.m_deltaT;//on reinitialise random
}

void Cellule::grow()
{
    if(m_CDK < m_thresholdCDK )
    {
        m_size = m_size + m_size*m_growthRate*m_deltaT;
        m_CDK = m_CDK + m_size*m_pCDK*m_deltaT; // eq (3)
        //m_thresholdCDK /= m_size; // eq (4)
    }
    else
    {
        //cout << "division !"<<endl;
        //cout << " m_CDK "<<m_CDK<<"  m_thresholdCDK "<<m_thresholdCDK<<endl;
        divide();
    }
}

void Cellule::divide()
{
    //mother cell has her size and CDK activity reduced
    //cout<< "m_size before division = " << m_size ;
    m_size *= (100-m_divisionRatio)/100 ;
    //cout <<" m_size AFTER = "<< m_size<<endl;

    //cout<< " m_size AFTER = " <<m_size<<endl;
    //cout <<"m_CDK (before) = "<< m_CDK;
    m_CDK = m_size*m_pCDK ;//CDK activity ***DIFFERENT TO PAPER ?!
    //cout <<" m_CDK (AFTER) = "<< m_CDK<<endl;

}


//accesseurs
double Cellule::getSize() const
{
    return m_size;
}
double Cellule::getCDK() const
{
    return m_CDK;
}
