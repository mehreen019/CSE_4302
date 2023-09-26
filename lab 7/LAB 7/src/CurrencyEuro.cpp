#include "CurrencyEuro.h"

CurrencyEuro::CurrencyEuro():euro(0.0), cent(0.0)
{
    //ctor
}

CurrencyEuro::CurrencyEuro(double euro, double cent):euro(euro), cent(cent)
{
    //ctor
}

CurrencyEuro::~CurrencyEuro()
{
    //dtor
}

CurrencyEuro::operator CurrencyBDT() const{
    double p= (cent/100)*117.64;
    double d= euro*117.64;
    double t=p+d;
    double taka,poi;

    taka=floor(t);
    poi=t-taka;

    return CurrencyBDT(taka, floor(poi*100));
}

