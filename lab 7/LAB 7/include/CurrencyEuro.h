#ifndef CURRENCYEURO_H
#define CURRENCYEURO_H
#include "CurrencyBDT.h"

class CurrencyEuro
{
    public:
        CurrencyEuro();
        CurrencyEuro(double euro, double cent);
        ~CurrencyEuro();
        operator CurrencyBDT() const;

    private:
        double euro;
        double cent;
};



#endif // CURRENCYEURO_H
