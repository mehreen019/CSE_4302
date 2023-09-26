#include "CurrencyDollar.h"

CurrencyDollar::CurrencyDollar():dollar(0.0), cent(0.0)
{
    //ctor
}

CurrencyDollar::CurrencyDollar(double dollar, double cent):dollar(dollar), cent(cent)
{
    //ctor
}

CurrencyDollar::~CurrencyDollar()
{
    //dtor
}

CurrencyDollar::operator CurrencyBDT() const{
    double p= (cent/100)*109.89;
    double d= dollar*109.89;
    double t=p+d;
    double taka,poi;

    taka=floor(t);
    poi=t-taka;

    return CurrencyBDT(taka, floor(poi*100));
}
