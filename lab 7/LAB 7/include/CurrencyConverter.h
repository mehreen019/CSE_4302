#ifndef CURRENCYCONVERTER_H
#define CURRENCYCONVERTER_H
#include <iostream>

class CurrencyConverter
{
    public:
        CurrencyConverter();
        CurrencyConverter(double rate, double USD);
        CurrencyConverter(double rate, double eurAmount, bool isEUR);
        ~CurrencyConverter();
        void showcurrency();
        operator double() const;

    private:
        double exchangeRate;
        double amountinUSD;
        double amountinEUR;
};

#endif // CURRENCYCONVERTER_H
