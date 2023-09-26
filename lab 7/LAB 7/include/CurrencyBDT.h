#ifndef CURRENCYBDT_H
#define CURRENCYBDT_H
#include<iostream>
#include<math.h>

class CurrencyBDT
{
    public:
        CurrencyBDT();
        CurrencyBDT(double taka, double poisha);
        ~CurrencyBDT();
        void display();

    private:
        double taka;
        double poisha;
};

#endif // CURRENCYBDT_H
