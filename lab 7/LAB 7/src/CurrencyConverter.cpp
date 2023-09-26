#include "CurrencyConverter.h"

CurrencyConverter::CurrencyConverter():exchangeRate(1.0), amountinEUR(0.0), amountinUSD(0.0)
{
    //ctor
}

CurrencyConverter::CurrencyConverter(double rate, double USD):exchangeRate(rate), amountinEUR(0.0), amountinUSD(USD)
{
    double d= USD*(rate);
    amountinEUR=d;
}

CurrencyConverter::CurrencyConverter(double rate, double eurAmount, bool isEUR): exchangeRate(rate)
{
    //dtor
    if(isEUR){
        amountinEUR= eurAmount;
        double d=eurAmount*(rate);
        amountinUSD=d;
    }
    else{
        amountinUSD= eurAmount;
        double d=eurAmount/(rate);
        amountinEUR=d;
    }
}

CurrencyConverter::~CurrencyConverter()
{
    //ctor
}

void CurrencyConverter::showcurrency(){
    std::cout<<"USD is: "<<amountinUSD<<std::endl;
    std::cout<<"EUR is: "<<amountinEUR<<std::endl;
}

CurrencyConverter::operator double() const{
    double d= amountinUSD;
    return d;
}
