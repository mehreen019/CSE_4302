#include "SavingsAccount.h"

int SavingsAccount::creation=0;
int SavingsAccount::destruction=0;
double SavingsAccount::annualInterestRate=0;

SavingsAccount::SavingsAccount()
{
    creation++;
}

SavingsAccount::SavingsAccount(double balance):savingsBalance(balance)
{
    creation++;
}

SavingsAccount::~SavingsAccount()
{
    destruction++;
}

double SavingsAccount::calculateMonthlyInterest()
{
    double interest= (savingsBalance*(annualInterestRate/12))/100;
    savingsBalance+=interest;

    return savingsBalance;
}
void SavingsAccount::modifyInterestRate(double newRate)
{
     annualInterestRate = newRate;
    // std::cout<<annualInterestRate<<std::endl;
}

void SavingsAccount::displayInfo()
{
    std::cout<<"CURRENT BALANCE IS: "<<savingsBalance<<std::endl;
}



