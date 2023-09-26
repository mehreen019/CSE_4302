#include "CurrencyBDT.h"

CurrencyBDT::CurrencyBDT():taka(0.0), poisha(0.0)
{
    //ctor
}

CurrencyBDT::CurrencyBDT(double taka, double poisha):taka(taka), poisha(poisha)
{
    //ctor
}

CurrencyBDT::~CurrencyBDT()
{
    //dtor
}

void CurrencyBDT::display(){
    std::cout<<"taka is: "<<taka<<" poisha is: "<<poisha<<std::endl;
}
