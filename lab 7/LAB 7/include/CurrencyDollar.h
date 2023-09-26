#ifndef CURRENCYDOLLAR_H
#define CURRENCYDOLLAR_H
#include "CurrencyBDT.h"

class CurrencyDollar
{
    public:
        CurrencyDollar();
        CurrencyDollar(double dollar, double cent);
        ~CurrencyDollar();
        operator CurrencyBDT() const;

    private:
        double dollar;
        double cent;
};

#endif // CURRENCYDOLLAR_H
